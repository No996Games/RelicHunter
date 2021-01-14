//
// Created by Yuchen Shen on 12/1/21.
//

#ifndef RELICHUNTER_TEXTURE_H
#define RELICHUNTER_TEXTURE_H

#include <glad/glad.h>
#include <string>
#include <stb_image.h>
#include <iostream>
#include "../Log.h"
class Texture {
private:
    unsigned int textureId;

public:
    Texture(std::string filePath){
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

        if (data)
        {
            GLenum format;
            if(nrChannels == 1){
                format = GL_RED;
            }else if(nrChannels == 3){
                format = GL_RGB;
            }else if(nrChannels == 4){
                format = GL_RGBA;
            }
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }

    unsigned int getId(){
        return textureId;
    }
    void draw(){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
};


#endif //RELICHUNTER_TEXTURE_H
