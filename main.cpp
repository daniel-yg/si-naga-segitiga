#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Dragon.hpp"

#include <iostream>
using namespace std;

const GLsizei SCREEN_WIDTH = 800;
const GLsizei SCREEN_HEIGHT = 800;

/* This Vertex Shader will convert a (0 -- 800) to (-1.0 -- 1.0) coordinate system */
/* (0,0) located on top left, standardized with paint coordinates */
const char* vertexShaderSource = 
"#version 440 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform vec2 size;\n"
"\n"
"void main() {\n"
    "gl_Position = vec4((aPos.x-(size.x/2))/(size.x/2), (-aPos.y+(size.y/2))/(size.y/2), aPos.z, 1.0);\n"
"}\n";

const char* fragmentShaderSource = 
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";

int main(void)
{

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
    
    /* Create and compile fragment shader */
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    /* Create the program */
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        cout <<"Oh no program doesn't work: \n" << infoLog << endl;
    }

    /* Clean Up */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    /* Triangle Creation */
    float vertices[] = {
        100.0f, 100.0f, 0.0f,
        200.0f, 200.0f, 0.0f,
        100.0f, 200.0f, 0.0f
    };
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dragonHeadVertices), dragonHeadVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dragonHeadIndices), dragonHeadIndices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);

    
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    /* Pass screen size to shader */
    GLint screenSizeAddr = glGetUniformLocation(shaderProgram, "size");
    glUniform2f(screenSizeAddr, SCREEN_WIDTH, SCREEN_HEIGHT);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
       
        glDrawElements(GL_TRIANGLES,9,GL_UNSIGNED_INT,0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    printf("%s",glGetString(GL_VERSION));
    glfwTerminate();
    return 0;
}
