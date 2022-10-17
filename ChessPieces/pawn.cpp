#include "pawn.hpp"
#include "queen.hpp"

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

int pawn::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    
    if (!backTrack.checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;
    
    //white 1 black 0
    if (this->Color)
    {
        if ((this->first_play && pos - ToMovePos == 16 && !Board[ToMovePos] && !Board[pos - 8]) ||  //first play of table, front move
            (this->first_play && pos - ToMovePos == 8 && !Board[ToMovePos])) //normal front move
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == 9 && Board[ToMovePos] ) ||  //kill enemy right
            (pos - ToMovePos == 7 && Board[ToMovePos] )) //kill enemy left
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if (pos - ToMovePos == 8 && !Board[ToMovePos]) //normal move
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
    }
    else
    {
        if ((this->first_play && pos - ToMovePos == -16 && !Board[ToMovePos] && !Board[pos + 8]) ||  //first play of table, front move
            (this->first_play && pos - ToMovePos == -8 && !Board[ToMovePos])) //normal front move
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == -9 && Board[ToMovePos] )  ||  //kill enemy left
            (pos - ToMovePos == -7 && Board[ToMovePos] )) //kill enemy right
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if (pos - ToMovePos == -8 && !Board[ToMovePos]) //normal move
        {
            this->first_play = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
    }

    return CANT_MOVE;
}

int pawn::getPos(Board_t &Board) const
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