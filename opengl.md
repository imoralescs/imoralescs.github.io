# OpenGl

OpenGL is mainly considered an API (an Application Programming Interface) that provides us with a large set of functions that we can use to manipulate graphics and images. However, OpenGL by itself is not an API, but merely a specification, developed and maintained by the Khronos Group.

The OpenGL specification specifies exactly what the result/output of each function should be and how it should perform. It is then up to the developers implementing this specification to come up with a solution of how this function should operate. Since the OpenGL specification does not give us implementation details, the actual developed versions of OpenGL are allowed to have different implementations, as long as their results comply with the specification (and are thus the same to the user).

The people developing the actual OpenGL libraries are usually the graphics card manufacturers. Each graphics card that you buy supports specific versions of OpenGL which are the versions of OpenGL developed specifically for that card (series).

When using an Apple system the OpenGL library is maintained by Apple themselves and under Linux there exists a combination of graphic suppliers' versions and hobbyists' adaptations of these libraries. This also means that whenever OpenGL is showing weird behavior that it shouldn't, this is most likely the fault of the graphics cards manufacturers (or whoever developed/maintained the library).

## GLUT 

Stands for OpenGL utility toolkit, implemented it to enable the construction of OpenGL application that are truly window system independent. It provides a simplified API for window management as well as event handling, IO control and few other services. Alternatives to GLUT include SDL and GLFW.

## Example of using GLUT

```
#include <iostream>
#include <GL/glut.h>  

using namespace std;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();  
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("OpenGL Setup Test"); 
       
     
    glutDisplayFunc(display); 
    glutMainLoop();           
    return 0;
}
```

Compiling:

```
g++ main.cpp -o main -lGL -lGLU -lglut
```

Execution:

```
./main
```

## GLEW (For create OpenGL objects)

OpenGL loading, OpenGL is an API specification, not a library. This means that the actual implementation behind the API varies based on your GPU hardware, operating system and your installed graphics driver.

GLEW (OpenGL Extension Wrangler) is a cross-platform library that declares and loads OpenGL functions for you. It also has handy run-time checks to see whether a given machine supports a given OpenGL profile (a profile is a guarantee that a given configuration supports a certain set of OpenGL functions).

## GLFW (For create window and then draw to this window)

GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop. It provides a simple API for creating windows, contexts and surfaces, receiving input and events.

## Example of using GLFW

```
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
    GLFWwindow* window;

    // Initialize GLFW library
    if(!glfwInit()) {
        printf("GLFW initialisation failed!");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Creating window
    window = glfwCreateWindow(640, 480, "Test Window", NULL, NULL);
    if(!window) {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Set context for GLFW to use
    glfwMakeContextCurrent(window);

    // Loop until window closed
    while(!glfwWindowShouldClose(window)) {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
```

Compiling:

```
g++ main.cpp -o main -lGL -lglfw -lGLEW
```

Execution:

```
./main
```

### `glfwInit()`

This function is used for initialize GLFW.

### `glfwWindowHint(int hint, int value)`

After used `glfwInit()` we can configure GLFW using `glfwWindowHint()`. The first argument tell us what option we want to configure. The second argument is an integer that sets the values of our option.

### `glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow * share)`

This function help to create a window object. This window object holds all the windowing data. 

#### Arguments

* **width:** Desired window width. This must be greater than zero.
* **height:** Desired window height. This must be greater than zero.
* **title:** Window title
* **monitor:** The monitor to use for full screen, or NULL for windowed mode
* **share:** The window whose context to share resources with, or NULL to not share resources.

### `glfwTerminate()` 

This function destroys all remaining windows, frees any allocated resources and sets the library to an uninitialized state.

## Example of using GLEW and GLFW

```
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
    GLFWwindow* window;

    // Initialize GLFW library
    if(!glfwInit()) {
        printf("GLFW initialisation failed!");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Creating window
    window = glfwCreateWindow(640, 480, "Test Window", NULL, NULL);
    if(!window) {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Set context for GLFW to use
    glfwMakeContextCurrent(window);

    // Allow modern extension feature
    glewExperimental = GL_TRUE;

    // Initialize GLEW library
    if(glewInit() != GLEW_OK) {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // Window viewport
    int bufferWidth, bufferHeight;
    
    // Get buffer size information
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    // Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Loop until window closed
    while(!glfwWindowShouldClose(window)) {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
```

Compiling:

```
g++ main.cpp -o main -lGL -lglfw -lGLEW
```

Execution:

```
./main
```

### `glewExperimental`

We set this to true, for ensures GLEW used the more modern techniques for managing OpenGL functionality. Leaving it to its default value of `GL_FALSE` might give issues when using the core profile of OpenGL.

### `glewInit()`

This function is used for initialize GLEW.

### `glfwGetFramebufferSize()` and `glViewport(int x, int y, GLsizei width, GLsizei height)`

Before rendering, we have to tell OpenGL the size of the rendering window so OpenGL knows how we want to display the data and coordinates with respect to the window. 

We can set those dimensions via the `glViewport()` function. We also need to retrieve the size, in pixels, of the framebuffer of the specified window. We can do that via the `glfwGetFrameBufferSize()` function.

#### Arguments for `glViewport()`

* **x:** Specify the lower corner of the viewport rectangle, in pixels.
* **y:** Specify the lower corner of the viewport rectangle, in pixels.
* **width:** Specify the width and height of the viewport.
* **height:** Specify the width and height of the viewport.

### Game loop

We don't want the application to draw a single image and then immediately quit and close the window. We want the application to keep drawing images and handling user input until the program has been explicitly told to stop. For this reason we have to create a while loop, that we now call the game loop, that keeps on running until we tell GLFW to stop.

#### `glfwWindowShouldClose()`

This function takes one parameter (GLFW winodw). It return true if the window has been instructed to close and false if it hasn't been.

#### `glfwPollEvents()` 

This function checks if any events have been triggered(keyboard, mouse input...) and calls the corresponding function(the callback methods.
 
#### `glfwSwapBuffers` 

This function also takes one parameter (GLFW window). It will swap the color buffer (a large buffer that contains color values for each pixel in GLFW's window) that has been used to draw in during this iteration and show it as output to the screen.

### Adding color

We also want our window to have some color. At the start of each render iteration we always want to clear the screen otherwise we would still see the results from the previous iteration. 

We can clear the screen's color buffer using the `glClear()` function where we pass in buffer bits to specify which buffer we would like to clear. 

#### `glClearColor()`

This function takes four parameters, The amount of red, green and blue color where the minimal amount is 0.0 and the maximal amount is 1.0f and the alpha value.

## Graphics Pipeline


