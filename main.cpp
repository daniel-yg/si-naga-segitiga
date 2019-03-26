#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Dragon.hpp"

#include <array>
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
"uniform vec4 objectColor;\n"
"\n"
"void main()\n"
"{\n"
"    FragColor = objectColor;\n"
"}\n";

unsigned int shaderProgram;

//outputs a shader program that has compiled the shaders
void compileShaders();

// sets up the objects to draw
// TODO: trim out the unrequired args (potentially such as VBO)
void setup(array<GLuint, 4> &VAO, array<GLuint, 4> &VBO, array<GLuint, 4> &EBO);
void setupDragonHead(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO);
void setupDragonBody(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO);
void setupDragonWings(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO);
void setupDragonTail(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO);

void render(array<GLuint, 4> &VAO);
void renderDragonHead(unsigned int &VAO);
void renderDragonBody(unsigned int &VAO);
void renderDragonWings(unsigned int &VAO);
void renderDragonTail(unsigned int &VAO);


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
    
    
    compileShaders();

    array<GLuint, 4> VAO;
    array<GLuint, 4> VBO;
    array<GLuint, 4> EBO;

    setup(VAO,VBO,EBO);
    
    glUseProgram(shaderProgram);
    
    /* Pass uniform variables to shaders */
    GLint screenSizeAddr = glGetUniformLocation(shaderProgram, "size");
    glUniform2f(screenSizeAddr, SCREEN_WIDTH, SCREEN_HEIGHT);

    
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        render(VAO);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    printf("%s",glGetString(GL_VERSION));
    glfwTerminate();
    return 0;
} /* int main(void) */


void compileShaders() {
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
}

void setup(array<GLuint, 4> &VAO, array<GLuint, 4> &VBO, array<GLuint, 4> &EBO) {

    //Initialization
    glGenVertexArrays(4, &VAO[0]); 
    glGenBuffers(4, &VBO[0]);
    glGenBuffers(4, &EBO[0]);

    // Set up the objects here
    setupDragonHead(VAO[DRAGON_HEAD], VBO[DRAGON_HEAD], EBO[DRAGON_HEAD]);
    setupDragonBody(VAO[DRAGON_BODY], VBO[DRAGON_BODY], EBO[DRAGON_BODY]);
    setupDragonWings(VAO[DRAGON_WINGS], VBO[DRAGON_WINGS], EBO[DRAGON_WINGS]);
    setupDragonTail(VAO[DRAGON_TAIL], VBO[DRAGON_TAIL], EBO[DRAGON_TAIL]);
    

    // Unbinding
    glBindBuffer(GL_ARRAY_BUFFER, 0); 


    glBindVertexArray(0);
}

void setupDragonHead(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dragonHeadVertices), dragonHeadVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dragonHeadIndices), dragonHeadIndices, GL_STATIC_DRAW);

    // Setting Vertex Attributes
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    // glBindVertexArray(0);
}

void setupDragonBody(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dragonBodyVertices), dragonBodyVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dragonBodyIndices), dragonBodyIndices, GL_STATIC_DRAW);

    // Setting Vertex Attributes
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0);
}

void setupDragonWings(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dragonWingsVertices), dragonWingsVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dragonWingsIndices), dragonWingsIndices, GL_STATIC_DRAW);

    // Setting Vertex Attributes
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
}

void setupDragonTail(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dragonTailVertices), dragonTailVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dragonTailIndices), dragonTailIndices, GL_STATIC_DRAW);

    // Setting Vertex Attributes
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
}


void render(array <GLuint, 4> &VAO) {
    renderDragonHead(VAO[DRAGON_HEAD]);
    renderDragonBody(VAO[DRAGON_BODY]);
    renderDragonWings(VAO[DRAGON_WINGS]);
    renderDragonTail(VAO[DRAGON_TAIL]);
    
}
void renderDragonHead(unsigned int &VAO) {
    glBindVertexArray(VAO);
    GLint objectColorAddr = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform4f(objectColorAddr, 0.0f, 1.0f, 1.0f, 1.0f);
    glDrawElements(GL_TRIANGLES,sizeof(dragonHeadIndices)/sizeof(int),GL_UNSIGNED_INT,0);
}

void renderDragonBody(unsigned int &VAO) {
    glBindVertexArray(VAO);
    GLint objectColorAddr = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform4f(objectColorAddr, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawElements(GL_TRIANGLES,sizeof(dragonBodyIndices)/sizeof(int),GL_UNSIGNED_INT,0);
}

void renderDragonWings(unsigned int &VAO) {
    glBindVertexArray(VAO);
    GLint objectColorAddr = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform4f(objectColorAddr, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawElements(GL_TRIANGLES,sizeof(dragonWingsIndices)/sizeof(int),GL_UNSIGNED_INT,0);
}

void renderDragonTail(unsigned int &VAO) {
    glBindVertexArray(VAO);
    GLint objectColorAddr = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform4f(objectColorAddr, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawElements(GL_TRIANGLES,sizeof(dragonTailIndices)/sizeof(int),GL_UNSIGNED_INT,0);
}