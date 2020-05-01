#pragma once

#include <iostream>
#include <cmath>

// TO DO : Return the angle from dot product (angle between 2 unit vectors)
/*
 * Angle in degrees = angle in radians * 180.0 / PI
 * Angle in radians = angle in degrees * PI / 180.0
 */

namespace bum {
    class vec3 {
    public:
        float x, y, z;

        vec3(float x, float y, float z);
        vec3(float xyz);
        vec3();

        // Vector negation
        void negate();

        // Vector length
        float length() const;

        // Vector normalization (unit vector)
        vec3 normalize() const;

        // Vector-scalar operations :
        void add(float scalar);
        void subtract(float scalar);
        void multiply(float scalar);
        void divide(float scalar);

        // Vector-vector addition & subtraction
        void add(const vec3 &otherVector);
        void subtract(const vec3 &otherVector);
    };

    // Vector-scalar operations (returns a new "vec3") :
    vec3 add(const vec3 &vector, float scalar);
    vec3 subtract(const vec3 &vector, float scalar);
    vec3 multiply(const vec3 &vector, float scalar);
    vec3 divide(const vec3 &vector, float scalar);

    // Vector-vector addition & subtraction (returns a new "vec3") :
    vec3 add(const vec3 &vector, const vec3 &otherVector);
    vec3 subtract(const vec3 &vector, const vec3 &otherVector);

    // Vector-vector multiplication (dot product & cross product) :
    float dot(const vec3 &vector, const vec3 &otherVector);
    vec3 cross(const vec3 &vector, const vec3 &otherVector);

    // Operator overloading
    vec3 operator+(const vec3 &vector, const float &scalar);
    vec3 operator-(const vec3 &vector, const float &scalar);
    vec3 operator*(const vec3 &vector, const float &scalar);
    vec3 operator/(const vec3 &vector, const float &scalar);
    vec3 operator+(const vec3 &vector, const vec3 &otherVector);
    vec3 operator-(const vec3 &vector, const vec3 &otherVector);
}

// Overload operator to print "vec3" with "std::cout"
std::ostream &operator<<(std::ostream &ostream, const bum::vec3 &vector);