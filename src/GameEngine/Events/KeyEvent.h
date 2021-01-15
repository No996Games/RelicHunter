//
// Created by Chuyang Zhou on 1/5/2021.
//

#ifndef RELICHUNTER_KEYEVENT_H
#define RELICHUNTER_KEYEVENT_H

//#include "KeyCode.h"
#include "Event.h"

namespace GE {

    using KeyCode = int16_t;

    class KeyEvent : public Event {
    public:
        KeyEvent(KeyCode keycode) {
            this->keycode = keycode;
        }

        KeyCode GetKeyCode() const {
            return this->keycode;
        }

        SET_EVENT_CATEGORY(KeyboardEvent);
        SET_EVENT_CATEGORY(InputEvent);

    protected:
        KeyCode keycode;
    };

    class KeyPressEvent : public KeyEvent {

    };
}




#endif //RELICHUNTER_KEYEVENT_H
