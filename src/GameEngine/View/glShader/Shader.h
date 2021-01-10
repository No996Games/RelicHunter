//
// Created by Yuchen Shen on 9/1/21.
//

#ifndef RELICHUNTER_SHADER_H
#define RELICHUNTER_SHADER_H
#include <glad/glad.h> // include glad to get the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
private:
    unsigned int ID;
public:
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};
#endif //RELICHUNTER_SHADER_H
