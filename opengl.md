# OpenGl

OpenGL is mainly considered an API (an Application Programming Interface) that provides us with a large set of functions that we can use to manipulate graphics and images. However, OpenGL by itself is not an API, but merely a specification, developed and maintained by the Khronos Group.

The OpenGL specification specifies exactly what the result/output of each function should be and how it should perform. It is then up to the developers implementing this specification to come up with a solution of how this function should operate. Since the OpenGL specification does not give us implementation details, the actual developed versions of OpenGL are allowed to have different implementations, as long as their results comply with the specification (and are thus the same to the user).

The people developing the actual OpenGL libraries are usually the graphics card manufacturers. Each graphics card that you buy supports specific versions of OpenGL which are the versions of OpenGL developed specifically for that card (series).

When using an Apple system the OpenGL library is maintained by Apple themselves and under Linux there exists a combination of graphic suppliers' versions and hobbyists' adaptations of these libraries. This also means that whenever OpenGL is showing weird behavior that it shouldn't, this is most likely the fault of the graphics cards manufacturers (or whoever developed/maintained the library).

## GLEW

OpenGL loading, OpenGL is an API specification, not a library. This means that the actual implementation behind the API varies based on your GPU hardware, operating system and your installed graphics driver.

GLEW (OpenGL Extension Wrangler) is a cross-platform library that declares and loads OpenGL functions for you. It also has handy run-time checks to see whether a given machine supports a given OpenGL profile (a profile is a guarantee that a given configuration supports a certain set of OpenGL functions).

## GLFW

GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop. It provides a simple API for creating windows, contexts and surfaces, receiving input and events.

```
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, char** argv)
{
    // Initialise GLFW
    if(!glfwInit())
    {
        printf("GLFW initialisation failed!");
        glfwTerminate();
        return 1;
    }

    /* Setup GLFW window properties */

    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // Core profile, no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if(!mainWindow)
    {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLFW to use
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension feature
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Loop until window closed
    while(!glfwWindowShouldClose(mainWindow))
    {
        // Get handler user input
        glfwPollEvents();

        // Clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}
```
