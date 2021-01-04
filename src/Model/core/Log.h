//
// Created by Yuchen Shen on 3/1/21.
//

#ifndef RELICHUNTER_LOG_H
#define RELICHUNTER_LOG_H
#define DEFAULT_LOGFILE "game.log"
#include <iostream>
#include <fstream>
class Log {
private:
    static Log* log;
    std::fstream stream;
public:
    static void init(){
        log = new Log();
        log->stream.open(DEFAULT_LOGFILE, std::fstream::in | std::fstream::out | std::fstream::trunc);
        log->stream<<"start logging";
        log->stream.flush();
    }
};


#endif //RELICHUNTER_LOG_H
