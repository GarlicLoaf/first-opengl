#version 330

layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aColor;

uniform mat4 transformMatrix;

out vec3 vColor;

void main() {
    gl_Position = transformMatrix * vec4(aPos, 1.0);
    vColor = aColor;
}
