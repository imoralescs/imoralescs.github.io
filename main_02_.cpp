#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// seven strings for the tetrominos
const char *tetrominos[7];

// game field vars
extern int game_field_width;
extern int game_field_height;
extern int game_field_start_x;
extern int game_field_start_y;

// game window vars
extern int game_win_width;
extern int game_win_height;
extern int game_win_start_x;
extern int game_win_start_y;

WINDOW* init_renderer_and_options(int game_win_height, int game_win_width, int game_win_start_y, int game_win_start_x);
int check_if_piece_fits(int tetromino, int rotation, int new_x, int new_y, unsigned char *game_field, int game_field_width);
int rotate(int x, int y, int rotation);
void clean_up(WINDOW* game_win);
void game_is_starting(WINDOW* game_win);
void game_is_over(WINDOW* game_win, int player_score);


// game field vars
int game_field_width = 12;
int game_field_height = 18;
int game_field_start_x = 2;
int game_field_start_y = 2;

// game window vars
int game_win_width = 30;
int game_win_height = 20;
int game_win_start_x = 0;
int game_win_start_y = 0;

WINDOW *init_renderer_and_options(int game_win_height, int game_win_width, int game_win_start_y, int game_win_start_x) {
    
    // initialize ncurses
    initscr();
    
    // check color support
    if (has_colors() == 0) {
        // end program if there is none
        endwin();
        printf("Your terminal does not support colors.\nFind a more modern system/terminal.");
        exit(1);
    }
    
    // enable color and set a new color pair
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    
    refresh();
    
    // disable the use of CTRL+* shortcuts
    raw();
    
    // won't print pressed characters on the screen
    noecho();
    
    // make the cursor invisible
    curs_set(0);
    
    // create our game window and set its background color to the color pair we made earlier
    WINDOW *game_win = newwin(game_win_height, game_win_width, game_win_start_y, game_win_start_x);
    wbkgd(game_win, COLOR_PAIR(1));
    
    // getches will be non blocking
    nodelay(game_win, 1);
    
    wrefresh(game_win);
    
    return game_win;
};

int check_if_piece_fits(int tetromino, int rotation, int new_x, int new_y, unsigned char *game_field, int game_field_width) {
    for (int py = 0; py < 4; py++) {
        for (int px = 0; px < 4; px++) {
            // get the correct element depending on rotation
            int pi = rotate(px, py, rotation);
            
            // get the equivalent field element by translating the tetromino array into the field
            int fi = (new_y + py - 2) * game_field_width + (new_x + px - 2);
            
            // if the pi element of the current tetromino has something else than a zero in the same spot on the game field then we can't move there
            if (tetrominos[tetromino][pi] == 'X' && game_field[fi] != 0) {
                return 0;
            }
        }
    }
    return 1;
};

int rotate(int x, int y, int rotation) {
    switch(rotation) {
        case 0: {
            return y * 4 + x;
        }
        case 1: {
            return 12 + y - (x * 4);
        }
        case 2: {
            return 15 - (y * 4) - x;
        }
        case 3: {
            return 3 - y + (x * 4);
        }
    }
    return 0;
};

void clean_up(WINDOW *game_win) {
    delwin(game_win);
    endwin();
}

void game_is_starting(WINDOW *game_win) {
    wclear(game_win);
    nodelay(game_win, 0);
    
    mvwprintw(game_win, 5, 1, "NTETRIS");
    mvwprintw(game_win, 6, 1, "-------");
    mvwprintw(game_win, 8, 1, "\"a\" = move left");
    mvwprintw(game_win, 9, 1, "\"d\" = move right");
    mvwprintw(game_win, 10, 1, "\"s\" = move down");
    mvwprintw(game_win, 11, 1, "\"z\" = rotate");
    mvwprintw(game_win, 13, 1, "Press anything to start");
    
    wgetch(game_win);
    nodelay(game_win, 1);
}

void game_is_over(WINDOW *game_win, int player_score) {
    wclear(game_win);
    nodelay(game_win, 0);
    
    mvwprintw(game_win, 5, 1, "Game Over");
    mvwprintw(game_win, 6, 1, "---------");
    mvwprintw(game_win, 8, 1, "Your final score is: %d", player_score);
    mvwprintw(game_win, 10, 1, "Press anything to exit");
    
    wgetch(game_win);
}

int main(void)
{
    // seed pgen
    srand(time(NULL));
    
    unsigned char game_field[game_field_width * game_field_height];
    
    WINDOW *game_win = init_renderer_and_options(game_win_height, game_win_width, game_win_start_y, game_win_start_x);
    
    // create the tetrominos
    tetrominos[0] = "..X...X...X...X.";
    tetrominos[1] = "..X..XX..X......";
    tetrominos[2] = ".X...XX...X.....";
    tetrominos[3] = ".XX..XX.........";
    tetrominos[4] = "..X..XX...X.....";
    tetrominos[5] = ".XX...X...X.....";
    tetrominos[6] = ".XX..X...X......";
    
    // set game field outline
    for(int y = 0; y < game_field_height; y++) {
        for(int x = 0; x < game_field_width; x++) {
            if(x == 0 || x == game_field_width - 1) {
                game_field[y * game_field_width + x] = 9;
            }
            else if(y == game_field_height - 1) {
                game_field[y * game_field_width + x] = 10;
            }
            else {
                game_field[y * game_field_width + x] = 0;
            }
        }
    }
    
    int game_over = 0;
    
    int current_piece_x = game_field_width / 2;
    int current_piece_y = game_field_start_y;
    int current_piece = rand() % 7;
    int current_rotation = 0;
    
    // game tick = 50ms, 20 gameticks = 1s
    int game_tick = 50000; 
    int speed_limit = 15;
    int speed_counter = 0;
    int force_piece_down = 0;
    int pieces_set = 0;
    int display_line = 0;
    int player_score = 0;
     
    // the line_buffer holds a line number in each element
    // the line numbers are so we know what lines have been completed
    // the buffer is filled starting from the first element
    // 100 = placeholder number
    unsigned char line_buffer[4] = {100, 100, 100, 100};
    
    char user_input;
    
    game_is_starting(game_win);
    
    while(!game_over) {
        /* game tick timing */
        usleep(game_tick);
        speed_counter++;
        force_piece_down = (speed_counter == speed_limit);
        
        /* player input */
        user_input = wgetch(game_win);
        
        /* update logic */
        current_piece_x -= (user_input == 'a' && check_if_piece_fits(current_piece, current_rotation, current_piece_x - 1, current_piece_y, game_field, game_field_width)) ? 1 : 0;
        current_piece_x += (user_input == 'd' && check_if_piece_fits(current_piece, current_rotation, current_piece_x + 1, current_piece_y, game_field, game_field_width)) ? 1 : 0;
        current_piece_y += (user_input == 's' && check_if_piece_fits(current_piece, current_rotation, current_piece_x, current_piece_y + 1, game_field, game_field_width)) ? 1 : 0;

        current_rotation += (user_input == 'z' && check_if_piece_fits(current_piece, current_rotation + 1, current_piece_x, current_piece_y, game_field, game_field_width)) ? 1 : 0;
        
        if(current_rotation > 3) {
            current_rotation = 0;
        }
        
        if(force_piece_down) {
            if(check_if_piece_fits(current_piece, current_rotation, current_piece_x, current_piece_y + 1, game_field, game_field_width)) {
                current_piece_y++;
            }
            else {
                // place current piece into the field
                for(int py = 0; py < 4; py++) {
                    for(int px = 0; px < 4; px++) {
                        if(tetrominos[current_piece][rotate(px, py, current_rotation)] == 'X') {
                            game_field[(current_piece_y + py - 2) * game_field_width + (current_piece_x + px - 2)] = current_piece + 1;
                        }
                    }
                }
                
                // decrease the speed_limit every five pieces we set down to make the game faster
                pieces_set++;
                if(pieces_set % 5 == 0) {
                    if(speed_limit > 5) {
                        speed_limit--;
                    }
                }
                
                // check for any horizontal lines by first iterating over the four rows of the tetromino
                for (int py = 0; py < 4; py++) {
                    if ((current_piece_y + py - 2) < game_field_height - 1) {
                        // assume that there is a horizontal line
                        int is_a_line = 1;
                        
                        // now in the py row iterate over the columns
                        for (int px = 0; px < game_field_width; px++) {
                            // if the element in the current py row and px column is not a zero, the expression is true (1)
                            // since is_a_line is true (1), when we & (AND) them together is_a_line gets set to true (1)
                            // 
                            // if however the element is a zero, the expression is false (0)
                            // if we & (AND) together is_a_line which is true (1) and the expression which is false (0) then is_a_line gets set to false (0)
                            // this means there is no horizontal line in this row
                            is_a_line &= (game_field[(current_piece_y + py - 2) * game_field_width + px]) != 0;
                        }
                        
                        if (is_a_line) {
                            // since is_a_line has not been changed to false, we know that on this row there is a line
                            for (int px = 1; px < game_field_width - 1; px++) {
                                game_field[(current_piece_y + py - 2) * game_field_width + px] = 8;
                                display_line = 1;
                            }
                            
                            // save the known line to the buffer
                            for (int i = 0; i < 4; i++) {
                                if (line_buffer[i] == 100) {
                                    line_buffer[i] = current_piece_y + py;
                                    break;
                                }
                            }
                        }
                    }
                }
                
                // choose next piece
                current_piece_x = game_field_width / 2;
                current_piece_y = game_field_start_y;
                current_piece = rand() % 7;
                current_rotation = 0;
                
                // if new piece does not fit
                game_over = !check_if_piece_fits(current_piece, current_rotation, current_piece_x, current_piece_y, game_field, game_field_width);
            }
            
            speed_counter = 0;
        }
        
        /* render output */
        wclear(game_win);
        
        // the game field is a grid of number values which all correspond to something
        // 0 = ' '
        // 1 = 'A'
        // 2 = 'B'
        // 3 = 'C'
        // 4 = 'D'
        // 5 = 'E'
        // 6 = 'F'
        // 7 = 'G'
        // 8 = '='
        // 9 = '|'
        // 10 = '-'
        
        // draw game field
        for (int y = 0; y < game_field_height; y++) {
            for (int x = 0; x < game_field_width; x++) {
                if (game_field[y * game_field_width + x] == 0) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", ' ');
                }
                else if (game_field[y * game_field_width + x] == 1) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'A');
                }
                else if (game_field[y * game_field_width + x] == 2) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'B');
                }
                else if (game_field[y * game_field_width + x] == 3) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'C');
                }
                else if (game_field[y * game_field_width + x] == 4) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'D');
                }
                else if (game_field[y * game_field_width + x] == 5) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'E');
                }
                else if (game_field[y * game_field_width + x] == 6) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'F');
                }
                else if (game_field[y * game_field_width + x] == 7) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", 'G');
                }
                else if (game_field[y * game_field_width + x] == 8) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", '=');
                }
                else if (game_field[y * game_field_width + x] == 9) {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", '|');
                }
                else {
                    mvwprintw(game_win, game_field_start_y + y, game_field_start_x + x, "%c", '-');
                }
            }
        }
        
        // draw the player score
        mvwprintw(game_win, 2, 17, "SCORE: %d", player_score);
        
        // draw current piece
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (tetrominos[current_piece][rotate(x, y, current_rotation)] == 'X') {
                    // 65 = 'A', 66 = 'B' and so on
                    mvwprintw(game_win, current_piece_y + y, current_piece_x + x, "%c", 65 + current_piece);
                }
            }
        }
        
        // iterate over the buffer
        for (int i = 0; i < 4; i++) {
            int number_of_lines = 0;
            
            // if we have a line number stored
            if (line_buffer[i] != 100) {
                number_of_lines++;
                
                // if we need to display the line
                if (display_line == 1) {
                    
                    // draw the line onto the screen
                    wrefresh(game_win);
                    
                    // wait 400ms
                    usleep(game_tick * 8);
                    
                    // set the lines to empty
                    for (int px = 1; px < game_field_width - 1; px++) {
                        game_field[(line_buffer[i] - 2) * game_field_width + px] = 0;
                    }
                    
                    // set display line off
                    display_line = 0;
                }
                
                // set all off the pieces above the lines down by one
                for (int px = 1; px < game_field_width - 1; px++) {
                    for (int py = line_buffer[i] - 2; py > 0; py--) {
                        game_field[py * game_field_width + px] = game_field[(py - 1) * game_field_width + px];
                    }
                }
                
                // set the buffer element to be vacant
                line_buffer[i] = 100;
            }
            
            // increase player score based on how many lines got completed
            player_score += (number_of_lines * 100);
        }
        
        wrefresh(game_win);
    }
    
    game_is_over(game_win, player_score);
    
    clean_up(game_win);
    
    return 0;
};
