#include "main_game.hpp"

main_game::main_game(int width, int height)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Chess Game");
}

main_game::~main_game()
{
}

/* Fill the table with blocks of black and white */
void main_game::FillTableColors()
{
    std::array<std::array<sf::RectangleShape, 8>, 8> Boxes;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Boxes[i][j].setSize(sf::Vector2f((_window->getSize().x / 8), (_window->getSize().y / 8)));
            if (_table[i][j])
                Boxes[i][j].setFillColor(sf::Color::White);
            else
                Boxes[i][j].setFillColor(sf::Color::Black);
            Boxes[i][j].setPosition(i * (_window->getSize().x / 8), j * (_window->getSize().y / 8));
            _window->draw(Boxes[i][j]);
        }
    }
}

/* Main loop */
void main_game::start()
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