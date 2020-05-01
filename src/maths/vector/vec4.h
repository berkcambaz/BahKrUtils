#pragma once

#include <iostream>

namespace bum {
    class vec4 {
    public:
        float x, y, z, w;

        vec4(float x, float y, float z, float w);
        vec4(float xyzw);
        vec4();
    };
}

// Overload operator to print "vec4" with "std::cout"
std::ostream &operator<<(std::ostream &ostream, const bum::vec4 &vector);