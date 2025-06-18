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
