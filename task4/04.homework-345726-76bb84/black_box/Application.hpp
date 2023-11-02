#pragma once
#include "View.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <chrono>
#include <memory>

class World;

class Application {
  public:
    Application(const char* name);
    void run(World& world);

  private:
    void processEvents();
    void updateWorld(World& world);
    void drawWorld(const World& world);

  private:
    sf::RenderWindow window;
    View view;
    std::chrono::system_clock::time_point time;
    double totalTime{};
};
