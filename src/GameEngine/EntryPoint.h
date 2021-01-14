//
// Created by Yuchen Shen on 8/1/21.
//
// 用来加载并进入游戏引擎
#ifndef RELICHUNTER_ENTRYPOINT_H
#define RELICHUNTER_ENTRYPOINT_H
#include "Tools.h"
#include "View/InputHandlers/KeyBoardHandler.h"

#include "View/Texture.h"
#include "View/glShader/Shader.h"
#include "View/common/Cursor.h"
#include "Tools.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int run()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        GE_CORE_ERROR("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("../resources/Transform.vs", "../resources/Transform.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
            // positions            // texture coords
            1.0f,  1.0f, 0.0f,     1.0f, 1.0f, // top right
            1.0f,-1.0f, 0.0f,      1.0f, 0.0f, // bottom right
            -1.0f, -1.0f, 0.0f,     0.0f, 0.0f, // bottom left
            -1.0f,  1.0f, 0.0f,      0.0f, 1.0f  // top left
    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



    // load and create a texture
    // -------------------------
    Texture t2 = Texture("../resources/pic/awesomeface.png");
    Texture t1 = Texture("../resources/pic/rain.jpeg");

    ourShader.use();
    ourShader.setInt("texture1",0);
    ourShader.setInt("texture2", 1);

    Cursor cursor(window, "../resources/pic/cursor.png");
    cursor.use();
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        // bind Texture
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, t1.getId());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, t2.getId());

        // create transformations
        glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        unsigned int transformLoc = glGetUniformLocation(ourShader.getId(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
#endif //RELICHUNTER_ENTRYPOINT_H
