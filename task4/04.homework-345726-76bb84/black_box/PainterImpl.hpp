#pragma once
#include "../Color.hpp"
#include "View.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace sf {
    class RenderWindow;
}

class PainterImpl {
  public:
    PainterImpl(sf::RenderWindow& window, const View& view);
    ~PainterImpl();
    void draw(const Point& center, double radius, const Color& color);
    void draw(const Point& topLeft, const Point& bottomRight,
              const Color& color);

  private:
    sf::Color toSFMLColor(const Color& color) const;
    sf::Vector2f toVector(const Point& point) const;

  private:
    sf::RenderWindow& window;

    const View& view;
};
