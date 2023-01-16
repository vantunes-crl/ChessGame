#include "GUI.hpp"

GUI::GUI(int width, int height)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Chess Game");
}

void GUI::FillBoardWithPieces(Board &board, std::array<sf::Texture, 13> &Textures)
{
    std::array<std::shared_ptr<sf::Sprite>, 32> Pieces;
    int count = 0;
    int CountPos = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[CountPos])
            {
                Pieces[count] = std::make_shared<sf::Sprite>(Textures[board[CountPos]->type()]);
                Pieces[count]->setPosition(j * 100, i * 100);
                count++;
            }
            CountPos++;
        }
        
    }
    for (int i = 0; i < 32; ++i)
    {
        if (Pieces[i])
            _window->draw(*Pieces[i]);
    }
}

std::array<sf::Texture, 13> GUI::initTextures()
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

    std::array<sf::Texture, 13> Textures = {
        BishopWhite,
        BishopWhite, KnightWhite,
        KingWhite, PawnWhite,
        QueenWhite, RookWhite,
        BishopBlack, KnightBlack,
        KingBlack, PawnBlack,
        QueenBlack, RookBlack,
    };

    return Textures;
}

void GUI::selectPiece(const int pos, Board &board, std::list<Pos> &List)
{
    
    static bool selected = false;
    static int PiecesPos = 0;
    static int Color = 0;
    std::list<int> AvalPlaces;
    static int count = 1;
    List.clear();
    AvalPlaces = backTrack.BackTrackAvalPlacesList(pos, board);
    for (auto it : AvalPlaces)
        List.push_back({it % 8, it / 8});

    if (!selected)
    {
        PiecesPos = pos;
        selected = true;
    }
    else
    {
        if(board[PiecesPos])
        {  
            
            if (pos != PiecesPos)
            {                
                // std::string move;
                // auto a = converter.posNumberToEncode(pos);
                // move += a.first;
                // move += char(a.second + 48);
                // std::cout << move << std::endl;

                board[PiecesPos]->play(board, pos);
                autoplay.ROUND = 1;
            }
        }
        List.clear();
        selected = false;
    }
}

void GUI::DisplayAvalPlaces(std::list<Pos> &List)
{
    for (auto it : List)
    {
        sf::RectangleShape rectangle(sf::Vector2f(100, 100));
        rectangle.setFillColor(sf::Color(0, 128, 0, 110));
        rectangle.setPosition(it.x * 100, it.y * 100);
        _window->draw(rectangle);
    }    
}

void GUI::PositionsNames()
{
    sf::Text text;
    sf::Font font;
    sf::Text text2;

    font.loadFromFile("/home/vantunes/ChessGame/GUI/fonts/Roboto-Black.ttf");
    text.setFont(font); 
    text.setString("\t\t a\t\t\t\t  b\t\t\t\t  c\t\t\t\t  d\t\t\t\t  e\t\t\t\t  f\t\t\t\t  g\t\t\t\t  h");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(0,800);

    text2.setFont(font);
    text2.setString("\n8\n\n\n\n7\n\n\n\n\n6\n\n\n\n5\n\n\n\n4\n\n\n\n\n3\n\n\n\n2\n\n\n\n1");
    text2.setFillColor(sf::Color::White);
    text2.setCharacterSize(20);
    text2.setPosition(805, 20);

    _window->draw(text);
    _window->draw(text2);

}

/* Main loop */
void GUI::start(Board &board)
{
    //static board image
    sf::Texture BoardTexture;

    BoardTexture.loadFromFile("GUI/chess-pack/board.png");
    sf::Sprite BoardSprite(BoardTexture);

    bool Select = 0;
    std::array<sf::Texture, 13> PiecesTextures = initTextures();

    int count = 0;
    int Matrix[8][8];
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            Matrix[i][j] = count++;
    }

    std::list<Pos> AvalPlaces;
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
                    selectPiece(Matrix[event.mouseButton.y / 100][event.mouseButton.x / 100], board, AvalPlaces);
                case sf::Event::KeyPressed:
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::B)
                        {
                            autoplay.BotPlay(board);
                            std::cout << "the escape key was pressed" << std::endl;
                        }
                    }
                default:
                    break;
            }
        }
        _window->clear();
        _window->draw(BoardSprite);
        FillBoardWithPieces(board, PiecesTextures);
        DisplayAvalPlaces(AvalPlaces);
        PositionsNames();
        _window->display();
    }
}