//-- Legacy OpenGL
/*
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if(!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Legacy OpenGL", NULL, NULL);
    if(!window) {
        // GLFW window creation failed!
        glfwTerminate();
        return -1;
    }

    // Make the window context current
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        cout << "Error!" << endl;
    }

    // Loop until the user closes the window
    while(!glfwWindowShouldClose(window)) {
        
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
*/

//-- Modern OpenGL
// We want to transform legacy to modern OpenGL

//-- Foundation of Modern OpenGL
// Vertex buffer is the data to draw triangle and shader execute and draw that triangle on the gpu.
// Vertex Buffer - Is an array of memory, or a simple buffer. Is a array of memory to place binary in there.
// Shader - Is a program on the gpu, is code that only run on the gpu.
// OpenGL behave as State Machine

//-- Init Moderns OpenGL
/*
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if(!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Moderns OpenGL", NULL, NULL);
    if(!window) {
        // GLFW window creation failed!
        glfwTerminate();
        return -1;
    }

    // Make the window context current
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        cout << "Error!" << endl;
    }

    // Define ours buffer
    // Generate a buffer and return back his ID, to OpenGL identify that buffer and used.
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Select that buffer, first param, porpuse of using and second param buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // Define the data of the buffer, first params, type of that data, second param how big
    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);


    // Loop until the user closes the window
    while(!glfwWindowShouldClose(window)) {
        
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // We need shader to display triangle, otherwise, will display none.
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
*/

//-- Vertex attributes
// If for define the layouts of ours vertices. Vertex is just a point.
/*
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
    GLFWwindow* window;

    if(!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Moderns OpenGL", NULL, NULL);
    if(!window) {
        // GLFW window creation failed!
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        cout << "Error!" << endl;
    }

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    // Vertex attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    while(!glfwWindowShouldClose(window)) {
        
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
*/
//-- Adding shaders
// vertex and fragment shader type are 90% more used shader on graphics.
// vertex shader, pourpose is to tell gpu where position on the screen we want to render specific each vertex. If we have three vertex, we call this 3 time.
// fragment or pixel shader, determine where to fill pixel inside of the figure we create and color.
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

// Function to compile shaders
static unsigned int CompileShader(unsigned int type, const string &source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << endl;
        cout << message << endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const string &vertexShader, const string &fragmentShader) {
    // Initialize program
    unsigned int program = glCreateProgram();

    // Shader objects or files
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    // Attach to the program
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    if(!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Moderns OpenGL", NULL, NULL);
    if(!window) {
        // GLFW window creation failed!
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        cout << "Error!" << endl;
    }

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    // Vertex attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // Writing shader
    string vertexShader = 
        // Version of GLSL
        "#version 330 core \n"
        "\n"
        "layout(location = 0) in vec4 position;"
        "\n"
        "void main()\n"
        "{\n"
        "gl_Position = position; \n"
        "} \n";

    string fragmentShader = 
        // Version of GLSL
        "#version 330 core \n"
        "\n"
        "layout(location = 0) out vec4 color;"
        "\n"
        "void main()\n"
        "{\n"
        "color = vec4(1.0, 0.0, 0.0, 1.0); \n"
        "} \n";
    
    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    while(!glfwWindowShouldClose(window)) {
        
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// If you dont provide shader, some GPU provide Shader for you on default. That why some GPU render the triangule without shader.

// Compile command pront
// g++ main.cpp -o main -std=c++11 -lGL -lglfw -lGLEW

