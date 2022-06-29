#include "GUI.hpp"

GUI::GUI(int width, int height)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Chess Game");
}

void GUI::FillTableWithPieces(Ichess_pieces::Table_t &Table, std::array<sf::Texture, 12> &Textures)
{
    std::array<std::shared_ptr<sf::Sprite>, 32> Pieces;
    int count = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (Table[i][j])
            {
               Pieces[count] =  std::make_shared<sf::Sprite>(Textures[Table[i][j]->type()]);
               Pieces[count]->setPosition(j * (_window->getSize().x / 8), i * (_window->getSize().y / 8));
               count++;
            }
        }
    }
    for (int i = 0; i < 32; ++i)
    {
        if (Pieces[i])
            _window->draw(*Pieces[i]);
    }
}

std::array<sf::Texture, 12> GUI::initTextures()
{
    sf::Texture PawnWhite;
    sf::Texture PawnBlack;
    sf::Texture BishopWhite;
    sf::Texture BishopBlack;
    sf::Texture KnightWhite;
    sf::Texture KnightBlack;
    sf::Texture KingWhite;
    sf::Texture KingBlack;
    sf::Texture QueenWhite;
    sf::Texture QueenBlack;
    sf::Texture RookWhite;
    sf::Texture RookBlack;

    PawnWhite.loadFromFile("GUI/chess-pack/chess-pawn-white.png");
    PawnBlack.loadFromFile("GUI/chess-pack/chess-pawn-black.png");
    BishopWhite.loadFromFile("GUI/chess-pack/chess-bishop-white.png");
    BishopBlack.loadFromFile("GUI/chess-pack/chess-bishop-black.png");
    KnightWhite.loadFromFile("GUI/chess-pack/chess-knight-white.png");
    KnightBlack.loadFromFile("GUI/chess-pack/chess-knight-black.png");
    KingWhite.loadFromFile("GUI/chess-pack/chess-king-white.png");
    KingBlack.loadFromFile("GUI/chess-pack/chess-king-black.png");
    QueenWhite.loadFromFile("GUI/chess-pack/chess-queen-white.png");
    QueenBlack.loadFromFile("GUI/chess-pack/chess-queen-black.png");
    RookWhite.loadFromFile("GUI/chess-pack/chess-rook-white.png");
    RookBlack.loadFromFile("GUI/chess-pack/chess-rook-black.png");

    std::array<sf::Texture, 12> Textures = {
        BishopWhite, KnightWhite,
        KingWhite, PawnWhite,
        QueenWhite, RookWhite,
        BishopBlack, KnightBlack,
        KingBlack, PawnBlack,
        QueenBlack, RookBlack,
    };

    return Textures;
}

/* Main loop */
void GUI::start(Ichess_pieces::Table_t &Table)
{
    //static board image
    sf::Texture Board;
    Board.loadFromFile("GUI/chess-pack/board.png");
    sf::Sprite BoardSprite(Board);

    bool Select = 0;
    std::array<sf::Texture, 12> PiecesTextures = initTextures();
    Pos Piece = {0,0};
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    _window->close();
                    break;
                
                case sf::Event::MouseButtonPressed:
                    if (!Select)
                    {
                        Select = true;
                        Piece = {event.mouseButton.y / 100, event.mouseButton.x / 100};
                    }
                    else
                    {
                        Pos NextMove = {event.mouseButton.y / 100, event.mouseButton.x / 100};
                        if (Table[Piece.x][Piece.y])
                            Table[Piece.x][Piece.y]->play(Table, NextMove);
                        Select = false;
                    }
                    break;
                // we don't process other types of events
                default:
                    break;
            }
        }   
        _window->clear();
        _window->draw(BoardSprite);
        FillTableWithPieces(Table, PiecesTextures);
        _window->display();
    }
}