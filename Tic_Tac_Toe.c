#include <gtk/gtk.h>


struct button_press_arguments {
    GtkWidget *button;
    int *state_pointer;
};

void on_clicked_button(
                       GtkWidget *widget,
                       struct button_press_arguments *arguments
                      )
{
  enum state_definition {
      NO_CLICK,  // 0
      CLICK      // 1
  };

  char *str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                               "<b>%s</b>"
                               "</span>",
                               "X");

    int *state_pointer = arguments->state_pointer;
    *state_pointer = CLICK;
    GtkButton *button = (GtkButton*) arguments->button;
    GtkLabel *label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
    gtk_label_set_text(label, "X");
    gtk_label_set_markup (GTK_LABEL (label), str);
    g_free (str); // remember to free the string allocated by g_strdup_printf()
    gboolean sensitive= FALSE;
    gtk_widget_set_sensitive(widget, sensitive);

    // g_print("%d\n",CLICK);
}

int main(int argc, char* argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *buttons[3][3];
    GtkWidget *player_label;

    enum state_definition {
        NO_CLICK,  // 0
        CLICK      // 1
    };

    int game_state[3][3];
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            game_state[i][j] = NO_CLICK;
        }
    }

    gtk_init(&argc, &argv);

    // Get GUI from file
    builder = gtk_builder_new_from_file(
        "./Tic_Tac_Toe.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    buttons[0][0] = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_0"));
    buttons[0][1] = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_1"));
    buttons[0][2] = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_2"));
    buttons[1][0] = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_0"));
    buttons[1][1] = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_1"));
    buttons[1][2] = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_2"));
    buttons[2][0] = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_0"));
    buttons[2][1] = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_1"));
    buttons[2][2] = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_2"));
    player_label = GTK_WIDGET(gtk_builder_get_object(builder, "player_label"));

    struct button_press_arguments arguments[3][3] = {};

    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
            arguments[i][j].button = buttons[i][j];
            arguments[i][j].state_pointer = &game_state[i][j];
            g_signal_connect(
                             buttons[i][j],
                             "clicked",
                             G_CALLBACK(on_clicked_button),
                             &arguments[i][j]
                            );
       }
    }

    // Show and start main loop
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
