# 3D Wireframe System with SFML

A C++ project that demonstrates 3D wireframe visualization using SFML. This repository contains two main components: a simple class testing system and an advanced 3D visualization system that pushes SFML to its limits for 3D rendering.

##  Features

- **3D Point Management**: Custom `CLpoint3D` class for handling 3D coordinates
- **Wireframe Rendering**: Real-time 3D to 2D projection and rendering
- **Interactive Camera**: Mouse-controlled rotation and zoom
- **Multiple 3D Shapes**: Cube, geometric star, and custom wireframe models
- **SFML 3.x Compatibility**: Uses the latest SFML 3.0.2 with modern C++ standards

##  Requirements

- **Compiler**: GCC 14.2.0+ (MinGW-w64)
- **SFML**: 3.0.2
- **C++ Standard**: C++17

##  Installation & Compilation

1. **Clone the repository**
2. **Ensure SFML 3.0.2 is installed** in your system
3. **Compile the project** using:

```powershell
g++ main.cpp Classes/point.cpp Classes/parcours.cpp -o program.exe -I"path/to/SFML/include" -L"path/to/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system -std=c++17
```

##  Usage

Run the compiled executable to launch the 3D wireframe viewer:

- **Mouse Drag**: Rotate the 3D camera
- **Mouse Wheel**: Zoom in/out
- **Real-time Rendering**: Watch as SFML renders 3D wireframes in real-time

##  Technical Details

This project showcases how to use SFML's 2D rendering capabilities to create 3D visualizations through:
- Custom 3D projection mathematics
- Vertex-based line rendering
- Efficient point and connection management
- Modern SFML 3.x event handling

##  Educational Value

Perfect for learning:
- 3D graphics programming concepts
- SFML advanced usage patterns
- Object-oriented design with C++
- Mathematical projections and transformations

Experience the power of SFML pushed beyond its typical 2D boundaries into the realm of 3D wireframe visualization!
