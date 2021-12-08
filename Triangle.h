// Copyright [2021] <Charles baxter>

#ifndef TRIANGLE_H  //NOLINT
#define TRIANGLE_H  //NOLINT

#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
 public:
    Triangle(sf::Vector2<double> center, float r);
    void rotate(float angle);
    void setOutlineColor(sf::Color color);
 private:
    virtual void draw(sf::RenderTarget& target,  //NOLINT
        sf::RenderStates states) const;
    sf::CircleShape tri;
};

#endif  //NOLINT