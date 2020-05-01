#include "mat4.h"

/* 4x4 matrix :
 * x0, y0, z0, w0
 * x1, y1, z1, w1
 * x2, y2, z2, w2
 * x3, y3, z3, w3
 */

namespace bum {
    mat4::mat4(float x0, float y0, float z0, float w0,
               float x1, float y1, float z1, float w1,
               float x2, float y2, float z2, float w2,
               float x3, float y3, float z3, float w3) {
        matrix[0].x = x0;
        matrix[0].y = y0;
        matrix[0].z = z0;
        matrix[0].w = w0;
        matrix[1].x = x1;
        matrix[1].y = y1;
        matrix[1].z = z1;
        matrix[1].w = w2;
        matrix[2].x = x2;
        matrix[2].y = y2;
        matrix[2].z = z2;
        matrix[2].w = w2;
        matrix[3].x = x3;
        matrix[3].y = y3;
        matrix[3].z = z3;
        matrix[3].w = w3;
    }

    mat4::mat4(bum::vec4 vector0, bum::vec4 vector1, bum::vec4 vector2, bum::vec4 vector3) {
        matrix[0].x = vector0.x;
        matrix[0].y = vector0.y;
        matrix[0].z = vector0.z;
        matrix[0].w = vector0.w;
        matrix[1].x = vector1.x;
        matrix[1].y = vector1.y;
        matrix[1].z = vector1.z;
        matrix[1].w = vector1.w;
        matrix[2].x = vector2.x;
        matrix[2].y = vector2.y;
        matrix[2].z = vector2.z;
        matrix[2].w = vector2.w;
        matrix[3].x = vector3.x;
        matrix[3].y = vector3.y;
        matrix[3].z = vector3.z;
        matrix[3].w = vector3.w;
    }

    mat4::mat4(bum::vec4 *vector) {
        for (int i = 0; i < 4; i++) {
            matrix[i].x = vector[i].x;
            matrix[i].y = vector[i].y;
            matrix[i].z = vector[i].z;
            matrix[i].w = vector[i].w;
        }
    }

    mat4::mat4(float value) {
        matrix[0].x = value;
        matrix[1].y = value;
        matrix[2].z = value;
        matrix[3].w = value;
    }

    // Matrix-matrix addition & subtraction
    void mat4::add(mat4 &otherMatrix) {
        for (int i = 0; i < 4; i++) {
            this->matrix[i].x += otherMatrix.matrix[i].x;
            this->matrix[i].y += otherMatrix.matrix[i].y;
            this->matrix[i].z += otherMatrix.matrix[i].z;
            this->matrix[i].w += otherMatrix.matrix[i].w;
        }
    }

    void mat4::subtract(mat4 &otherMatrix) {
        for (int i = 0; i < 4; i++) {
            this->matrix[i].x -= otherMatrix.matrix[i].x;
            this->matrix[i].y -= otherMatrix.matrix[i].y;
            this->matrix[i].z -= otherMatrix.matrix[i].z;
            this->matrix[i].w -= otherMatrix.matrix[i].w;
        }
    }

    // Matrix-scalar multiplication
    void mat4::multiply(float scalar) {
        for (vec4 &i : this->matrix) {
            i.x *= scalar;
            i.y *= scalar;
            i.z *= scalar;
            i.w *= scalar;
        }
    }

    // Matrix-matrix addition & subtraction
    mat4 add(const mat4 &matrix, const mat4 &otherMatrix) {
        vec4 resultMatrix[4]{0.0f};
        for (int i = 0; i < 4; i++) {
            resultMatrix[i].x = matrix.matrix[i].x + otherMatrix.matrix[i].x;
            resultMatrix[i].y = matrix.matrix[i].y + otherMatrix.matrix[i].y;
            resultMatrix[i].z = matrix.matrix[i].z + otherMatrix.matrix[i].z;
            resultMatrix[i].w = matrix.matrix[i].w + otherMatrix.matrix[i].w;
        }
        return mat4{resultMatrix};
    }

    mat4 subtract(const mat4 &matrix, const mat4 &otherMatrix) {
        vec4 resultMatrix[4]{0.0f};
        for (int i = 0; i < 4; i++) {
            resultMatrix[i].x = matrix.matrix[i].x - otherMatrix.matrix[i].x;
            resultMatrix[i].y = matrix.matrix[i].y - otherMatrix.matrix[i].y;
            resultMatrix[i].z = matrix.matrix[i].z - otherMatrix.matrix[i].z;
            resultMatrix[i].w = matrix.matrix[i].w - otherMatrix.matrix[i].w;
        }
        return mat4{resultMatrix};
    }

    // Matrix-scalar multiplication
    mat4 multiply(const mat4 &matrix, float scalar) {
        vec4 resultMatrix[4]{0.0f};
        for (int i = 0; i < 4; i++) {
            resultMatrix[i].x = matrix.matrix[i].x * scalar;
            resultMatrix[i].y = matrix.matrix[i].y * scalar;
            resultMatrix[i].z = matrix.matrix[i].z * scalar;
            resultMatrix[i].w = matrix.matrix[i].w * scalar;
        }
        return mat4{resultMatrix};
    }

    // Matrix-matrix multiplication
    mat4 multiply(const mat4 &matrix, const mat4 &otherMatrix) {
        vec4 resultMatrix[4]{0.0f};
        for (int i = 0; i < 4; i++) {
            resultMatrix[i].x = matrix.matrix[i].x * otherMatrix.matrix[0].x +
                                matrix.matrix[i].y * otherMatrix.matrix[1].x +
                                matrix.matrix[i].z * otherMatrix.matrix[2].x +
                                matrix.matrix[i].w * otherMatrix.matrix[3].x;
            resultMatrix[i].y = matrix.matrix[i].x * otherMatrix.matrix[0].y +
                                matrix.matrix[i].y * otherMatrix.matrix[1].y +
                                matrix.matrix[i].z * otherMatrix.matrix[2].y +
                                matrix.matrix[i].w * otherMatrix.matrix[3].y;
            resultMatrix[i].z = matrix.matrix[i].x * otherMatrix.matrix[0].z +
                                matrix.matrix[i].y * otherMatrix.matrix[1].z +
                                matrix.matrix[i].z * otherMatrix.matrix[2].z +
                                matrix.matrix[i].w * otherMatrix.matrix[3].z;
            resultMatrix[i].w = matrix.matrix[i].x * otherMatrix.matrix[0].w +
                                matrix.matrix[i].y * otherMatrix.matrix[1].w +
                                matrix.matrix[i].z * otherMatrix.matrix[2].w +
                                matrix.matrix[i].w * otherMatrix.matrix[3].w;
        }
        return mat4{resultMatrix};
    }

    // Operator overloading
    mat4 operator+(const mat4 &matrix, const mat4 &otherMatrix) {
        return add(matrix, otherMatrix);
    }

    mat4 operator-(const mat4 &matrix, const mat4 &otherMatrix) {
        return subtract(matrix, otherMatrix);
    }

    mat4 operator*(const mat4 &matrix, float scalar) {
        return multiply(matrix, scalar);
    }

    mat4 operator*(const mat4 &matrix, const mat4 &otherMatrix) {
        return multiply(matrix, otherMatrix);
    }
}

// Overload operator to print "mat4" with "std::cout", uses overloaded
// function from "vec4" class since a "mat4" is combination of 4 "vec4"s
std::ostream &operator<<(std::ostream &ostream, const bum::mat4 &matrix) {
    using namespace std;    // Didn't fit on to my screen, so had to do it :)
    ostream << matrix.matrix[0] << endl << matrix.matrix[1] << endl << matrix.matrix[2] << endl << matrix.matrix[3];
    return ostream;
}
