//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_SETTING_H
#define RELICHUNTER_SETTING_H
class Setting{
private:
    int SCREENWIDTH;
    int SCREENHEIGHT;
    static Setting set;
    Setting(){
    }
public:
    static void setScreen(int width,int height){
        set.SCREENHEIGHT = height;
        set.SCREENWIDTH = width;
    }
    static int getScreenWidth(){
        return set.SCREENWIDTH;
    }
    static int getScreenHeight(){
        return set.SCREENHEIGHT;
    }
};
#endif //RELICHUNTER_SETTING_H
