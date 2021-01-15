//
// Created by Chuyang Zhou on 15/1/21.
//

#ifndef RELICHUNTER_KEYCODE_H
#define RELICHUNTER_KEYCODE_H

#include <cstdint>

namespace GE {


    using KeyCode = uint16_t;

    namespace Key {
        enum : KeyCode {
            Space = 32,
            Tab   = 258,
            Left_shift = 340,
            Left_ctrl  = 341,

            N0  =  48,
            N1  =  49,
            N2  =  50,
            N3  =  51,
            N4  =  52,
            N5  =  53,
            N6  =  54,
            N7  =  55,
            N8  =  56,
            N9  =  57,

            A   = 65,
            B   = 66,
            C   = 67,
            D   = 68,
            E   = 69,
            F   = 70,
            G   = 71,
            H   = 72,
            I   = 73,
            J   = 74,
            K   = 75,
            L   = 76,
            M   = 77,
            N   = 78,
            O   = 79,
            P   = 80,
            Q   = 81,
            R   = 82,
            S   = 83,
            T   = 84,
            U   = 85,
            V   = 86,
            W   = 87,
            X   = 88,
            Y   = 89,
            Z   = 90,
        };
    }
}



#endif //RELICHUNTER_KEYCODE_H
