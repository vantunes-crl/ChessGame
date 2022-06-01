#include "GUI.hpp"

GUI::GUI(int width, int height)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Chess Game");
}

/* Fill the table with blocks of black and white */
void GUI::FillTableColors()
{
    std::array<std::array<sf::RectangleShape, 8>, 8> Boxes;
    std::array<std::array<int, 8>, 8> ColorTable;

    for (auto i = 0; i < 8 ; ++i)
    {
        if (i % 2)
            ColorTable[i] = {0, 1, 0, 1, 0, 1, 0, 1};
        else
            ColorTable[i] = {1, 0, 1, 0, 1, 0, 1, 0};
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Boxes[i][j].setSize(sf::Vector2f((_window->getSize().x / 8), (_window->getSize().y / 8)));
            if (ColorTable[i][j])
                Boxes[i][j].setFillColor(sf::Color::White);
            else
                Boxes[i][j].setFillColor(sf::Color::Black);
            Boxes[i][j].setPosition(i * (_window->getSize().x / 8), j * (_window->getSize().y / 8));
            _window->draw(Boxes[i][j]);
        }
    }
}

/* Main loop */
void GUI::start()
{
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }   
        _window->clear();
        FillTableColors();
        _window->display();
    }
}