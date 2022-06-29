#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../table.hpp"
#include "../ChessPieces/Ichess_pieces.hpp"

class GUI
{
private:
    std::shared_ptr<sf::RenderWindow> _window;
public:

    void start(Ichess_pieces::Table_t &Table);

    void FillTableWithPieces(Ichess_pieces::Table_t &Table, std::array<sf::Texture, 12> &Textures);

    std::array<sf::Texture, 12> initTextures();

    GUI(int width, int height);
};


#endif