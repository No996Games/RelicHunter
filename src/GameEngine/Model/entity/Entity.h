//
// Created by Yuchen Shen on 28/12/20.
//

#ifndef RELICHUNTER_ENTITY_H
#define RELICHUNTER_ENTITY_H

#include <string>
using namespace std;
class Entity {
public:
    Entity(double x,double y,double height,double width,string imagePath){
        this->height = height;
        this->width = width;
        this->x = x;
        this->y = y;
        this->imagePath = imagePath;
    }
    double getX(){
        return this->x;
    }
    double getY(){
        return this->y;
    }
    double getWidth(){
        return this->width;
    }
    double getHeight(){
        return this->height;
    }
    string getImagePath(){
        return imagePath;
    }
protected:
    double x;
    double y;
    double height;
    double width;
    string imagePath;
};



#endif //RELICHUNTER_ENTITY_H
