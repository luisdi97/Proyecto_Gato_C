#include <gtk/gtk.h>


void on_clicked_button(GtkWidget *widget, gpointer button_data) {
  char *str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                             "<b>%s</b>"
                           "</span>",
                           "X");

    GtkButton *button = (GtkButton*) button_data;
    GtkLabel *label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
    gtk_label_set_text(label, "X");
    gtk_label_set_markup (GTK_LABEL (label), str);
    g_free (str); // remember to free the string allocated by g_strdup_printf()
    // g_print("X\n");
}

int main(int argc, char* argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *button_0_0;
    GtkWidget *button_0_1;
    GtkWidget *button_0_2;
    GtkWidget *button_1_0;
    GtkWidget *button_1_1;
    GtkWidget *button_1_2;
    GtkWidget *button_2_0;
    GtkWidget *button_2_1;
    GtkWidget *button_2_2;
    GtkWidget *player_label;

    gtk_init(&argc, &argv);

    // Get GUI from file
    builder = gtk_builder_new_from_file(
        "/home/luisdi/Desktop/Tic_Tac_Toe.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    button_0_0 = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_0"));
    button_0_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_1"));
    button_0_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_0_2"));
    button_1_0 = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_0"));
    button_1_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_1"));
    button_1_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_1_2"));
    button_2_0 = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_0"));
    button_2_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_1"));
    button_2_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_2_2"));
    player_label = GTK_WIDGET(gtk_builder_get_object(builder, "player_label"));

    g_signal_connect(
                     button_0_0,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_0_0
                    );

    g_signal_connect(
                     button_0_1,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_0_1
                    );

    g_signal_connect(
                     button_0_2,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_0_2
                    );

    g_signal_connect(
                     button_1_0,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_1_0
                    );

    g_signal_connect(
                     button_1_1,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_1_1
                    );

    g_signal_connect(
                     button_1_2,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_1_2
                    );

    g_signal_connect(
                     button_2_0,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_2_0
                    );

    g_signal_connect(
                     button_2_1,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_2_1
                    );

    g_signal_connect(
                     button_2_2,
                     "clicked",
                     G_CALLBACK(on_clicked_button),
                     button_2_2
                    );

    // Show and start main loop
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
