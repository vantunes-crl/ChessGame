#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "table.hpp"
#include <algorithm>
#include <memory>

class main_game
{
private:
    std::shared_ptr<sf::RenderWindow> _window;
    table _table;
public:

    void start();
    void FillTableColors();


    main_game(int width, int height);
    ~main_game();
};


#endif