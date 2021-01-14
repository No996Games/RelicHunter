//
// Created by Yuchen Shen on 8/1/21.
//
// 用来加在并进入游戏引擎
#ifndef RELICHUNTER_ENTRYPOINT_H
#define RELICHUNTER_ENTRYPOINT_H
#include "Tools.h"
#include "View/InputHandlers/InputHandler.h"

#include "View/Texture.h"
#include "View/glShader/Shader.h"
#include "View/common/Cursor.h"
#include "Tools.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "View/common/GLEntity.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

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
    GLEntity entity(0,0,1440,900);

    // load and create a texture
    // -------------------------
    Texture t2 = Texture("../resources/pic/awesomeface.png");
    Texture t1 = Texture("../resources/pic/rain.jpeg");

    ourShader.use();
    ourShader.setInt("texture1",0);
    ourShader.setInt("texture2", 1);

    Cursor cursor(window, "../resources/pic/cursor.png");
    cursor.use();
    glfwSetCursorPosCallback(window,processMouseInput);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        processKeyInput(window);
        // bind Texture
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, t1.getId());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, t2.getId());

        // create transformations
        glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

        transform = glm::translate(transform, glm::vec3(0.f, 0.f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime()*0, glm::vec3(0.0f, 0.0f, 1.0f));

        unsigned int transformLoc = glGetUniformLocation(ourShader.getId(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // render container
        ourShader.use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
#endif //RELICHUNTER_ENTRYPOINT_H
