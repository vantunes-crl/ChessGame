#include "rook.hpp"
#include "king.hpp"

rook::rook(bool b)
{
    Color = b;
}

bool rook::checkNullRange(Ichess_pieces *first, Ichess_pieces *end)
{
    while (first != end)
    {
        if (first != nullptr)
            return false;
        ++first;
    }
    return true;
}

bool rook::swapKing(Board_t &Board, const int posRook, const int posKing)
{
    static int countWhite = 0;
    static int countBlack = 0;
    static bool Swap[2][2] = {{false, false}, {false, false}};

    int color = Board[posKing]->getColor();
    
    switch (posRook)
    {
    case 63:
        if (checkNullRange(Board[60].get(), Board[62].get()) && (!Swap[color][1] || !Swap[color][0]))
        {
            std::swap(Board[posKing], Board[61]);
            std::swap(Board[posRook], Board[60]);
            if (color)
                Swap[color][countWhite++] = true;
            else
                Swap[color][countBlack++] = true;
            break;
        }
    case 56:
        if (checkNullRange(Board[57].get(), Board[58].get()) && (!Swap[color][1] || !Swap[color][0]))
        {
            std::swap(Board[posKing], Board[57]);
            std::swap(Board[posRook], Board[58]);
            if (color)
                Swap[color][countWhite++] = true;
            else
                Swap[color][countBlack++] = true;
            break;
        }
    case 7:
        if (checkNullRange(Board[4].get(), Board[6].get()) && (!Swap[color][1] || !Swap[color][0]))
        {
            std::swap(Board[posKing], Board[5]);
            std::swap(Board[posRook], Board[4]);
            if (color)
                Swap[color][countWhite++] = true;
            else
                Swap[color][countBlack++] = true;
            break;
        }
    case 0:
        if (checkNullRange(Board[1].get(), Board[2].get()) && (!Swap[color][1] || !Swap[color][0]))
        {
            std::swap(Board[posKing], Board[1]);
            std::swap(Board[posRook], Board[2]);
            if (color)
                Swap[color][countWhite++] = true;
            else
                Swap[color][countBlack++] = true;
            break;
        }
    default:
        return true;
    }   
    return false;
}

int rook::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
    {
        switch (Board[ToMovePos]->type()) //Check if its a Swap Rook/King
        {
        case WHITE_KING:
        case BLACK_KING:
            return (swapKing(Board, pos, ToMovePos));
        default:
            return CANT_MOVE;
        }
    }

    std::list<int> moves;
    backTrack.AvalMoves(8, BOTTON_EDGE, pos, Board, moves); //move top right
    backTrack.AvalMoves(-8, TOP_EDGE, pos, Board, moves); //move top left
    backTrack.AvalMoves(-1, LEFT_EDGE, pos, Board, moves); //move botton left
    backTrack.AvalMoves(1, RIGHT_EDGE, pos, Board, moves); //move botton right

    for (auto it : moves)
    {
        if (it == ToMovePos)
        {
            Board[ToMovePos] = Board[pos];
            Board[pos] = nullptr;
            return NO_ERROR;
        }
    };

    return CANT_MOVE;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

int rook::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

std::shared_ptr<Ichess_pieces> rook::copy()
{
    return std::make_shared<rook>(Color);
}

bool rook::getColor() const
{
    return Color;
}