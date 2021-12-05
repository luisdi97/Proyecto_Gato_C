/*
Author: Luis Diego Araya Campos

Tic Tac Toe

This program recreates the famous game Tic Tac Toe where two users in the same
computer play against each other sharing a mouse and clicking to position the
'X' or 'O' with the objective to get three of the same character in line.
*/

// The main library used is gtk to make the GUI
#include <gtk/gtk.h>

// The standard library is used for other minor resources
#include <stdlib.h>


char check_rows(char (*game_state)[3]){
    /*
    This function checks the rows in the 3x3 game array called game_state to
    determine whether three 'X' or 'O' are present. If there's a row with three
    'X' the char 'X' is returned, if there's a row with three 'O' the char 'O'
    is returned, if none of those conditions are met the char ' ' is returned.
    */
    int a;
    int b;
    // Two boolean arrays are initialized with every element as false
    _Bool X_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    _Bool O_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    char current_box;

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            // The current char to analyze is extracted from the game state
            current_box = *(*(game_state + a) + b);

            if (current_box=='X') {
                // If the character is 'X' the corresponding boolean is set
                // true
                X_wins[a][b] = 1;
            } else if (current_box=='O') {
                // If the character is 'O' the corresponding boolean is set
                // true
                O_wins[a][b] = 1;
            }
        }
    }

    // The default output is the char ' '
    char output_char = ' ';

    if (X_wins[0][0]&&X_wins[0][1]&&X_wins[0][2] ||
        X_wins[1][0]&&X_wins[1][1]&&X_wins[1][2] ||
        X_wins[2][0]&&X_wins[2][1]&&X_wins[2][2]) {

            // If any of the rows is filled with the character 'X' the output
            // is 'X'
            output_char = 'X';

    } else if (O_wins[0][0]&&O_wins[0][1]&&O_wins[0][2] ||
               O_wins[1][0]&&O_wins[1][1]&&O_wins[1][2] ||
               O_wins[2][0]&&O_wins[2][1]&&O_wins[2][2]) {

                 // If any of the rows is filled with the character 'O' the
                 // output is 'O'
                   output_char = 'O';
    }

    return output_char;
}

char check_columns(char (*game_state)[3]){
    /*
    This function checks the columns in the 3x3 game array called game_state to
    determine whether three 'X' or 'O' are present. If there's a column with
    three 'X' the char 'X' is returned, if there's a column with three 'O' the
    char 'O' is returned, if none of those conditions are met the char ' ' is
    returned.
    */
    int a;
    int b;
    // Two boolean arrays are initialized with every element as false
    _Bool X_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    _Bool O_wins[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    char current_box;

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            // The current char to analyze is extracted from the game state
            current_box = *(*(game_state + b) + a);

            if (current_box=='X') {
                // If the character is 'X' the corresponding boolean is set
                // true
                X_wins[b][a] = 1;
            } else if (current_box=='O') {
                // If the character is 'O' the corresponding boolean is set
                // true
                O_wins[b][a] = 1;
            }
        }
    }

    // The default output is the char ' '
    char output_char = ' ';

    if (X_wins[0][0]&&X_wins[1][0]&&X_wins[2][0] ||
        X_wins[0][1]&&X_wins[1][1]&&X_wins[2][1] ||
        X_wins[0][2]&&X_wins[1][2]&&X_wins[2][2]) {

            // If any of the columns is filled with the character 'X' the
            // output is 'X'
            output_char = 'X';

    } else if (O_wins[0][0]&&O_wins[1][0]&&O_wins[2][0] ||
               O_wins[0][1]&&O_wins[1][1]&&O_wins[2][1] ||
               O_wins[0][2]&&O_wins[1][2]&&O_wins[2][2]) {

                   // If any of the columns is filled with the character 'O'
                   // the output is 'O'
                   output_char = 'O';
    }

    return output_char;
}

char check_first_diagonal(char (*game_state)[3]){
    /*
    This function checks the diagonal starting on top left and ending on bottom
    right in the 3x3 game array called game_state to determine whether three
    'X' or 'O' are present. If the diagonal has three 'X' the char 'X' is
    returned, if the diagonal has three 'O' the char 'O' is returned, if none
    of those conditions are met the char ' ' is returned.
    */
    int a;
    // Two boolean arrays are initialized with every element as false
    _Bool X_wins[] = {0, 0, 0};
    _Bool O_wins[] = {0, 0, 0};
    char current_box;

    for (a = 0; a < 3; a++) {
        // The current char to analyze is extracted from the game state
        current_box = *(*(game_state + a) + a);

        if (current_box=='X') {
            // If the character is 'X' the corresponding boolean is set
            // true
            X_wins[a] = 1;
        } else if (current_box=='O') {
            // If the character is 'O' the corresponding boolean is set
            // true
            O_wins[a] = 1;
        }
    }

    // The default output is the char ' '
    char output_char = ' ';

    if (X_wins[0]&&X_wins[1]&&X_wins[2]) {
        // If the diagonal is filled with the character 'X' the output is 'X'
        output_char = 'X';
    } else if (O_wins[0]&&O_wins[1]&&O_wins[2]) {
        // If the diagonal is filled with the character 'O' the output is 'O'
        output_char = 'O';
    }

    return output_char;
}

char check_second_diagonal(char (*game_state)[3]){
    /*
    This function checks the diagonal starting on top right and ending on
    bottom left in the 3x3 game array called game_state to determine whether
    three 'X' or 'O' are present. If the diagonal has three 'X' the char 'X' is
    returned, if the diagonal has three 'O' the char 'O' is returned, if none
    of those conditions are met the char ' ' is returned.
    */
    int a;
    // Two boolean arrays are initialized with every element as false
    _Bool X_wins[] = {0, 0, 0};
    _Bool O_wins[] = {0, 0, 0};
    char current_box;

    for (a = 0; a < 3; a++) {
        // The current char to analyze is extracted from the game state
        current_box = *(*(game_state + a) + 2-a);

        if (current_box=='X') {
            // If the character is 'X' the corresponding boolean is set
            // true
            X_wins[a] = 1;
        } else if (current_box=='O') {
            // If the character is 'O' the corresponding boolean is set
            // true
            O_wins[a] = 1;
        }
    }

    // The default output is the char ' '
    char output_char = ' ';

    if (X_wins[0]&&X_wins[1]&&X_wins[2]) {
        // If the diagonal is filled with the character 'X' the output is 'X'
        output_char = 'X';
    } else if (O_wins[0]&&O_wins[1]&&O_wins[2]) {
        // If the diagonal is filled with the character 'O' the output is 'O'
        output_char = 'O';
    }

    return output_char;
}

char check_three_in_line(char (*game_state)[3]){
    /*
    This function checks if three 'X' or three 'O' are present in a row,
    column or diagonal. If three 'X' in line are present the char 'X' is
    returned, if three 'O' in line are present the char 'O' is returned. If
    none of those conditions are met, the char ' ' is returned.
    */

    // An array is created with the results of the functions checking rows,
    // columns and diagonals
    char checking[] = {check_rows(game_state),
                      check_columns(game_state),
                      check_first_diagonal(game_state),
                      check_second_diagonal(game_state)
                      };

    // The default output is ' '
    char output_char = ' ';

    int a;

    for (a = 0; a < 4; a++) {
        if (checking[a] != ' ') {
            // The results array is analyzed element by element, if the result
            // is different from ' ' the output is changed to that char
            output_char = checking[a];
        }
    }

    return output_char;
}

_Bool nobody_wins(char (*game_state)[3]){
    /*
    This function is used to check at the end of a game if nobody wins. The
    result is true if at the end all boxes are filled with characters different
    to ' ' and there are not three equal characters in line.
    */
    int a;
    int b;
    char current_box;
    // The default result is true
    _Bool output_bool = 1;

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            // The current char to analyze is extracted from the game state
            current_box = *(*(game_state + a) + b);

            if (current_box == ' ') {
                // If any of the characters in the game is ' ' the output is
                // false, because in that case, someone won
                output_bool = 0;
            }
        }
    }

    return output_bool;
}

struct button_press_arguments {
    /*
    This data structure is used to give different types of data to a function
    with an only pointer to this struct.
    */
    GtkWidget *player_label;
    GtkWidget *((*buttons)[3]);
    char (*game_state_pointer)[3];
    char *current_player;
    char *first_player;
    int i;
    int j;
};

void on_clicked_button(
                       GtkWidget *widget,
                       struct button_press_arguments *arguments
                      )
{
    /*
    This function is called when a button of the 3x3 game array is clicked. It
    first checks if the player wins with the current action, in that case all
    buttons are disabled and the winning player is show in the label. If nobody
    has won yet, the next player is show on the label and the current player is
    changed. If the game boxes are full with characters different to ' ' the
    labels indicates that nobody wins
    */
    char (*game_state)[3];
    // The game state is extracted from the arguments structure as a pointer
    game_state = arguments->game_state_pointer;
    // The coordinates of the button are extracted from the arguments structure
    int i = arguments->i;
    int j = arguments->j;
    // The current player is extracted from the arguments structure as a
    // pointer
    char *current_player = arguments->current_player;
    // The game box corresponding to the current button is set equal to the
    // current player. To represent that the player added a character.
    *(*(game_state + i) + j) = *current_player;

    // It is checked if someone won
    char winning_player = check_three_in_line(game_state);
    // The pointer to the buttons is extracted and saved
    GtkWidget *((*buttons)[3]);
    buttons = arguments->buttons;
    // The pointer to the player label is extracted and saved
    GtkLabel *player_label = (GtkLabel*) arguments->player_label;

    if (winning_player != ' ') {
        // If someone won the corresponding button label is set to the
        // corresponding character of the current player
        char state = *current_player;
        char *str;

        // A string pointer is prepared with the corresponding character and
        // format
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

        // First the button widget is obtained
        GtkButton *button = (GtkButton*) *(*(buttons + i) + j);
        // Then the label of the button is obtained
        GtkLabel *button_label=(GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
        // Finally the button label is set with the prepared string
        gtk_label_set_markup (GTK_LABEL (button_label), str);
        // The string created recently needs to be set free as it was created
        // using dynamic memory and is no longer needed
        g_free (str);

        // Allocate the necessary storage to make a formatted string
        char *winning_string = (char*)malloc(14 * sizeof(char));

        // A formatted string is created to indicate the winning player
        sprintf(winning_string, "Jugador %c gana", winning_player);

        // The label text is set to the winning player string
        gtk_label_set_text(player_label, winning_string);

        // The winning string needs to be set free as it was created using
        // dynamic memory and is no longer needed
        free(winning_string);

        int a;
        int b;

        // As some player won, all the game buttons are disabled
        for (a = 0; a < 3; a++) {
            for (b = 0; b < 3; b++) {
                GtkWidget *button_widget = *(*(buttons + a) + b);
                gboolean sensitive = FALSE;
                gtk_widget_set_sensitive(button_widget, sensitive);
            }
        }
    }else{
        // If no player won the state, in the game state array corresponding to
        // the game button pressed is set equal to the current player char
        char state = *current_player;
        char *str;

        // Depending of the state a string pointer is created with the char and
        // format. The player label text is changed to the next player and the
        // current player is changed to the next player

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

        // First the button widget is obtained
        GtkButton *button = (GtkButton*) *(*(buttons + i) + j);
        // Then the label of the button is obtained
        GtkLabel *button_label=(GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
        // Finally the button label is set with the prepared string
        gtk_label_set_markup (GTK_LABEL (button_label), str);
        // The string created recently needs to be set free as it was created
        // using dynamic memory and is no longer needed
        g_free (str);
        // And the current game button is disabled
        gboolean sensitive = FALSE;
        gtk_widget_set_sensitive(widget, sensitive);

        if (nobody_wins(game_state)){
            // In the case that all boxes of the game are filled with
            // characters different to ' ', the label text is set to indicate
            // that nobody won
            gtk_label_set_text(player_label, "Ninguno gana");
        }
    }
}

void reset_clicked(
                   GtkWidget *widget,
                   struct button_press_arguments *arguments
                  )
{
    /*
    This function is called when the reset button is clicked, and resets the
    game.
    */
    char (*game_state)[3];
    game_state = arguments->game_state_pointer;
    char *current_player = arguments->current_player;
    char *first_player = arguments->first_player;
    // A temporal character is used to save the last first player and make
    // comparisons
    char first_player_temp = *first_player;

    if (first_player_temp=='X') {
        // If the last first player was 'X' change the current first player to
        // 'O' and the current player to 'O'
        *first_player = 'O';
        *current_player = 'O';
    } else if (first_player_temp=='O') {
      // If the last first player was 'O' change the current first player to
      // 'X' and the current player to 'X'
        *first_player = 'X';
        *current_player = 'X';
    }

    GtkWidget *((*buttons)[3]);
    buttons = arguments->buttons;
    GtkLabel *player_label = (GtkLabel*) arguments->player_label;

    if (*first_player=='X') {
        // If the first player is 'X' change the player label text to indicate
        // that the first player is 'X'
        gtk_label_set_text(player_label, "Jugador X");
    } else if (*first_player=='O') {
        // If the first player is 'O' change the player label text to indicate
        // that the first player is 'O'
        gtk_label_set_text(player_label, "Jugador O");
    }

    int a;
    int b;
    GtkWidget *button_widget;
    gboolean sensitive = TRUE;
    GtkButton *button;
    GtkLabel *button_label;

    // Define a string pointer with text as " " and the correct format
    char *str = g_strdup_printf ("<span font=\"90\" color=\"red\">"
                                 "<b>%s</b>"
                                 "</span>",
                                 " ");

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            // Set all the game state characters to ' '
            *(*(game_state + a) + b) = ' ';
            // Set all the game buttons as enabled
            button_widget = *(*(buttons + a) + b);
            gtk_widget_set_sensitive(button_widget, sensitive);
            // Get the button widget
            button = (GtkButton*) *(*(buttons + a) + b);
            // Get the button widget label
            button_label = (GtkLabel*) gtk_bin_get_child(GTK_BIN(button));
            // Set the button widget label as the prepared string
            gtk_label_set_markup (GTK_LABEL (button_label), str);
        }
    }

    // The string created recently needs to be set free as it was created
    // using dynamic memory and is no longer needed
    g_free (str);
}

int main(int argc, char* argv[]) {
    /*
    This main function initializes the GUI and the Tic Tac Toe game.
    */
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *buttons[3][3];
    GtkWidget *player_label;
    GtkWidget *reset_button;

    char game_state[3][3];
    int i;
    int j;

    // Initially the game state array is filled with ' '
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            game_state[i][j] = ' ';
        }
    }

    // The first player and first current player is 'X'
    char first_player = 'X';
    char current_player = 'X';

    gtk_init(&argc, &argv);

    // Get GUI from file
    builder = gtk_builder_new_from_file(
        "./Tic_Tac_Toe.glade");

    // Create the main window and connect the exit button with a function that
    // quits the app
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // All the widgets present in the GUI are created
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
    reset_button = GTK_WIDGET(gtk_builder_get_object(builder, "reset_button"));

    // An array of structures is created, one element for each game button
    struct button_press_arguments arguments[3][3] = {};

    // An string pointer with text " " and correct format is created to assign
    // to the button labels initially
    char *str_button = g_strdup_printf ("<span font=\"90\">"
                                       "<b>%s</b>"
                                       "</span>",
                                       " ");

    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
           // Each button's structure is filled
           arguments[i][j].player_label = player_label;
           arguments[i][j].buttons = buttons;
           arguments[i][j].game_state_pointer = game_state;
           arguments[i][j].current_player = &current_player;
           arguments[i][j].first_player = &first_player;
           arguments[i][j].i = i;
           arguments[i][j].j = j;
           // Each button is connected to the same function but the structure
           // is different. The structure is introduced as its pointer
           g_signal_connect(
                            buttons[i][j],
                            "clicked",
                            G_CALLBACK(on_clicked_button),
                            &arguments[i][j]
                            );

           GtkWidget *button_label = gtk_bin_get_child(GTK_BIN(buttons[i][j]));
           // Each button label text is set to the prepared string
           gtk_label_set_markup (GTK_LABEL (button_label), str_button);
       }
    }
    // The string created recently needs to be set free as it was created
    // using dynamic memory and is no longer needed
    g_free (str_button);

    // The reset button is connected to the reset function, and the structure
    // used corresponds to the button_0_0 as all buttons have similar
    // structures with different coordinates, but in this case the coordinates
    // are no needed
    g_signal_connect(reset_button,
                     "clicked",
                     G_CALLBACK(reset_clicked),
                     &arguments[0][0]
                    );

    // A string pointer for the reset button label is created
    char *str_reset = g_strdup_printf ("<span font=\"20\">"
                                       "%s"
                                       "</span>",
                                       "Reinicio");

    GtkWidget *reset_label = gtk_bin_get_child(GTK_BIN(reset_button));
    // The button label text is set to the previous string
    gtk_label_set_markup (GTK_LABEL (reset_label), str_reset);
    // The string created recently needs to be set free as it was created
    // using dynamic memory and is no longer needed
    g_free (str_reset);

    // Show and start main loop
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
