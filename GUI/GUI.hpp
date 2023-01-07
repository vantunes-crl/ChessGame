#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../ChessPieces/Ichess_pieces.hpp"
//#include "../Bot/AutoPlay.hpp"

struct Pos
{
    int x;
    int y;
};

/**
 * @brief Graphical interface for the ChessGame.
 * 
 */
class GUI
{
private:
    std::shared_ptr<sf::RenderWindow> _window;
    BackTrack backTrack;
    //AutoPlay<::Board<std::shared_ptr<Ichess_pieces>>> autoplay;
public:
    void DisplayAvalPlaces(std::list<Pos> &List);

    void selectPiece(const int pos, Board &Board, std::list<Pos> &List);

    /**
     * @brief Main Function of the GUI, Where the main loop hapens.
     * 
     * @param Board The table where the pieces are.
     */
    void start(Board &Board);

    /**
     * @brief a Draw Function where draws all pieces in the right places.
     * 
     * @param Board Board where the pieces are
     * @param Textures a array of sf::Textures, with all pieces textures. 
     */
    void FillBoardWithPieces(Board &Table, std::array<sf::Texture, 13> &Textures);

    /**
     * @brief Init the list of textures.
     * 
     * @return std::array<sf::Texture, 12> 
     */
    std::array<sf::Texture, 13> initTextures();

    void PositionsNames();

    /**
     * @brief Construct a new GUI object.
     * 
     * @param width window width.
     * @param height window hight.
     */
    GUI(int width, int height);
};


#endif