#include "shape_data.h"
#include <GL/gl.h>
#include <glm/glm.hpp>

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

ShapeData make_triangle() {
    ShapeData out;

    out.vertices = {
        {glm::vec3(+0.0f, +1.0f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f)},
        {glm::vec3(-1.0f, -1.0f, +0.0f), glm::vec3(+0.0f, +1.0f, +0.0f)},
        {glm::vec3(+1.0f, -1.0f, +0.0f), glm::vec3(+0.0f, +0.0f, +1.0f)},
    };

    out.indices = {0, 1, 2};

    return out;
}

ShapeData make_cube() {
    ShapeData out;

    out.vertices = {
        // Top face
        {glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+1.0f, +0.0f, +0.0f)},
        {glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+0.0f, +1.0f, +0.0f)},
        {glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f)},
        {glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+1.0f, +1.0f, +1.0f)},

        // Front face
        {glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+1.0f, +0.0f, +1.0f)},
        {glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.0f, +0.5f, +0.2f)},
        {glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.8f, +0.6f, +0.4f)},
        {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.3f, +1.0f, +0.5f)},

        // Right face
        {glm::vec3(+1.0f, +1.0f, -1.0f), glm::vec3(+0.2f, +0.5f, +0.2f)},
        {glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+0.9f, +0.3f, +0.7f)},
        {glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.3f, +0.7f, +0.5f)},
        {glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.5f)},

        // Left face
        {glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.7f, +0.8f, +0.2f)},
        {glm::vec3(-1.0f, +1.0f, -1.0f), glm::vec3(+0.5f, +0.7f, +0.3f)},
        {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.4f, +0.7f, +0.7f)},
        {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.2f, +0.5f, +1.0f)},

        // Back face
        {glm::vec3(+1.0f, +1.0f, +1.0f), glm::vec3(+0.6f, +1.0f, +0.7f)},
        {glm::vec3(-1.0f, +1.0f, +1.0f), glm::vec3(+0.6f, +0.4f, +0.8f)},
        {glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.2f, +0.8f, +0.7f)},
        {glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.2f, +0.7f, +1.0f)},

        // Bottom face
        {glm::vec3(+1.0f, -1.0f, -1.0f), glm::vec3(+0.8f, +0.3f, +0.7f)},
        {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(+0.8f, +0.9f, +0.5f)},
        {glm::vec3(-1.0f, -1.0f, +1.0f), glm::vec3(+0.5f, +0.8f, +0.5f)},
        {glm::vec3(+1.0f, -1.0f, +1.0f), glm::vec3(+0.9f, +1.0f, +0.2f)},
    };

    out.indices = {
        0,  1,  2,  0,  2,  3,   // Top
        4,  5,  6,  4,  6,  7,   // Front
        8,  9,  10, 8,  10, 11,  // Right
        12, 13, 14, 12, 14, 15,  // Left
        16, 17, 18, 16, 18, 19,  // Back
        20, 22, 21, 20, 23, 22   // Bottom
    };

    return out;
}
