#pragma once

#include "../../vector/vec4.h"

#include <iostream>

namespace bum {
    class mat4 {
    public:
        vec4 matrix[4]{0.0f, 0.0f, 0.0f, 0.0f};

        mat4(float x0, float y0, float z0, float w0,
             float x1, float y1, float z1, float w1,
             float x2, float y2, float z2, float w2,
             float x3, float y3, float z3, float w3);
        mat4(bum::vec4 vector0,
             bum::vec4 vector1,
             bum::vec4 vector2,
             bum::vec4 vector3);
        mat4(bum::vec4 *vector);
        mat4(float value);

        // Matrix-matrix addition & subtraction
        void add(mat4 &otherMatrix);
        void subtract(mat4 &otherMatrix);

        // Matrix-scalar multiplication
        void multiply(float scalar);
    };

    // Matrix-matrix addition & subtraction
    mat4 add(const mat4 &matrix, const mat4 &otherMatrix);
    mat4 subtract(const mat4 &matrix, const mat4 &otherMatrix);

    // Matrix-scalar multiplication
    mat4 multiply(const mat4 &matrix, float scalar);

    // Matrix-matrix multiplication
    mat4 multiply(const mat4 &matrix, const mat4 &otherMatrix);

    // Operator overloading
    mat4 operator+(const mat4 &matrix, const mat4 &otherMatrix);
    mat4 operator-(const mat4 &matrix, const mat4 &otherMatrix);
    mat4 operator*(const mat4 &matrix, float scalar);
    mat4 operator*(const mat4 &matrix, const mat4 &otherMatrix);
}

// Overload operator to print "mat4" with "std::cout", uses overloaded
// function from "vec4" class since a "mat4" is combination of 4 "vec4"s
std::ostream &operator<<(std::ostream &ostream, const bum::mat4 &matrix);