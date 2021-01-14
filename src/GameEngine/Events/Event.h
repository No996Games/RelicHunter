//
// Created by Chuyang Zhou on 1/5/2021.
//

#ifndef RELICHUNTER_EVENT_H
#define RELICHUNTER_EVENT_H


#include <functional>
#include "Core.h"

#define BIT(x) (1 << x)


// Currently do not have Events buffer (will be added in the future)
namespace GE {

    /* Enum Class does not allow implicit conversion to int */
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
        ApplicationEvent    = BIT(0),   // 0
        InputEvent          = BIT(1),   // 10
        KeyboardEvent       = BIT(2),   // 100
        MouseEvent          = BIT(3),   // 1000
        MouseButtonEvent    = BIT(4)    // 10000
    };


    /** Base class for all events
     * */
    class Event {
        friend class EventDispatcher;

    public:
        bool Handeled = false;

        virtual EventCategory GetCategory() const = 0;
        virtual EventType GetType() const = 0;
        virtual std::string GetName() const = 0;

        bool IsInCategory(EventCategory category) {
            return category & GetCategory();
        }

    };

#define SET_EVENT_TYPE(type) 



    class EventDispatcher {
        /* TODO: Finish the dispatcher */
    };

}


#endif //RELICHUNTER_EVENT_H
