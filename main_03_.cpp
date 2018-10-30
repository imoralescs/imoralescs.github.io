#include <iostream>
#include <SDL2/SDL.h>
#include <utility>
#include <string>

using namespace std;

// g++ main.cpp -o main -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

// Compile: g++ main.cpp -o main -std=c++11 -lSDL2
// ==========================================================
// SDL - Part 1
// ========================================================== 

/*
int main(int argc, char* args[])
{
    int posX = 100;
    int posY = 200;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
 
    // Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        // Something failed, print error and exit.
        std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create and init the window
    window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
    if(window == nullptr) {
        std::cout << "Failed to create window : " << SDL_GetError();
        return -1;
    }
    
    // Create and init the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return -1;
    }

    SDL_Delay(4000);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();

    return 0;
}
*/

//---- Setting up SDL2
/*
if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    // Something failed, print error and exit.
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    return -1;
}
*/
// Before doing anything else, you must initialize SDL as a whole. To initialize SDL we need to used the following function `SDL_Init`, as parameters they accept `flags` to specifies what to initialize on SDL. SDL allows you to initialize particular subsets (or subsystems) of the library individually. In the example case we want to initialize everything, that why we using the following flag `SDL_INIT_EVERYTHING `. This function as successfully they return the value integer 0 otherwise they return value -1.

//---- SDL2 Structures

//-- SDL_Window
/*
window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
if(window == nullptr) {
    std::cout << "Failed to create window : " << SDL_GetError();
    return -1;
}
*/
// This is the physical window you see on your screen, you must create the window that your program will use for multimedia input and output. One SDL_Window represents one physical window on your screen, but you can have as many SDL_Windows as you like. The structs holds info about the window like position, size, window state and window style.
/*
 SDL_CreateWindow - We using this function to create our window, this function accept the following parameters:
 + title - The window caption/title that appears on the top of the window
 + posX - x position of the window
 + posY - y position of the window
 + sizeW - width of the window
 + sizeH - height of the window
 + flags - specifies window state or properties. The `flags` parameters has a few different possible values, here are the flasg that are most revelant to us now:
 ++ SDL_WINDOW_FULLSCREEN - the window will start out in fullscreen mode
 ++ SDL_WINDOW_FULLSCREEN_DESKTOP - the window will start out in fullscreen mode with the same resolution as your desktop currently has
 ++ SDL_WINDOW_OPENGL - for use with OpenGL
 ++ SDL_WINDOW_SHOWN - the window will start out being visible
 ++ SDL_WINDOW_HIDDEN - the window wil start out being invisible
*/
// This function as successfully they return the same window otherwise they return null.

//-- SDL_Renderer
/*
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
if(renderer == nullptr) {
    std::cout << "Failed to create renderer : " << SDL_GetError();
    return -1;
}
*/
// The SDL_Renderer is basically what you use to render to the screen. The SDL structure SDL_Renderer represents a rendering context, this means that it contains all current settings related to rendering, as well as the instructions for how to render the current frame.  The renderer is usually tied to a window element. One renderer can only render within one window. The SDL_Renderer also contains info about the rending itself like hardware acceleration and v-sync prevention. To create a rendering context, you can use the function `SDL_CreateWindowAndRenderer()` or `SDL_CreateRenderer()`. 
/*
 SDL_CreateRenderer - We using this function to create our renderer, this function accept the following parameters:
 + window - the SDL_Window this rendere will be attached to.
 + index - specifies which rendering driver to use.
 + flags - species how the rendering should be done
*/

//-- Shutting Down
// Once your program has completed its operation, it must destroy the window and rendering to free related resources. As you might expect, `SDL_DestroyWindow()` and `SDL_DestroyRenderer()` does just that. The function will close your window and rendering, freeing related memory.
// Finally, to shut down SDL as a whole, call `SDL_Quit()`.

// ==========================================================
// SDL - Part 2 Rendering
// ========================================================== 

int main(int argc, char* args[])
{
    int posX = 100;
    int posY = 200;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
 
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
        return -1;
    }

    window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
    if(window == nullptr) {
        std::cout << "Failed to create window : " << SDL_GetError();
        return -1;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return -1;
    }

    // Set color of renderer
    SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);

    // Clear the window and make it all to the color we set above
    SDL_RenderClear(renderer);

    // Render
    SDL_RenderPresent(renderer);

    SDL_Delay(4000);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();

    return 0;
}

//---- Draw setting
// The drawing state is contained in the rendering context, so SDL provides several functions to adjust it. To change the drawing color we use the function `SDL_SetRenderDrawColor()`. We used this function to set the color for drawing or filling rectangles, lines, and points, and for SDL_RenderClear(). On `SDL_SetRenderDrawColor()` function we simple pass the R, G, B, and A color values. To get the current color, use the function `SDL_GetRenderDrawColor()`.

//---- Clearing the Renderer
// We used `SDL_RenderClear()` function to clear the current rendering target with the drawing color. This function clears the entire rendering target, ignoring the viewport and the clip rectangle. You should clear the window after each frame, as otherwise drawing will persist between frames, even if moved.

//---- Rendering
// We used `SDL_RenderPresent()` function to tells the renderer show its operations on its window.
