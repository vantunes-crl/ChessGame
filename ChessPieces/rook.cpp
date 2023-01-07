#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

bool rook::swapKing(Board &board, const int posRook, const int posKing)
{
    auto state = board.read_state();
    int color = board[posKing]->getColor();
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
                std::swap(board[posKing], board[2]);
                std::swap(board[posRook], board[3]);
                swap = false;
                return false;
            }
            break;
        case 7:
            if (std::equal(state.begin() + 4, state.begin() + 7, std::begin(BlackPatern2)))
            {
                std::swap(board[posKing], board[6]);
                std::swap(board[posRook], board[5]);
                swap = false;
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
                std::swap(board[posKing], board[58]);
                std::swap(board[posRook], board[59]);
                swap = false;
                return false;
            }
            break;
        case 63:
            if (std::equal(state.begin() + 60, state.begin() + 63, std::begin(WhitePatern2)))
            {
                std::swap(board[posKing], board[62]);
                std::swap(board[posRook], board[61]);
                swap = false;
                return false;
            }
            break;
        }
    default:
        return true;
    }      
}

int rook::Check(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
    {
        if (board[ToMovePos]->type() == WHITE_KING || board[ToMovePos]->type() == BLACK_KING ) //Check if its a Swap Rook/King
            return SWAP_KING;
        return CANT_MOVE;
    }

    backTrack.AvalMoves(8, BOTTON_EDGE, pos, board, moves); //move top right
    backTrack.AvalMoves(-8, TOP_EDGE, pos, board, moves); //move top left
    backTrack.AvalMoves(-1, LEFT_EDGE, pos, board, moves); //move botton left
    backTrack.AvalMoves(1, RIGHT_EDGE, pos, board, moves); //move botton right

    for (auto it : moves)
    {
        if (it == ToMovePos)
            return NO_ERROR;
    };
    return CANT_MOVE;

}

int rook::play(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    if (Check(board, ToMovePos) == NO_ERROR)
    {
        for (auto it : moves)
        {
            if (it == ToMovePos)
            {
                board[ToMovePos] = board[pos];
                board[pos] = nullptr;
                moves.clear();
                return NO_ERROR;
            }
        };
    }
    else if (Check(board, ToMovePos) == SWAP_KING)
        return swapKing(board, pos, ToMovePos);
    moves.clear();
    return CANT_MOVE;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

int rook::getPos(Board &board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == board[i].get())
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