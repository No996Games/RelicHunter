//
// Created by yu qiu on 15/1/21.
//

#ifndef RELICHUNTER_GLENTITY_H
#define RELICHUNTER_GLENTITY_H

#include "Tools.h"
#include <string.h>
class GLEntity{
private:
    unsigned int VAO_ID,VBO,EBO;
    Texture* text;
public:
    GLEntity(float Xpos,float Ypos, float width, float height,std::string imagePath){

        float vertices[] = {
                // positions                                                            // texture coords
                (Xpos+width)/SCR_WIDTH * 2 -1,    (Ypos+height)/SCR_HEIGHT* 2 -1, 0.0f,      1.0f, 1.0f, // top right
                (Xpos+width)/SCR_WIDTH* 2 -1,    Ypos/SCR_HEIGHT* 2 -1,         0.0f,      1.0f, 0.0f, // bottom right
                Xpos/SCR_WIDTH* 2 -1,           Ypos/SCR_HEIGHT* 2 -1,         0.0f,      0.0f, 0.0f, // bottom left
                Xpos/SCR_WIDTH* 2 -1,           (Ypos+height)/SCR_HEIGHT* 2 -1, 0.0f,      0.0f, 1.0f  // top left
        };

        unsigned int indices[] = {
                0, 1, 3, // first triangle
                1, 2, 3  // second triangle
        };

        glGenVertexArrays(1, &(this->VAO_ID));
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(this->VAO_ID);

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
        text = new Texture(imagePath);
    }
    void draw(){
        glBindVertexArray(this->VAO_ID);
        text->draw();
    }
    unsigned int get_VAO(){
        return VAO_ID;
    }
    ~GLEntity(){
        glDeleteVertexArrays(1, &VAO_ID);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }

};

#endif //RELICHUNTER_GLENTITY_H

