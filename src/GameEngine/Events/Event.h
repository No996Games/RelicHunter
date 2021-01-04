//
// Created by Chuyang Zhou on 1/5/2021.
//

#ifndef RELICHUNTER_EVENT_H
#define RELICHUNTER_EVENT_H

#include <string>
#include <functional>
#include "Core.h"


// Currently do not have Events buffer (will be added in the future)
namespace GE {

    enum class EventType {
        None = 0,
        /*---------Application Events--------*/
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        /* Following are all input events */
        /*---------Keyboard Events-----------*/
        KeyPressed,
        KeyReleased,
        /*---------MouseButton Events--------*/
        MouseButtonPressed,
        MouseButtonReleased,
        /*---------Mouse Events--------------*/
        MouseMoved,
        MouseScrolled
    };

    /* Some times we may only care about the event type */
    enum EventCategory {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

}



#endif //RELICHUNTER_EVENT_H
