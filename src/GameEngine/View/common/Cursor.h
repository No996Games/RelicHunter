//
// Created by Yuchen Shen on 14/1/21.
//

#ifndef RELICHUNTER_CURSOR_H
#define RELICHUNTER_CURSOR_H
#include "Tools.h"
#include <string>
class Cursor{
private:
    GLFWcursor* cursor = nullptr;
    GLFWwindow* window = nullptr;
public:
    Cursor(GLFWwindow* window, std::string imagePath){
        int width,height,nrChannels;
        unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
        GLFWimage image;
        image.width = width;
        image.height = height;
        image.pixels = data;
        cursor = glfwCreateCursor(&image, 0, 0);
        this->window = window;
    }
    ~Cursor() {
        glfwDestroyCursor(cursor);
    }

    void use(){
        glfwSetCursor(window, cursor);
    }
};

#endif //RELICHUNTER_CURSOR_H
