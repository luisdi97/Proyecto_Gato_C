#include <gtk/gtk.h>


struct button_press_arguments {
    GtkWidget *player_label;
    GtkWidget *button;
    char (*game_state_pointer)[3];
    char *current_player;
    int i;
    int j;
};

void on_clicked_button(
                       GtkWidget *widget,
                       struct button_press_arguments *arguments
                      )
{
  char (*game_state)[3];
  game_state = arguments->game_state_pointer;
  int i = arguments->i;
  int j = arguments->j;
  char *current_player = arguments->current_player;
  *(*(game_state + i) + j) = *current_player;

  int a;
  int b;

  // for (a = 0; a < 3; a++) {
  //     for (b = 0; b < 3; b++) {
  //         g_print("%c",*(*(game_state + a) + b));
  //     }
  //     g_print("\n");
  // }
  // g_print("\n");

  char state = *current_player;
  GtkLabel *player_label = (GtkLabel*) arguments->player_label;
  char *str;

  if (state == 'X') {
    // g_print("Current player is %c\n",*current_player);

    str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                                 "<b>%s</b>"
                                 "</span>",
                                 "X");

    gtk_label_set_text(player_label, "Jugador O");

    *current_player = 'O';

  } else if (state == 'O') {
    // g_print("Current player is %c\n",*current_player);

    str = g_strdup_printf ("<span font=\"90\" color=\"blue\">"
                                 "<b>%s</b>"
                                 "</span>",
                                 "O");

    gtk_label_set_text(player_label, "Jugador X");

    *current_player = 'X';

  }

    GtkButton *button = (GtkButton*) arguments->button;
    GtkLabel *button_label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
    gtk_label_set_markup (GTK_LABEL (button_label), str);
    g_free (str); // remember to free the string allocated by g_strdup_printf()
    gboolean sensitive = FALSE;
    gtk_widget_set_sensitive(widget, sensitive);

    // g_print("%d\n",CLICK);
}

int main(int argc, char* argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *buttons[3][3];
    GtkWidget *player_label;

    char game_state[3][3];
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            game_state[i][j] = ' ';
        }
    }

    char current_player = 'X';

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
            arguments[i][j].player_label = player_label;
            arguments[i][j].button = buttons[i][j];
            arguments[i][j].game_state_pointer = game_state;
            arguments[i][j].current_player = &current_player;
            arguments[i][j].i = i;
            arguments[i][j].j = j;
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
