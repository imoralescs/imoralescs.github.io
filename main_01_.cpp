/*
#include <iostream>
#include <Windows.h>
 
using namespace std;

int nScreenWidth = 80;			// Console Screen Size X (columns)
int nScreenHeight = 30;			// Console Screen Size Y (rows)

int main()
{
    wchar_t *screen = new wchar_t[80*30];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;


    while(1) {
        screen[10 * 80 + 15] = L'P';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten)
    }

    return 0;
}
*/

// Started
/*
#include <ncurses.h>
using namespace std;

int main()
{
    // Initializes the screen, sets up memory and clears the screen
    initscr();
    
    // Prints a string(const char *) to a window
    printw("Hello World!");

    // Refreshes the screen to match what in memory
    refresh();

    // Whats for user input, returns int value of that key
    getch();

    // Deallocates memory and ends ncurses
    endwin();

    return 0;
}
*/

// Moving cursors
/*
#include <ncurses.h>
using namespace std;

int main()
{
    initscr();
    
    int x, y;
    x = y = 10;

    // Moves the cursor to the specified location
    move(y, x);
    
    printw("Hello World!");

    getch();

    endwin();

    return 0;
}
*/

// Basic template Ncurses 
/*
#include <ncurses.h>
using namespace std;

int main()
{
    // Initialize the screen
    initscr();

    // Get user input, return int value of that key
    int c = getch();
    
    // Deallocates memory and end ncurses
    endwin();

    return 0;
}
*/

/*
// Ncurses Window
#include <ncurses.h>
using namespace std;

int main()
{
    // Initialize the screen
    initscr();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;

    // Pointer to windows
    // newwin() - function to create new windows,
    WINDOW *win = newwin(height, width, start_y, start_x);

    // To clear the actual window content
    refresh();

    // Apply border to the windows
    box(win, 0, 0);

    // If we want to display content inside of the window
    //wprintw(win, "This is my box");

    // If we want to display content inside the box with specific x and y coordenate
    mvwprintw(win, 1, 1, "This is my box");

    // Display the new window content
    wrefresh(win);

    // Get user input, return int value of that key
    int c = getch();
    
    // Deallocates memory and end ncurses
    endwin();

    return 0;
}
*/

#include <ncurses.h>
using namespace std;

// game window vars
int height = 20; 
int width = 30;
int start_y = 0;
int start_x = 0;

// game field vars
int game_field_width = 12;
int game_field_height = 18;
int game_field_start_x = 2;
int game_field_start_y = 2;

int main()
{
    unsigned char game_field[game_field_width * game_field_height];
    
    // Set game field outline
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
    
    initscr();

    WINDOW *win = newwin(height, width, start_y, start_x);

    refresh();
    
    // Draw game field
    for(int y = 0; y < game_field_height; y++) {
        for(int x = 0; x < game_field_width; x++) {
            if(game_field[y * game_field_width + x] == 0) {
                mvwprintw(win, game_field_start_y + y, game_field_start_x + x, "%c", ' ');
            }
            else if(game_field[y * game_field_width + x] == 9) {
                mvwprintw(win, game_field_start_y + y, game_field_start_x + x, "%c", '|');
            }
            else {
                mvwprintw(win, game_field_start_y + y, game_field_start_x + x, "%c", '-');
            }
        }
    }

    wrefresh(win);

    int c = getch();
    
    endwin();

    return 0;
}
