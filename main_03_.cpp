#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <utility>
#include <string>

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
*/

//---- Draw setting
// The drawing state is contained in the rendering context, so SDL provides several functions to adjust it. To change the drawing color we use the function `SDL_SetRenderDrawColor()`. We used this function to set the color for drawing or filling rectangles, lines, and points, and for SDL_RenderClear(). On `SDL_SetRenderDrawColor()` function we simple pass the R, G, B, and A color values. To get the current color, use the function `SDL_GetRenderDrawColor()`.

//---- Clearing the Renderer
// We used `SDL_RenderClear()` function to clear the current rendering target with the drawing color. This function clears the entire rendering target, ignoring the viewport and the clip rectangle. You should clear the window after each frame, as otherwise drawing will persist between frames, even if moved.

//---- Rendering
// We used `SDL_RenderPresent()` function to tells the renderer show its operations on its window.

// ==========================================================
// SDL - Part 3 Drawing
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
    SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
    SDL_RenderClear(renderer);
    // Create a rectangle
    SDL_Rect r1, r2;
    // Set Size and position
    r1.x = 50;
    r1.y = 50;
    r1.w = 50;
    r1.h = 50;
    r2.x = 100;
    r2.y = 100;
    r2.w = 50;
    r2.h = 50;
    // Set color to paint rect
    SDL_SetRenderDrawColor(renderer, 198, 24, 0, 255);
    // Render our SLD_Rect
    SDL_RenderDrawRect(renderer, &r1);
    // Set color to paint another rect
    SDL_SetRenderDrawColor(renderer, 49, 182, 57, 255);
    // Render our SLD_Rect
    SDL_RenderDrawRect(renderer, &r2);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    return 0;
}
*/

//---- Drawing
// SDL provides several functions for drawing rudimentary shapes—namely, points, lines, rectangles, and filled rectangles. The functions are all used as you'd expect: the point and line functions simply take the screen coordinates of the shape, and the rectangle functions take a SDL_Rect with the same data.

//---- Fill rectangle up

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
    SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
    SDL_RenderClear(renderer);
    // Create a rectangle
    SDL_Rect r1, r2;
    // Set Size and position
    r1.x = 50;
    r1.y = 50;
    r1.w = 50;
    r1.h = 50;
    r2.x = 100;
    r2.y = 100;
    r2.w = 50;
    r2.h = 50;
    SDL_SetRenderDrawColor(renderer, 198, 24, 0, 255);
    // Render our fill SLD_Rect
    SDL_RenderFillRect(renderer, &r1);
    SDL_SetRenderDrawColor(renderer, 49, 182, 57, 255);
    // Render our fill SLD_Rect
    SDL_RenderFillRect(renderer, &r2);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    return 0;
}
*/

// ==========================================================
// SDL - Part 4 Events
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
    bool loop = true;
    while(loop) {
        
        // Event handler
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
				    case SDLK_RIGHT:
						cout << "Typing to right key..." <<  endl;
						break;
					case SDLK_LEFT:
						cout << "Typing to left key..." <<  endl;
						break;
					case SDLK_DOWN:
						cout << "Typing to down key..." <<  endl;
						break;
					case SDLK_UP:
						cout << "Typing to up key..." <<  endl;
						break;
                    case SDLK_ESCAPE:
                        cout << "Goodbye, shut it down..." <<  endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
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
    return 0;
}
*/

//---- Event loop
// Most multimedia programs rely on an events system to process input, SDL provides a flexible API for processing input events. Essentially, SDL records input from devices (like the keyboard, mouse, or controller) as events, storing them in the "event queue." You can think of this structure just like a waiting line—events are queued in the back of the line and taken from the front of the line.

//---- Game loop
// In a game things need to happen over and over again. So we need a loop that does all these thing. A game loop itself is usually a form of infinite loop, so in order to exit the loop, we need a way of set the loop true bool value from start to untrue or false from inside the loop. This can be posible using inside the loop a if condition to stop the loop.

/*
bool loop = true;
while(loop) {
    loop = false;
}
*/

// Inside of the game loop we have another event loop, this will processes all events and runs your program based on the input. Each time the event loop is run, you must pull each event off the event queue (in order) to process the input. This is done with the function `SDL_PollEvent()`. 

//-- `SDL_Event event`
// In our code SDL is initialized and we declare a flag to initialize everything on this include `SDL_INIT_EVENTS` this keeps track of whether the user input. All events in SDL is in the form of `SDL_Event`. 
/*
// Event handler
SDL_Event event;
*/

//-- `SDL_PollEvent()`
// This function retrieve the first event from the queue, copying the value into a parameter of type SDL_Event.
/*
SDL_PollEvent(&event)
*/

//---- Event types

//-- Quitting SDL_QUIT

//-- Keyboard events SDL_KEYDOWN & SDL_KEYUP

//-- Other events

// ==========================================================
// SDL - Part 5 Moving things
// ========================================================== 
/*
int main(int argc, char* args[])
{
    int posX = 900;
    int posY = 300;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect elementPosition;
 
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
    // Initialize our element position
    elementPosition.x = 20;
	elementPosition.y = 20;
	elementPosition.w = 20;
	elementPosition.h = 20;
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
                        ++elementPosition.x;
						cout << "Typing to right key..." <<  endl;
						break;
					case SDLK_LEFT:
                        --elementPosition.x;
						cout << "Typing to left key..." <<  endl;
						break;
					case SDLK_DOWN:
                        ++elementPosition.y;
						cout << "Typing to down key..." <<  endl;
						break;
					case SDLK_UP:
                        --elementPosition.y;
						cout << "Typing to up key..." <<  endl;
						break;
                    case SDLK_ESCAPE:
                        cout << "Goodbye, shut it down..." <<  endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        SDL_Quit();
                        break;
					default :
						break;
				}
			}
		}
        // Clear the window
        SDL_RenderClear(renderer);
        
        // Set first color
        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
        // Render our element
        SDL_RenderFillRect(renderer, &elementPosition);
        // Set color to our element
        SDL_SetRenderDrawColor(renderer, 198, 24, 0, 255);
        // Render change 
        SDL_RenderPresent(renderer);
		
        // Add a 16msec delay to make our game run at ~60 fps, wait before next frame
        SDL_Delay( 16 );
	}
    return 0;
}
*/
// ==========================================================
// SDL - Part 6 Collision detection
// ========================================================== 
/*
enum class Direction {
    Left,
    Right
};
struct NPC {
    NPC(
        SDL_Rect _position,
        int _speed,
        Direction _direction
    ) {
        position = _position;
        speed = _speed;
        direction = _direction;
    }
    SDL_Rect position;
    int speed;
    Direction direction;
};
std::vector<NPC> npc;
int lastNPC = 50;
void addNPC() {
    if ((rand() % 2) == 0) {
		npc.push_back( 
            NPC({ 
                rand() % 300, 
                lastNPC, 
                20, 
                20 
            }, 
            1, 
            Direction::Right));
	}
	else
	{
		npc.push_back(
            NPC({
                rand() % 300, 
                lastNPC
                , 
                20, 
                20 
            }, 
            1, 
            Direction::Left));
	}
	lastNPC += 25;
}
bool checkCollision();
bool checkNPCCollisions();
SDL_Rect elementPosition;
int main(int argc, char* args[])
{
    int posX = 900;
    int posY = 300;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect topBar;
    SDL_Rect bottomBar;
    // Amount of pixel the element move per keypress
    int movementFactor = 15;
 
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
    // Initialize no controller element
    addNPC();
    addNPC();
    addNPC();
    addNPC();
    // Init top and bottom bar
	topBar.x = 0;
	topBar.y = 0;
	topBar.w = sizeX;
	topBar.h = 20;
	bottomBar.x = 0;
	bottomBar.y = sizeY - 20;
	bottomBar.w = sizeX;
	bottomBar.h = 20;
    // Initialize our element position
	elementPosition.w = 20;
	elementPosition.h = 20;
    // sizeX / 2 = middle pixel of the screen
	// elementPosition.w / 2 = middle of the element 
	// So setting player x pos to [middle of screen] - [middle of player] means it will be centerd in the screen.
    elementPosition.x = (sizeX / 2) - (elementPosition.w / 2);
	elementPosition.y = sizeY - bottomBar.h;
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
                        elementPosition.x += movementFactor;
						break;
					case SDLK_LEFT:
                        elementPosition.x -= movementFactor;
						break;
					case SDLK_DOWN:
                        elementPosition.y += movementFactor;
						break;
					case SDLK_UP:
                        elementPosition.y -= movementFactor;
						break;
                    case SDLK_ESCAPE:
                        std::cout << "Goodbye, shut it down..." <<  std::endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        SDL_Quit();
                        break;
					default :
						break;
				}
			}
		}
        // =============================================
        // Check collision against no controller element
        // =============================================
        if(checkNPCCollisions()) {
            elementPosition.x = ( sizeX / 2 ) - ( elementPosition.w / 2 );
	        elementPosition.y = sizeY - bottomBar.h;
        }
        // =============================================
        // Check collision against top bar
        // =============================================
        if(elementPosition.y < (topBar.y + topBar.h)) {
            elementPosition.x = ( sizeX / 2 ) - ( elementPosition.w / 2 );
	        elementPosition.y = sizeY - bottomBar.h;
        }
        // =============================================
        // Render section
        // =============================================
        // Clear the window
        SDL_RenderClear(renderer);
        
        // Set first color
        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
        // Render top and bottom bar
        SDL_RenderFillRect( renderer, &bottomBar );
	    SDL_RenderFillRect( renderer, &topBar );
        SDL_SetRenderDrawColor(renderer, 255, 207, 0, 255);
        
        // Render our element
        SDL_RenderFillRect(renderer, &elementPosition);
        SDL_SetRenderDrawColor(renderer, 198, 24, 0, 255);
        // Render our no controller element
        for(const auto &p : npc) {
            SDL_RenderFillRect(renderer, &p.position);
        }
        SDL_SetRenderDrawColor(renderer, 49, 182, 57, 255);
        // Render change 
        SDL_RenderPresent(renderer);
		
        // Add a 16msec delay to make our game run at ~60 fps, wait before next frame
        SDL_Delay( 16 );
	}
    return 0;
}
bool checkCollision(const SDL_Rect &rect1, const SDL_Rect &rect2) {
    // Find edges of rect1
    int left1 = rect1.x;
    int right1 = rect1.x + rect1.w;
    int top1 = rect1.y;
    int bottom1 = rect1.y + rect1.h;
    
    // Find edges of rect2
    int left2 = rect2.x;
    int right2 = rect2.x + rect2.w;
    int top2 = rect2.y;
    int bottom2 = rect2.y + rect2.h;
    
    // =============================================
    // Check edges
    // =============================================
    // Left 1 is right of right 2
	if(left1 > right2) {
        // No collision
		return false; 
    }
    // Right 1 is left of left 2
	if(right1 < left2) {
        // No collision 
		return false; 
    }
    // Top 1 is below bottom 2
	if(top1 > bottom2) {
        // No collision 
		return false; 
    }
    // Bottom 1 is above top 2
	if(bottom1 < top2) {
        // No collision  
		return false; 
    }
	return true;
}
bool checkNPCCollisions() {
    for(const auto &p: npc) {
        if(checkCollision(p.position, elementPosition)) {
            return true;
        }
    }
}
*/

// ==========================================================
// SDL - Part 7 Bitmaps, Blitting and Textures
// ==========================================================
/*
int main(int argc, char* args[])
{
    int posX = 900;
    int posY = 300;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;

 
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

    SDL_Surface *tempSurface = SDL_LoadBMP("assets/spacedragon.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

    destinationRectangle.x = sourceRectangle.x = 0;
    destinationRectangle.y = sourceRectangle.y = 0;
    destinationRectangle.w = sourceRectangle.w;
    destinationRectangle.h = sourceRectangle.h;

    bool loop = true;

    while(loop) {
        
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        std::cout << "Goodbye, shut it down..." <<  std::endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        SDL_Quit();
                        break;
					default :
						break;
				}
			}
		}

        // =============================================
        // Render section
        // =============================================
        // Clear the window
        SDL_RenderClear(renderer);
        
        // Set first color
        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);

        SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);

        SDL_RenderPresent(renderer);
		
        // Add a 16msec delay to make our game run at ~60 fps, wait before next frame
        SDL_Delay( 16 );
	}

    return 0;
}
*/
//-- Bitmaps
// Bitmap is just an image stored in a format where pixel data is represented by a block of memory, or a map of bits. The "bmp" format denotes an image where the color values of each pixel (monochrome, RGB, RGBA, etc) are simply stored sequentially after a header. Other formats such as "png" and "jpg" are still a from of bitmap, but make use of compression technologies to reduce file size (ideally) without sacrificing image quality.

//-- SDL_Surface & SDL_LoadBPM
// `SDL_Surface` is used for holding the raw texture data. A surface can represent a loaded bitmap, a new texture you're creating, or even the window you're drawing to. To load a bitmap into a surface, use the function `SDL_LoadBMP()`. `SDL_LoadBMP` this function accept the file we want to load as parameter and the return value is the loaded image as a `SDL_Surface` otherwise they return null.

//-- Convert SDL_Surface to SDL_Texture
// We not gonna use the SDL_Surface, we want a SDL_Texture to get it we need to use `SDL_CreateTextureFromSurface`, this function accept renderer and surface as parameter and return SDL Texture otherwise return null. We can used another function with the first one called `SDL_Surface` this function accept surface as parameter and is  used to delete and free memory from the past surface used.

//-- Getting the images on screen
// 

// ==========================================================
// SDL - Part 8 Animations
// ==========================================================
/*
int main(int argc, char* args[])
{
    int posX = 900;
    int posY = 300;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
 
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
    SDL_Surface *tempSurface = SDL_LoadBMP("assets/run.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);
    destinationRectangle.x = sourceRectangle.x = 0;
    destinationRectangle.y = sourceRectangle.y = 0;
    destinationRectangle.w = sourceRectangle.w = 108; // 432 / 4
    destinationRectangle.h = sourceRectangle.h = 140;
    bool loop = true;
    while(loop) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        std::cout << "Goodbye, shut it down..." <<  std::endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        SDL_Quit();
                        break;
                    case SDLK_RIGHT:
                        if(sourceRectangle.x > 280 && sourceRectangle.y == 0) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 140;
                        }
                        else if(sourceRectangle.x > 280 && sourceRectangle.y == 140) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 0;
                        }
                        else {
                            sourceRectangle.x += 108;
                        }
						break;
					default :
						break;
				}
			}
		}
        // =============================================
        // Render section
        // =============================================
        // Clear the window
        SDL_RenderClear(renderer);
        
        // Set first color
        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
        SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);
        SDL_RenderPresent(renderer);
		
        // Add a 16msec delay to make our game run at ~60 fps, wait before next frame
        SDL_Delay( 16 );
	}
    return 0;
}
*/

// ==========================================================
// SDL - Part 9 Animations Flipping Images
// ==========================================================
int main(int argc, char* args[])
{
    int posX = 900;
    int posY = 300;
    int sizeX = 300;
    int sizeY = 400;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
 
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
    SDL_Surface *tempSurface = SDL_LoadBMP("assets/run.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);
    destinationRectangle.x = sourceRectangle.x = 0;
    destinationRectangle.y = sourceRectangle.y = 0;
    destinationRectangle.w = sourceRectangle.w = 108; // 432 / 4
    destinationRectangle.h = sourceRectangle.h = 140;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    bool loop = true;
    while(loop) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
			    loop = false;
            }
			else if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        std::cout << "Goodbye, shut it down..." <<  std::endl;
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        SDL_Quit();
                        break;
                    case SDLK_RIGHT:
                        flipType = SDL_FLIP_NONE;
                        if(sourceRectangle.x > 280 && sourceRectangle.y == 0) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 140;
                        }
                        else if(sourceRectangle.x > 280 && sourceRectangle.y == 140) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 0;
                        }
                        else {
                            sourceRectangle.x += 108;
                        }
						break;
                    case SDLK_LEFT:
                        flipType = SDL_FLIP_HORIZONTAL;
                        if(sourceRectangle.x > 280 && sourceRectangle.y == 0) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 140;
                        }
                        else if(sourceRectangle.x > 280 && sourceRectangle.y == 140) {
                            sourceRectangle.x = 0;
                            sourceRectangle.y = 0;
                        }
                        else {
                            sourceRectangle.x += 108;
                        }
						break;
					default :
						break;
				}
			}
		}
        // =============================================
        // Render section
        // =============================================
        // Clear the window
        SDL_RenderClear(renderer);
        
        // Set first color
        SDL_SetRenderDrawColor(renderer, 72, 133, 237, 255);
        SDL_RenderCopyEx(renderer, texture, &sourceRectangle, &destinationRectangle, 0, 0, flipType);
        SDL_RenderPresent(renderer);
		
        // Add a 16msec delay to make our game run at ~60 fps, wait before next frame
        SDL_Delay( 16 );
	}
    return 0;
}
