#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Board.hpp"
#include "../ChessPieces/Ichess_pieces.hpp"
#include "../BackTrackAlgorithm/BackTrack.hpp"

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
public:
    void DisplayAvalPlaces(std::list<Pos> &List);

    void selectPiece(const int pos, Ichess_pieces::Board_t &Board, std::list<Pos> &List);

    /**
     * @brief Main Function of the GUI, Where the main loop hapens.
     * 
     * @param Board The table where the pieces are.
     */
    void start(Ichess_pieces::Board_t &Board);

    /**
     * @brief a Draw Function where draws all pieces in the right places.
     * 
     * @param Board Board where the pieces are
     * @param Textures a array of sf::Textures, with all pieces textures. 
     */
    void FillBoardWithPieces(Ichess_pieces::Board_t &Table, std::array<sf::Texture, 13> &Textures);

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