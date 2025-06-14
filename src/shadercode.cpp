const char* vertex_shader_code =
    "#version 330\r\n"
    ""
    "in layout(location=0) vec2 aPos;"
    "in layout(location=1) vec3 aColor;"
    ""
    "out vec3 vColor;"
    ""
    "void main() {"
    "gl_Position = vec4(aPos, 0.0, 1.0);"
    "vColor = aColor;"
    "}";

const char* fragment_shader_code =
    "#version 330\r\n"
    ""
    "in vec3 vColor;"
    "out vec4 FragColor;"
    ""
    "void main() {"
    "FragColor = vec4(vColor, 1.0);"
    "}";
