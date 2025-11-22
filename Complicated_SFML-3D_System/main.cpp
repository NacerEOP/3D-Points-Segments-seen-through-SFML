#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Classes/point.h"
#include "Classes/parcours.h"

// Helper: degrees → radians
float degToRad(float deg) { return deg * 3.14159f / 180.f; }

// 3D → 2D simple projection
sf::Vector2f project3D(const sf::Vector3f& p3, float camYaw, float camPitch, float camDist, float screenW, float screenH) {
    float cosy = std::cos(degToRad(camYaw));
    float siny = std::sin(degToRad(camYaw));

    float xz = p3.x * cosy - p3.z * siny;
    float zz = p3.x * siny + p3.z * cosy;

    float cosp = std::cos(degToRad(camPitch));
    float sinp = std::sin(degToRad(camPitch));

    float yz = p3.y * cosp - zz * sinp;
    float zz2 = p3.y * sinp + zz * cosp;

    float f = camDist / (camDist + zz2);
    return {screenW/2 + xz*f, screenH/2 - yz*f};
}

int main() {
    // -----------------------------
    // SFML 3.x window
    // -----------------------------
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "3D Viewport");
    window.setFramerateLimit(60);

    // -----------------------------
    // Create simple 3D cube points
    // -----------------------------
    std::vector<CLpoint3D> points;
    
    float size = 120.0f;
    
    // Front face
    points.emplace_back(-size, -size, -size); // 0: bottom left front
    points.emplace_back(size, -size, -size);  // 1: bottom right front  
    points.emplace_back(size, size, -size);   // 2: top right front
    points.emplace_back(-size, size, -size);  // 3: top left front
    
    // Back face
    points.emplace_back(-size, -size, size);  // 4: bottom left back
    points.emplace_back(size, -size, size);   // 5: bottom right back
    points.emplace_back(size, size, size);    // 6: top right back
    points.emplace_back(-size, size, size);   // 7: top left back

    // -----------------------------
    // Define cube connections
    // -----------------------------
    std::vector<std::pair<int, int>> connections;
    
    // Front face
    connections.emplace_back(0, 1);
    connections.emplace_back(1, 2);
    connections.emplace_back(2, 3);
    connections.emplace_back(3, 0);
    
    // Back face
    connections.emplace_back(4, 5);
    connections.emplace_back(5, 6);
    connections.emplace_back(6, 7);
    connections.emplace_back(7, 4);
    
    // Connecting lines
    connections.emplace_back(0, 4);
    connections.emplace_back(1, 5);
    connections.emplace_back(2, 6);
    connections.emplace_back(3, 7);

    // -----------------------------
    // Camera
    // -----------------------------
    float camYaw = 45.f;
    float camPitch = 30.f;
    float camDist = 400.f;

    bool dragging = false;
    sf::Vector2i lastPos;

    // -----------------------------
    // Main loop
    // -----------------------------
    while (window.isOpen()) {
        // SFML 3.x: New event handling pattern
        while (auto event = window.pollEvent()) {
            // Check event type using is()
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    dragging = true;
                    lastPos = sf::Mouse::getPosition(window);
                }
            }
            else if (auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseReleased->button == sf::Mouse::Button::Left) {
                    dragging = false;
                }
            }
            else if (auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
                if (dragging) {
                    sf::Vector2i pos = {mouseMoved->position.x, mouseMoved->position.y};
                    camYaw += (pos.x - lastPos.x) * 0.5f;
                    camPitch += (pos.y - lastPos.y) * 0.5f;
                    if (camPitch > 89) camPitch = 89;
                    if (camPitch < -89) camPitch = -89;
                    lastPos = pos;
                }
            }
            else if (auto* mouseWheel = event->getIf<sf::Event::MouseWheelScrolled>()) {
                camDist -= mouseWheel->delta * 20.f;
                if (camDist < 200) camDist = 200;
                if (camDist > 1000) camDist = 1000;
            }
        }

        window.clear(sf::Color(20, 20, 20));

        // Draw points
        for (auto& p : points) {
            sf::Vector3f p3(p.getX(), p.getY(), p.getZ());
            sf::Vector2f p2 = project3D(p3, camYaw, camPitch, camDist,
                                         (float)window.getSize().x, (float)window.getSize().y);

            sf::CircleShape dot(4.f);
            dot.setFillColor(sf::Color::Yellow);
            dot.setPosition({p2.x-4.f, p2.y-4.f});
            window.draw(dot);
        }

        // Draw lines
        for (auto& conn : connections) {
            sf::Vector2f a = project3D({points[conn.first].getX(), points[conn.first].getY(), points[conn.first].getZ()},
                                      camYaw, camPitch, camDist,
                                      (float)window.getSize().x, (float)window.getSize().y);

            sf::Vector2f b = project3D({points[conn.second].getX(), points[conn.second].getY(), points[conn.second].getZ()},
                                      camYaw, camPitch, camDist,
                                      (float)window.getSize().x, (float)window.getSize().y);

            // Create vertices
            std::array<sf::Vertex, 2> vertices;
            vertices[0].position = a;
            vertices[0].color = sf::Color::Cyan;
            vertices[1].position = b;
            vertices[1].color = sf::Color::Cyan;
            
            window.draw(vertices.data(), vertices.size(), sf::PrimitiveType::Lines);
        }

        window.display();
    }

    return 0;
}