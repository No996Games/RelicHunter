//
// Created by Yuchen Shen on 8/1/21.
//

#ifndef RELICHUNTER_KEYBOARDHANDLER_H
#define RELICHUNTER_KEYBOARDHANDLER_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window,GLFW_KEY_0) == GLFW_PRESS) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

#endif //RELICHUNTER_KEYBOARDHANDLER_H
