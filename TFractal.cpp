// Copyright [2021] <Charles baxter>

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Triangle.h"

void fTree(int n, double l, sf::Vector2<double> center,
    std::vector<Triangle>& vec);  //NOLINT

void zoomAt(sf::RenderWindow& window,  //NOLINT
    sf::Vector2i pixel, double zoom);

int main(int argc, char* argv[]) {
    double L = stod(std::string{ argv[1] });
    int N = stoi(std::string{ argv[2] });

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(3 * L, 3 * L),
        "Sierpinski Fractal", sf::Style::Default, settings);

    std::vector<Triangle> triangles;

    fTree(N, L, { window.getSize().x / 2.0,
        window.getSize().y / 2.0 }, triangles);

    sf::Color colors[] = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::White,
        sf::Color::Cyan,
        sf::Color::Yellow
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseWheelScrolled:
                zoomAt(window, { event.mouseWheelScroll.x,
                    event.mouseWheelScroll.y },
                    (1.0 - event.mouseWheelScroll.delta / 10.0));
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::O:
                    for (uint16_t i = 0; i < triangles.size(); i++)
                        triangles[i].rotate(-5.f);
                    break;
                case sf::Keyboard::P:
                    for (uint16_t i = 0; i < triangles.size(); i++)
                        triangles[i].rotate(5.f);
                    break;
                case sf::Keyboard::Q:
                    for (uint16_t i = 0; i < triangles.size(); i++) {
                        triangles[i].setOutlineColor(colors[i % 6]);
                    }
                    break;
                case sf::Keyboard::W:
                    for (uint16_t i = 0; i < triangles.size(); i++) {
                        triangles[i].setOutlineColor(sf::Color::White);
                    }
                    break;
                default:
                    break;
                }
            default:
                break;
            }
        }



        window.clear();

        for (uint16_t i = 0; i < triangles.size(); i++)
            window.draw(triangles[i]);

        window.display();
    }

    std::cout << sizeof(triangles) / 8 << std::endl;

    return 0;
}

void fTree(int n, double l, sf::Vector2<double> center,
    std::vector<Triangle>& vec) {  //NOLINT
    if (n > 0) {
        double d = l / (2 * sqrt(3));
        double r = l / sqrt(3);

        // create this triangle object
        vec.push_back(Triangle(center, r));

        // recurve on first triangle (top-left)
        fTree(n - 1, l / 2, { center.x - (l / 2),
            center.y - d - (r / 2) }, vec);
        // recurve on second triangle (top-right)
        fTree(n - 1, l / 2, { center.x + (3 * l / 4),
            center.y - (d / 2) }, vec);
        // recurve on third triangle (bottom)
        fTree(n - 1, l / 2, { center.x - (l / 4),
            center.y + r + (d / 2) }, vec);
    }
}

void zoomAt(sf::RenderWindow& window,  //NOLINT
    sf::Vector2i pixel, double zoom) {
    const sf::Vector2f initCoords(window.mapPixelToCoords(pixel));
    sf::View view(window.getView());
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f newCoords(window.mapPixelToCoords(pixel));
    const sf::Vector2f offsetCoords(initCoords - newCoords);
    view.move(offsetCoords);
    window.setView(view);
}
