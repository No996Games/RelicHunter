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

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); }             \
    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
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
    private:
        Event& event;
    public:
        EventDispatcher(Event& e) : event(e) {}

        template<typename F, typename T>
        bool Dispatch(const F& func) {
            if (event.GetEventType() == T::GetStaticType()) {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }

        inline std::ostream& operator<<(std::ostream& os, const Event& e)
        {
            return os << e.ToString();
        }
    };

}


#endif //RELICHUNTER_EVENT_H
