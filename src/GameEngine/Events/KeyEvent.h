//
// Created by Chuyang Zhou on 1/5/2021.
//

#ifndef RELICHUNTER_KEYEVENT_H
#define RELICHUNTER_KEYEVENT_H

#include "KeyCode.h"
#include "Event.h"

namespace GE {

    class KeyEvent : public Event {
    public:
        KeyCode keycode;

        KeyEvent(KeyCode keycode) {
            this->keycode = keycode;
        }
    };


}




#endif //RELICHUNTER_KEYEVENT_H
