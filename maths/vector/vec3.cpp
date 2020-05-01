#include "vec3.h"

namespace bum {
    vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    vec3::vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
    vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}

    // Vector negation
    void vec3::negate() {
        this->x *= -1;
        this->y *= -1;
        this->z *= -1;
    }

    // Vector length
    float vec3::length() const {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    // Vector normalization (unit vector)
    vec3 vec3::normalize() const {
        float length = this->length();
        // TO DO : Handle "0 / 0" division
        return vec3{this->x / length,
                    this->y / length,
                    this->z / length};
    }

    // Vector-scalar operations
    void vec3::add(float scalar) {
        this->x += scalar;
        this->y += scalar;
        this->z += scalar;
    }

    void vec3::subtract(float scalar) {
        this->x -= scalar;
        this->y -= scalar;
        this->z -= scalar;
    }

    void vec3::multiply(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
    }

    void vec3::divide(float scalar) {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
    }

    // Vector-vector addition & subtraction
    void vec3::add(const vec3 &otherVector) {
        this->x += otherVector.x;
        this->y += otherVector.y;
        this->z += otherVector.z;
    }

    void vec3::subtract(const vec3 &otherVector) {
        this->x -= otherVector.x;
        this->y -= otherVector.y;
        this->z -= otherVector.z;
    }

    // Vector-scalar operations (returns a new "vec3")
    vec3 add(const vec3 &vector, float scalar) {
        return vec3{vector.x + scalar,
                    vector.y + scalar,
                    vector.z + scalar};
    }

    vec3 subtract(const vec3 &vector, float scalar) {
        return vec3{vector.x - scalar,
                    vector.y - scalar,
                    vector.z - scalar};
    }

    vec3 multiply(const vec3 &vector, float scalar) {
        return vec3{vector.x * scalar,
                    vector.y * scalar,
                    vector.z * scalar};
    }

    vec3 divide(const vec3 &vector, float scalar) {
        // TO DO : Handle "0 / 0" division
        return vec3{vector.x / scalar,
                    vector.y / scalar,
                    vector.z / scalar};
    }

    // Vector-vector addition & subtraction (returns a new "vec3")
    vec3 add(const vec3 &vector, const vec3 &otherVector) {
        return vec3{vector.x + otherVector.x,
                    vector.y + otherVector.y,
                    vector.z + otherVector.z,};
    }

    vec3 subtract(const vec3 &vector, const vec3 &otherVector) {
        return vec3{vector.x - otherVector.x,
                    vector.y - otherVector.y,
                    vector.z - otherVector.z,};
    }

    // Vector-vector multiplication (dot product & cross product)
    float dot(const vec3 &vector, const vec3 &otherVector) {
        // TO DO : Create a new function or rework this method to let user to give normalized vectors
        vec3 vectorN = vector.normalize();
        vec3 otherVectorN = otherVector.normalize();
        return vectorN.x * otherVectorN.x + vectorN.y * otherVectorN.y + vectorN.z * otherVectorN.z;
    }

    vec3 cross(const vec3 &vector, const vec3 &otherVector) {
        return vec3{vector.y * otherVector.z - vector.z * otherVector.y,
                    vector.z * otherVector.x - vector.x * otherVector.z,
                    vector.x * otherVector.y - vector.y * otherVector.x};
    }

    // Operator overloading
    vec3 operator+(const vec3 &vector, const float &scalar) {
        return add(vector, scalar);
    }

    vec3 operator-(const vec3 &vector, const float &scalar) {
        return subtract(vector, scalar);
    }

    vec3 operator*(const vec3 &vector, const float &scalar) {
        return multiply(vector, scalar);
    }

    vec3 operator/(const vec3 &vector, const float &scalar) {
        return divide(vector, scalar);
    }

    vec3 operator+(const vec3 &vector, const vec3 &otherVector) {
        return add(vector, otherVector);
    }

    vec3 operator-(const vec3 &vector, const vec3 &otherVector) {
        return subtract(vector, otherVector);
    }
}

// Overload operator to print "vec3" with "std::cout"
std::ostream &operator<<(std::ostream &ostream, const bum::vec3 &vector) {
    ostream << vector.x << ", " << vector.y << ", " << vector.z;
    return ostream;
}