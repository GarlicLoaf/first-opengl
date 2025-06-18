#include <iostream>
#include <fstream>
#include <iterator>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "glm/fwd.hpp"

#include "primitives.h"
#include "shape_data.h"

int check_status(GLuint object_id, PFNGLGETSHADERIVPROC object_property_getter,
                 PFNGLGETSHADERINFOLOGPROC get_info_log_func,
                 GLenum status_type) {
    GLint status;
    object_property_getter(object_id, status_type, &status);
    if (status != GL_TRUE) {
        GLint info_log_length;
        object_property_getter(object_id, GL_INFO_LOG_LENGTH, &info_log_length);
        GLchar* buffer = new GLchar[info_log_length];

        GLsizei bufferSize;
        get_info_log_func(object_id, info_log_length, &bufferSize, buffer);
        std::cout << buffer << "\n";

        delete[] buffer;
        return 0;
    }
    return 1;
}

int check_shader_status(GLuint shader_id) {
    return check_status(shader_id, glGetShaderiv, glGetShaderInfoLog,
                        GL_COMPILE_STATUS);
}

int check_program_status(GLuint program_id) {
    return check_status(program_id, glGetProgramiv, glGetProgramInfoLog,
                        GL_LINK_STATUS);
}

std::string read_shader_code(const char* file_name) {
    std::ifstream input(file_name);
    if (!input.good()) {
        std::cout << "File failed to load: " << file_name;
        exit(1);
    }
    return std::string(std::istreambuf_iterator<char>(input),
                       std::istreambuf_iterator<char>());
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* window_setup() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window =
        glfwCreateWindow(800, 600, "First Project", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << "\n";
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void send_data() {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    ShapeData tri = make_triangle();

    GLuint vertex_buffer_id;
    glGenBuffers(1, &vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, tri.vertices.size() * sizeof(Vertex),
                 tri.vertices.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (char*)(3 * sizeof(float)));

    GLuint index_buffer_id;
    glGenBuffers(1, &index_buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, tri.indices.size() * sizeof(GLushort),
                 tri.indices.data(), GL_STATIC_DRAW);
}

void install_shaders() {
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* adapter[1];
    std::string temp = read_shader_code("../src/vertex_shader_code.glsl");
    adapter[0] = temp.c_str();
    glShaderSource(vertex_shader_id, 1, adapter, 0);
    temp = read_shader_code("../src/fragment_shader_code.glsl");
    adapter[0] = temp.c_str();
    glShaderSource(fragment_shader_id, 1, adapter, 0);

    glCompileShader(vertex_shader_id);
    glCompileShader(fragment_shader_id);

    if (!(check_shader_status(vertex_shader_id) &&
          check_shader_status(fragment_shader_id))) {
        return;
    }

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);

    if (!check_program_status(program_id)) {
        return;
    }

    glUseProgram(program_id);
}

int main() {
    GLFWwindow* window = window_setup();
    glEnable(GL_DEPTH_TEST);
    send_data();
    install_shaders();

    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // rendering
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
