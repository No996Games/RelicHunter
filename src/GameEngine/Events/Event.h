//
// Created by Chuyang Zhou on 1/5/2021.
//

#ifndef RELICHUNTER_EVENT_H
#define RELICHUNTER_EVENT_H


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
        EventCategoryApplication    = BIT(0),   // 0
        EventCategoryInput          = BIT(1),   // 10
        EventCategoryKeyboard       = BIT(2),   // 100
        EventCategoryMouse          = BIT(3),   // 1000
        EventCategoryMouseButton    = BIT(4)    // 10000
    };

    class Event {
        friend class EventDispatcher;

    public:
        virtual EventType GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName() };

        /* Check if the Event is in given category */
        inline bool InCategory(EventCategory category) {
            return GetCategoryFlags() & category;
        }

    protected:
        bool Handeled = false;
    };

    class EventDispatcher {

    };

}



#endif //RELICHUNTER_EVENT_H
