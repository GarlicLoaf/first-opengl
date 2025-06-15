#version 330

in layout(location=0) vec3 aPos;
in layout(location=1) vec3 aColor;

out vec3 vColor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    vColor = aColor;
}
