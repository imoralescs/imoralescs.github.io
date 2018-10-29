#include <iostream>
#include <SDL2/SDL.h>
#include <utility>
#include <string>

using namespace std;

// ==========================================================
// SDL - Part 0
// ========================================================== 
/*
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char* args[]) 
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindow(
        "Hello", 0, 0, 640, 480,
        SDL_WINDOW_FULLSCREEN |
        SDL_WINDOW_OPENGL
    );

    return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char* args[]) 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    string title;
    int windowMode;
    int posX;
    int posY;
    int width;
    int height;
    int rendererMode;
    int index;

    SDL_Init(SDL_INIT_VIDEO);
    
    title           =   "SDL2 Tutorial";
    windowMode      =   SDL_WINDOW_OPENGL;
    posX            =   SDL_WINDOWPOS_CENTERED;
    posY            =   SDL_WINDOWPOS_CENTERED;
    width           =   1280;
    height          =   720;
    rendererMode    =   SDL_RENDERER_ACCELERATED;
    
    window          =   SDL_CreateWindow(title.c_str(), posX, posY, width, height, windowMode);
    renderer        =   SDL_CreateRenderer(window, index, rendererMode);
    
    SDL_Delay(4000);
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();

    return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

class Window 
{
    private:
        int _width;
        int _height;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
    public:
        Window(int width, int height) {
            this->_width = width;
            this->_height = height;
        };
        virtual ~Window() {
            this->hide();
        }

        void show() {
            if(this->_window != nullptr) {
                string title;
                int posX;
                int posY;
                int windowType;
                
                title = "SDL 2 Tutor";
                posX = SDL_WINDOWPOS_CENTERED;
                posY = SDL_WINDOWPOS_CENTERED;
                windowType = SDL_WINDOW_OPENGL;
                
                this->_window = SDL_CreateWindow(
                    title.c_str(), 
                    posX, 
                    posY, 
                    this->_width, 
                    this->_height, 
                    windowType);
                
                int rendererIndex;
                int rendererType;
                
                rendererIndex = 0;
                rendererType = SDL_RENDERER_ACCELERATED;
                
                this->_renderer = SDL_CreateRenderer(
                    this->_window, 
                    rendererIndex, 
                    rendererType);
            }
        };
        
        void hide() {
            SDL_DestroyRenderer(this->_renderer);
            SDL_DestroyWindow(this->_window);
        };

        void render() {
            SDL_RenderClear(this->_renderer);
            SDL_RenderPresent(this->_renderer);
        };
};

class Game 
{
    protected:
        bool _run;
        Window *_window;

        void onAwake() {
            SDL_Init(SDL_INIT_EVERYTHING);

            this->_window = new Window(1280, 720);
            this->_window->show();
        };
        
        void onInput() {
            SDL_Event event;

            while(SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_QUIT:
                        this->end();
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym) {
                            case SDLK_ESCAPE:
                                this->end();
                                break;
                            default:
                                break;
                        }
                    default:
                        break;
                }
            }
        };
        
        void onUpdate() {

        };
        
        void onRender() {
            this->_window->render();
        };
        
        void onFinish() {
            this->_window->hide();
            SDL_Quit();
        };
    
    public:
        Game(){};
        virtual ~Game(){};

        void start() {
            this->_run = true;

            this->onAwake();

            while(_run) {
                this->onInput();
                this->onUpdate();
                this->onRender();
            }

            this->onFinish();
        };

        void end() {
            this->onFinish();
        };
};

int main(int argc, char* args[]) 
{
    Game game;

    game.start();
    
    return 0;
}
*/


// g++ main.cpp -o main -std=c++11 -lSDL2
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
    // Set size of renderer to the same as window
    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
     
    // Set color of renderer to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //-- Render something
    // Clear the window and make it all red
    SDL_RenderClear(renderer);
    // Render the changes above ( which up until now had just happened behind the scenes )
    SDL_RenderPresent(renderer);
    // Pause program so that the window doesn't disappear at once.
    // This willpause for 4000 milliseconds which is the same as 4 seconds
    SDL_Delay(4000);
}
*/

//---- SDL2 Structures
//-- SDL_Window
// This is the physical window you see on your screen. One SDL_Window represents one physical window on your screen. You can have as many SDL_Windows as you like. The structs holds info about the window like position, size, window state and window style.

//-- SDL_Renderer
// The SDL_Renderer is basically what you use to render to the screen. The renderer is usually tied to a window. One renderer can only render within one window. The SDL_Renderer also contains info about the rending itself like hardware acceleration and v-sync prevention.

//---- Setting up SDL2
// Before you can use SDL2, you must set it up by initializing it and creating a SDL_Window and a SDL_Renderer.

/*
if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    // Something failed, print error and exit.
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    return -1;
}
*/

// SDL_Init - We using this function to initialize SDL, as parameters they accept `flags` to specifies what you want to initialize, in this above example case we set it to `SDL_INIT_EVERYTHING` to initialize everything. As the function success they return the value 0 otherwise they return -1.
// SDL_GetError - This function tell us what went wrong.

//---- Creating and Setting up SDL_Window
/*
int posX = 100;
int posY = 200;
int sizeX = 300;
int sizeY = 400;
SDL_Window *window;
SDL_Renderer *renderer;
// Create and init the window
window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
    
if(window == nullptr) {
    std::cout << "Failed to create window : " << SDL_GetError();
    return -1;
}
*/

// SDL_CreateWindow - We using this function to create our window, this function accept the following parameters:
// * title - The window caption/title that appears on the top of the window
// * posX - x position of the window
// * posY - y position of the window
// * sizeW - width of the window
// * sizeH - height of the window
// * flags - specifies window state or properties.

// The `flags` parameters has a few different possible values, here are the flasg that are most revelant to us now:
// * SDL_WINDOW_FULLSCREEN - the window will start out in fullscreen mode
// * SDL_WINDOW_FULLSCREEN_DESKTOP - the window will start out in fullscreen mode with the same resolution as your desktop currently has
// * SDL_WINDOW_OPENGL - for use with OpenGL
// * SDL_WINDOW_SHOWN - the window will start out being visible
// * SDL_WINDOW_HIDDEN - the window wil start out being invisible

// SDL_CreateWindow will return a valid pointer on success otherwise will return `nullptr` or `NULL`

//---- Creating the SDL_Renderer
/*
// Create and init the renderer
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
if(renderer == nullptr) {
    std::cout << "Failed to create renderer : " << SDL_GetError();
    return -1;
}
*/
// SDL_CreateRenderer - We using this function to create our renderer, this function accept the following parameters:
// * window - the SDL_Window this rendere will be attached to.
// * index - specifies which rendering driver to use.
// * flags - species how the rendering should be done

// SDL_CreateRenderer will return window as a valid pointer on success otherwise nullptr or NULL

//---- Setting up the renderer
/*
// Set size of renderer to the same as window
    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
*/
//-* SDL_RenderSetLogicalSize - this is used to set the resolution of the renderer, this function accept the following parameters:
// * renderer - is the SDL_Renderer we want to se the resolution on.
// * width - desired width in pixel
// * height - desired height in pixel

// as return valid value is 0 otherwise will be 1

/*
// Set color of renderer to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
*/
//-* SDL_SetRenderDrawColor - this is used to set the color for drawing operations, this function accept the following parameters:
// * renderer - is the SDL_Renderer we want to set render color
// * red - specifies amount of red(0 - 255)
// * green - specifies amount of green(0 - 255)
// * blue - specifies amount of blue(0 - 255)
// * alpha - specifies amount of alpha(0 - 255) 0 = completely transparent

// as return valid value is 0 otherwise will be 1

//---- Rendering something
// Before drawing somthing we need to clear our window and the fill our window with the color we set using SDL_SetRenderDrawColor
/*
//-* SDL_RenderClear - to clear the current rendering target with the drawing color, in this case make it all red
SDL_RenderClear(renderer);
// Render the changes above ( which up until now had just happened behind the scenes )
SDL_RenderPresent(renderer);
*/

// ==========================================================
// SDL - Part 2 DRAWING RECTANGLES
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
    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
     
    // ... After setting up renderer and window
    // Set color of renderer to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // Clear the window and make it all red
    SDL_RenderClear(renderer);
    // Create a rectangle
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;
    // Change color to blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // Render our SDL_Rect, the rectangle will no be blue
    SDL_RenderDrawRect(renderer, &r);
    // Render the changes above ( which up until now had just happened behind the scenes )
    SDL_RenderPresent(renderer);
    // Pause program so that the window doesn't disappear at once.
    // This willpause for 4000 milliseconds which is the same as 4 seconds
    SDL_Delay(4000);
}
*/

// To fill rectangle up
/*
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

    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
     
    // ... After setting up renderer and window
    // Set color of renderer to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear the window and make it all red
    SDL_RenderClear(renderer);

    // Create a rectangle
    SDL_Rect r;

    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    // Change color to blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Fill
    SDL_RenderFillRect(renderer, &r);

    // Render the changes above ( which up until now had just happened behind the scenes )
    SDL_RenderPresent(renderer);

    // Pause program so that the window doesn't disappear at once.
    // This willpause for 4000 milliseconds which is the same as 4 seconds
    SDL_Delay(4000);
}
*/
// ==========================================================
// SDL - Part 4 Game Loop
// ==========================================================
// The game loop itself is usually a form of infinite loop, So in order to exit the loop, we need a way of setting the loop bool to yountrue inside the loop.This will make the loop condition ( if ( loop ) ) false and the loop will stop. We could just use a break; to quit the loop. But this won’t work when we start handling input.
// ==========================================================
// SDL - Part 5 Event
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

    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);

    bool loop = true;
    
    while(loop) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {

            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
				    case SDLK_RIGHT:
						cout << "Typing to right..." <<  endl;
						break;
					case SDLK_LEFT:
						cout << "Typing to left..." <<  endl;
						break;
						// Remeber 0,0 in SDL is left-top. So when the user pressus down, the y need to increase
					case SDLK_DOWN:
						cout << "Typing to down..." <<  endl;
						break;
					case SDLK_UP:
						cout << "Typing to up..." <<  endl;
						break;
                    case SDLK_ESCAPE:
                        SDL_Quit();
                        break;
					default :
						break;
				}
			}
		}

        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

		SDL_Delay( 16 );
	}
}
*/
// ==========================================================
// SDL - Part 6 MAKE RECTANGLES MOVE
// ==========================================================

int posX = 100;
int posY = 200;
int sizeX = 300;
int sizeY = 400;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Rect playerPos;
bool InitSDL() {
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
        return false;
    }
    
    return true;
}
bool CreateWindow() {
    window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
    
    if(window == nullptr) {
        std::cout << "Failed to create window : " << SDL_GetError();
        return false;
	}
    
    return true;
}
bool CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(renderer == nullptr) {
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return false;
    }
    
    return true;
}
void SetupRenderer() {
    // Set size of renderer to the same as window
    SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);
    
    // Set color of renderer to green
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
}
bool InitEverything() {
    if(!InitSDL()) {
        return false;
    }
	if(!CreateWindow()) {
	    return false;
    }
	if(!CreateRenderer()) {
	    return false;
    }
    
    SetupRenderer();
    
    return true;
}
void Render() {
    // Clear the window and make it all green
    SDL_RenderClear(renderer);
	// Change color to blue
	SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
	// Render our "player"
	SDL_RenderFillRect(renderer, &playerPos);
	// Change color to green
	SDL_SetRenderDrawColor(renderer, 219, 50, 54, 255);
	// Render the changes above
	SDL_RenderPresent(renderer);
}
void RunGame() {
    bool loop = true;
    
    while(loop) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
			
            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
				    case SDLK_RIGHT:
						++playerPos.x;
						break;
					case SDLK_LEFT:
						--playerPos.x;
						break;
						// Remeber 0,0 in SDL is left-top. So when the user pressus down, the y need to increase
					case SDLK_DOWN:
						++playerPos.y;
						break;
					case SDLK_UP:
						--playerPos.y;
						break;
					default :
						break;
				}
			}
		}
		Render();
		// Add a 16msec delay to make our game run at ~60 fps
		SDL_Delay( 16 );
	}
}
int main(int argc, char* args[])
{
	if(!InitEverything()) { 
		return -1;
    }
	// Initlaize our playe
	playerPos.x = 20;
	playerPos.y = 20;
	playerPos.w = 20;
	playerPos.h = 20;
	RunGame();
}

http://headerphile.com/
https://www.willusher.io/pages/sdl2/
https://thenumbat.github.io/cpp-course/index.html
