#pragma once

#include <glad/glad.h>
#include <vector>
#include "primitives.h"

struct ShapeData {
    std::vector<Vertex> vertices;
    std::vector<GLushort> indices;
};

ShapeData make_triangle();
ShapeData make_cube();
