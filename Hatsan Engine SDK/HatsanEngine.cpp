#include "HatsanEngine.hpp"
#include "tiny_obj_loader.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

namespace HatsanEngine{

    // Internal GLFW window pointer
    GLFWwindow* window = nullptr;

    void PrintEngineInfo() {
        const GLubyte* version = glGetString(GL_VERSION);
        if (version) {
            std::cout << "OpenGL Version: " << version << std::endl;
        } else {
            std::cerr << "Failed to retrieve OpenGL version." << std::endl;
        }
    }

    void InitEngine() {
        if (!glfwInit()) {
            std::cerr << "Error: Failed to initialize GLFW." << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "GLFW initialized successfully." << std::endl;
    }

    void InitWindow(const std::string& title, int width, int height) {
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            std::cerr << "Error: Failed to create GLFW window." << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable VSync

        std::cout << "Window created: " << title << " (" << width << "x" << height << ")" << std::endl;
        PrintEngineInfo();
    }

    void ClearScreen() {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f); // Dark blue-gray background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void SwapBuffers() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Terminate() {
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
        glfwTerminate();
        std::cout << "Engine terminated." << std::endl;
    }

    bool LoadObjModel(const std::string& filename, ObjModel& model, std::string& err) {
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
        std::string warn;

        bool success = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename.c_str());
        if (!warn.empty()) std::cerr << "OBJ Warn: " << warn << std::endl;
        if (!err.empty())  std::cerr << "OBJ Error: " << err << std::endl;
        if (!success)      return false;

        for (const auto& shape : shapes) {
            for (const auto& index : shape.mesh.indices) {
                // Vertices
                model.vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
                model.vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
                model.vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

                // Normals
                if (!attrib.normals.empty() && index.normal_index >= 0) {
                    model.normals.push_back(attrib.normals[3 * index.normal_index + 0]);
                    model.normals.push_back(attrib.normals[3 * index.normal_index + 1]);
                    model.normals.push_back(attrib.normals[3 * index.normal_index + 2]);
                }

                // Texture Coordinates
                if (!attrib.texcoords.empty() && index.texcoord_index >= 0) {
                    model.texcoords.push_back(attrib.texcoords[2 * index.texcoord_index + 0]);
                    model.texcoords.push_back(attrib.texcoords[2 * index.texcoord_index + 1]);
                }

                model.indices.push_back(static_cast<unsigned int>(model.vertices.size() / 3 - 1));
            }
        }

        return true;
    }

} // namespace SourceEngine
