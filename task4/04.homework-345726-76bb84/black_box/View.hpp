#pragma once
#include "../Point.hpp"

class View {
  public:
    View(const Point& viewPoint, double screenWidth, double screenHeight,
         double scale);
    void onZoom(double step);
    Point toScreen(const Point& worldPos) const;
    double scale() const;

  private:
    double zoomValue;
    Point viewPoint;
    double screenWidth;
    double screenHeight;
    double scale_;
};
