#pragma once

#include <string>
#include <vector>

// Forward declarations to reduce header dependencies
struct GLFWwindow;

namespace SourceEngine {

    // === Engine Lifecycle ===
    void InitEngine();                                      // Initializes the engine (GLFW, etc.)
    void InitWindow(const std::string& title, int width, int height); // Creates the GLFW window
    void Terminate();                                       // Cleans up and shuts down the engine
    void PrintEngineInfo();                                 // Logs OpenGL version and engine info

    // === Rendering ===
    void ClearScreen();     // Clears the frame
    void SwapBuffers();     // Swaps window buffers and polls events

    // === 3D Model Loading ===
    struct ObjModel {
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> texcoords;
        std::vector<unsigned int> indices;
    };

    // Loads an .obj model using tinyobjloader
    bool LoadObjModel(const std::string& filename, ObjModel& model, std::string& err);

    // === Internal Access ===
    extern GLFWwindow* window; // Global pointer to the GLFW window
}
