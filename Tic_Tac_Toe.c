#include <gtk/gtk.h>


char check_rows(char (*game_state)[3]){
    int a;
    int b;
    _Bool X_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    _Bool O_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    char current_box;

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            current_box = *(*(game_state + a) + b);

            if (current_box=='X') {
                X_wins[a][b] = 1;
            } else if (current_box=='O') {
                O_wins[a][b] = 1;
            }
        }
    }

    char output_char = ' ';

    if (X_wins[0][0]&&X_wins[0][1]&&X_wins[0][2] ||
        X_wins[1][0]&&X_wins[1][1]&&X_wins[1][2] ||
        X_wins[2][0]&&X_wins[2][1]&&X_wins[2][2]) {

        output_char = 'X';

    } else if (O_wins[0][0]&&O_wins[0][1]&&O_wins[0][2] ||
               O_wins[1][0]&&O_wins[1][1]&&O_wins[1][2] ||
               O_wins[2][0]&&O_wins[2][1]&&O_wins[2][2]) {

        output_char = 'O';
    }

    return output_char;
}

char check_columns(char (*game_state)[3]){
    int a;
    int b;
    _Bool X_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    _Bool O_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    char current_box;

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            current_box = *(*(game_state + b) + a);

            if (current_box=='X') {
                X_wins[b][a] = 1;
            } else if (current_box=='O') {
                O_wins[b][a] = 1;
            }
        }
    }

    char output_char = ' ';

    if (X_wins[0][0]&&X_wins[1][0]&&X_wins[2][0] ||
        X_wins[0][1]&&X_wins[1][1]&&X_wins[2][1] ||
        X_wins[0][2]&&X_wins[1][2]&&X_wins[2][2]) {

        output_char = 'X';

    } else if (O_wins[0][0]&&O_wins[1][1]&&O_wins[2][2] ||
               O_wins[0][1]&&O_wins[1][1]&&O_wins[2][1] ||
               O_wins[0][2]&&O_wins[1][1]&&O_wins[2][2]) {

        output_char = 'O';
    }

    return output_char;
}

char check_first_diagonal(char (*game_state)[3]){
    int a;
    _Bool X_wins[] = {0, 0, 0};
    _Bool O_wins[] = {0, 0, 0};
    char current_box;

    for (a = 0; a < 3; a++) {
        current_box = *(*(game_state + a) + a);

        if (current_box=='X') {
            X_wins[a] = 1;
        } else if (current_box=='O') {
            O_wins[a] = 1;
        }
    }

    char output_char = ' ';

    if (X_wins[0]&&X_wins[1]&&X_wins[2]) {
        output_char = 'X';
    } else if (O_wins[0]&&O_wins[1]&&O_wins[2]) {
        output_char = 'O';
    }

    return output_char;
}

char check_second_diagonal(char (*game_state)[3]){
    int a;
    _Bool X_wins[] = {0, 0, 0};
    _Bool O_wins[] = {0, 0, 0};
    char current_box;

    for (a = 0; a < 3; a++) {
        current_box = *(*(game_state + a) + 2-a);

        if (current_box=='X') {
            X_wins[a] = 1;
        } else if (current_box=='O') {
            O_wins[a] = 1;
        }
    }

    char output_char = ' ';

    if (X_wins[0]&&X_wins[1]&&X_wins[2]) {
        output_char = 'X';
    } else if (O_wins[0]&&O_wins[1]&&O_wins[2]) {
        output_char = 'O';
    }

    return output_char;
}

char check_three_in_line(char (*game_state)[3]){
    char checking[] = {check_rows(game_state),
                      check_columns(game_state),
                      check_first_diagonal(game_state),
                      check_second_diagonal(game_state)
                      };

    char output_char = ' ';

    int a;

    for (a = 0; a < 4; a++) {
        if (checking[a] != ' ') {
            output_char = checking[a];
        }
    }

    return output_char;
}

struct button_press_arguments {
    GtkWidget *player_label;
    GtkWidget *((*buttons)[3]);
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

  char winning_player = check_three_in_line(game_state);
  GtkWidget *((*buttons)[3]);
  buttons = arguments->buttons;
  GtkLabel *player_label = (GtkLabel*) arguments->player_label;



  if (winning_player != ' ') {
      // g_print("%c player wins\n",winning_player);

      char state = *current_player;
      char *str;

      if (state == 'X') {
        str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                                     "<b>%s</b>"
                                     "</span>",
                                     "X");
      } else if (state == 'O') {
        str = g_strdup_printf ("<span font=\"90\" color=\"blue\">"
                                     "<b>%s</b>"
                                     "</span>",
                                     "O");
      }

      GtkButton *button = (GtkButton*) *(*(buttons + i) + j);
      GtkLabel *button_label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
      gtk_label_set_markup (GTK_LABEL (button_label), str);
      g_free (str); // remember to free the string allocated by g_strdup_printf()

      // Allocates storage
      char *winning_string = (char*)malloc(14 * sizeof(char));

      sprintf(winning_string, "Jugador %c gana", winning_player);

      gtk_label_set_text(player_label, winning_string);

      free(winning_string);

      int a;
      int b;

      for (a = 0; a < 3; a++) {
          for (b = 0; b < 3; b++) {
              GtkWidget *button_widget = *(*(buttons + a) + b);
              gboolean sensitive = FALSE;
              gtk_widget_set_sensitive(button_widget, sensitive);
          }
      }
  }else{
      char state = *current_player;
      char *str;

      if (state == 'X') {
        str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                                     "<b>%s</b>"
                                     "</span>",
                                     "X");

        gtk_label_set_text(player_label, "Jugador O");

        *current_player = 'O';

      } else if (state == 'O') {
        str = g_strdup_printf ("<span font=\"90\" color=\"blue\">"
                                     "<b>%s</b>"
                                     "</span>",
                                     "O");

        gtk_label_set_text(player_label, "Jugador X");

        *current_player = 'X';

      }

        GtkButton *button = (GtkButton*) *(*(buttons + i) + j);
        GtkLabel *button_label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
        gtk_label_set_markup (GTK_LABEL (button_label), str);
        g_free (str); // remember to free the string allocated by g_strdup_printf()
        gboolean sensitive = FALSE;
        gtk_widget_set_sensitive(widget, sensitive);
  }
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
            arguments[i][j].buttons = buttons;
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
