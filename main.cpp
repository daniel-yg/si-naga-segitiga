#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

const char* vertexShaderSource = 
"#version 440 core\n\
layout (location = 0) in vec3 aPos;\n\
\n\
void main() {\n\
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n\
}";

int main(void)
{
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    // unsigned int VBO;
    // glGenBuffers(1, &VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Init Glew */
    GLenum err = glewInit();
    
    /* Create and Compile vertex shader */
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    } else 
    {
        cout << "Vertex Shader Compilation Successful" << endl;
    }
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    printf("%s",glGetString(GL_VERSION));
    glfwTerminate();
    return 0;
}
