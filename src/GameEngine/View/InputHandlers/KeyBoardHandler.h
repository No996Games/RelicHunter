//
// Created by Yuchen Shen on 8/1/21.
//

#ifndef RELICHUNTER_KEYBOARDHANDLER_H
#define RELICHUNTER_KEYBOARDHANDLER_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../../Log.h"
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window,GLFW_KEY_0) == GLFW_PRESS) {
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        GE_INFO("Change window colour");
    }
}

#endif //RELICHUNTER_KEYBOARDHANDLER_H
