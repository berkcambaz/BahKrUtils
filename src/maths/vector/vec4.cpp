#include "vec4.h"


namespace bum {
    vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    vec4::vec4(float xyzw) {
        x = xyzw;
        y = xyzw;
        z = xyzw;
        w = xyzw;
    }

    vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

}

// Overload operator to print "vec4" with "std::cout"
std::ostream &operator<<(std::ostream &ostream, const bum::vec4 &vector) {
    ostream << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w;
    return ostream;
}