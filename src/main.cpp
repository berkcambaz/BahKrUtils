#include <iostream>

#include "vector/vec3.h"
#include "matrix/mat4.h"

int main() {
    bum::vec4 vector[4]{1.0f, 1.0f, 1.0f, 1.0f};
    bum::mat4 player(1.0f);
    bum::mat4 otherPlayer(5.0f);
    std::cout << vector * otherPlayer * 0.525f;
    return 0;
}
