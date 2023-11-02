#pragma once
#include "Color.hpp"
#include "Point.hpp"
#include <memory>

class View;
class PainterImpl;

namespace sf {
    class RenderWindow;
}

class Painter {
  public:
    Painter(sf::RenderWindow& window, const View& view);
    ~Painter();
    /**
     * Рисует круг цвета color
     * @param center центр круга
     * @param radius радиус круга
     * @param color цвет заливки
     */
    void draw(const Point& center, double radius, const Color& color);
    /**
     * Рисует прямоугольник цвета color
     * @param topLeft координата верхнего левого угла
     * @param bottomRight координата нижнего правого угла
     * @param color цвет заливки
     */
    void draw(const Point& topLeft, const Point& bottomRight,
              const Color& color);

  private:
    std::unique_ptr<PainterImpl> impl;
};