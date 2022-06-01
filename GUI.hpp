#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class GUI
{
private:
    std::shared_ptr<sf::RenderWindow> _window;
public:

    void start();
    void FillTableColors();

    GUI(int width, int height);
};


#endif