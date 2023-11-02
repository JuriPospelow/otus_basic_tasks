#include "Painter.hpp"
#include "black_box/PainterImpl.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Painter::Painter(sf::RenderWindow& window, const View& view)
    : impl{new PainterImpl(window, view)} {}

Painter::~Painter() = default;

void Painter::draw(const Point& center, double radius, const Color& color) {
    impl->draw(center, radius, color);
}

void Painter::draw(const Point& topLeft, const Point& bottomRight,
                   const Color& color) {
    impl->draw(topLeft, bottomRight, color);
}
