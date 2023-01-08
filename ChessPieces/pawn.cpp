#include "pawn.hpp"
#include "unistd.h"

pawn::pawn(bool b)
{
    Color = b;
}

bool pawn::checkEnd(const int ToMovePos)
{
    const int BoardEnd[16] = {56, 57, 58, 59, 60, 61, 62 , 63, 0, 1, 2, 3, 4, 5, 6, 7};

    if (std::find(std::begin(BoardEnd), std::end(BoardEnd), ToMovePos) != std::end(BoardEnd))
        return true;
    return false;
}

void pawn::move(std::shared_ptr<Ichess_pieces> &ToMovePos, std::shared_ptr<Ichess_pieces> &Pos, bool end)
{
    if (!end)
        ToMovePos = Pos;
    else
    {
        std::shared_ptr<Ichess_pieces> temp = std::make_shared<queen>(this->Color);
        ToMovePos = temp;
    }
    Pos = nullptr;
}

int pawn::play(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    auto check = Check(board, ToMovePos);
    auto lastMove = board.getLastEventMove();
    switch (check)
    {
        case ENPASSANTE:
            board[lastMove.first] = nullptr;
        case NO_ERROR:
            if (abs(pos - ToMovePos) == 16)
                board.setMoveEvent(ToMovePos, true);
            else
                board.setMoveEvent(ToMovePos, false);
            move(board[ToMovePos], board[pos], checkEnd(ToMovePos));
            this->first_play = false;
            return NO_ERROR;
    }
    return CANT_MOVE;
}

int pawn::Check(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    if (!backTrack.checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;

    int signal = 1;
    if (!this->Color)
        signal = -1;
        
    bool firstPlay = ((this->first_play && pos - ToMovePos == (16 * signal) && !board[ToMovePos] && !board[pos - (8 * signal)]) || (this->first_play && pos - ToMovePos == (8 * signal) && !board[ToMovePos]));
    bool killEnemy = ((pos - ToMovePos == (9 * signal) && board[ToMovePos] ) || (pos - ToMovePos == (7 * signal) && board[ToMovePos]));
    bool normalMove = (pos - ToMovePos == (8 * signal) && !board[ToMovePos]);
    bool enpassant =  ((pos - ToMovePos == (9 * signal)) || (pos - ToMovePos == (7 * signal)));

    if (enpassant)
    {
        auto move = board.getLastEventMove();
        if (board[pos + 1] && board[pos + 1]->getColor() != this->Color)
        {
            int left = this->Color ? 7 : 9;
            if (move.first == pos + 1 && move.second && (pos - ToMovePos) == (left * signal))
                return ENPASSANTE;
        }
        if (board[pos -1] && board[pos - 1]->getColor() != this->Color)
        {
            int right = this->Color ? 9 : 7;
            if (move.first == pos - 1 && move.second && (pos - ToMovePos) == (right * signal))
                return ENPASSANTE;
        }
    }

    if (firstPlay || killEnemy || normalMove)
        return NO_ERROR;
    return CANT_MOVE;
}

int pawn::getPos(Board &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

int pawn::type()
{
    if (Color)
        return WHITE_PAWN;
    else
        return BLACK_PAWN;
}

std::shared_ptr<Ichess_pieces> pawn::copy()
{
    return std::make_shared<pawn>(Color);
}


bool pawn::getColor() const
{
    return Color;
}