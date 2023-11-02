#include "View.hpp"
#include <algorithm>
#include <cmath>

inline constexpr double maxZoom = 60.;
inline constexpr double initialZoom = 20;
inline constexpr double zoomCoef = 0.01;
inline constexpr double minScale = 0.005;

View::View(const Point& viewPoint, double screenWidth, double screenHeight,
           double scale)
    : zoomValue{initialZoom}, viewPoint{viewPoint}, screenWidth{screenWidth},
      screenHeight{screenHeight}, scale_{scale} {
    onZoom(0.);
}

Point View::toScreen(const Point& worldPos) const {
    // Не самая эффективная, но тривиальная реализация
    // перехода от мировых координат к экранным

    // clang-format off
    Point screenPos =
        // Смещаем worldPos относительно наблюдаемой точки
        (worldPos - viewPoint)
        // масштабируем
        * scale_
        // и центруем на экране
        // (чтобы наблюдаемая точка оказалась в центре)
        + Point(screenWidth / 2., screenHeight / 2);
    // clang-format on

    // инвертируем ось y
    screenPos.y = screenHeight - screenPos.y;
    return screenPos;
}

void View::onZoom(double step) {
    zoomValue = std::clamp(zoomValue + step, 1., maxZoom);
    scale_ = std::exp(zoomValue * zoomCoef) - 1. + minScale;
}

double View::scale() const {
    return scale_;
}
