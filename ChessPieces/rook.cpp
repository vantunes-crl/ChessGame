#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

bool rook::swapKing(Board_t &Board, const int posRook, const int posKing)
{
    auto state = Board.read_state();
    int color = Board[posKing]->getColor();
    int type = color ? 3 : 9;

    std::array<int, 5> BlackPatern1 = {BLACK_ROOK, EMPTY, EMPTY, EMPTY, BLACK_KING}; // left black
    std::array<int, 4> BlackPatern2 = {BLACK_KING, EMPTY, EMPTY, BLACK_ROOK}; // right black
    std::array<int, 5> WhitePatern1 = {WHITE_ROOK, EMPTY, EMPTY, EMPTY, WHITE_KING}; // left white
    std::array<int, 4> WhitePatern2 = {WHITE_KING, EMPTY, EMPTY, WHITE_ROOK}; // right white

    switch (type)
    {
    case BLACK_KING:
        switch (posRook)
        {
        case 0:
            if (std::equal(state.begin(), state.begin() + 4, std::begin(BlackPatern1)))
            {
                std::swap(Board[posKing], Board[2]);
                std::swap(Board[posRook], Board[3]);
                Board.swapRookKing(color) = false;
                return false;
            }
            break;
        case 7:
            if (std::equal(state.begin() + 4, state.begin() + 7, std::begin(BlackPatern2)))
            {
                std::swap(Board[posKing], Board[6]);
                std::swap(Board[posRook], Board[5]);
                Board.swapRookKing(color) = false;
                return false;
            }
            break;
        }
    case WHITE_KING:
        switch (posRook)
        {
        case 56:
            if (std::equal(state.begin() + 56, state.begin() + 61, std::begin(WhitePatern1)))
            {
                std::swap(Board[posKing], Board[58]);
                std::swap(Board[posRook], Board[59]);
                Board.swapRookKing(color) = false;
                return false;
            }
            break;
        case 63:
            if (std::equal(state.begin() + 60, state.begin() + 63, std::begin(WhitePatern2)))
            {
                std::swap(Board[posKing], Board[62]);
                std::swap(Board[posRook], Board[61]);
                Board.swapRookKing(color) = false;
                return false;
            }
            break;
        }
    default:
        return true;
    }      
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
        }
        return CANT_MOVE;
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