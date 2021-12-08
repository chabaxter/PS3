// Copyright [2021] <Charles baxter>

#include "Triangle.h"

Triangle::Triangle(sf::Vector2<double> center, float r) : tri(r, 3) {
    tri.setOrigin(r, r);
    tri.move(center.x, center.y);
    tri.rotate(180);

    tri.setFillColor(sf::Color(0, 0, 0, 0));
    tri.setOutlineColor(sf::Color::White);
    tri.setOutlineThickness(-1);
}

void Triangle::rotate(float angle) {
    tri.rotate(angle);
}

void Triangle::setOutlineColor(sf::Color color) {
    tri.setOutlineColor(color);
}

void Triangle::draw(sf::RenderTarget& target,  //NOLINT
    sf::RenderStates states) const {
    target.draw(tri);
}
