#include "pawn.hpp"
#include "queen.hpp"

pawn::pawn(bool b)
{
    Color = b;
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

    //white 1 black 0
    if (this->Color)
    {
        const int BoardEnd[8] = {56, 57, 58, 59, 60, 61, 62 , 63};
        bool is_End = false;

        if (std::find(std::begin(BoardEnd), std::end(BoardEnd), ToMovePos) != std::end(BoardEnd))
            is_End = true;

        if ((G_first_play[this->Color] && pos - ToMovePos == 16) ||  //first play of table, front move
            (G_first_play[this->Color] && pos - ToMovePos == 8 && !Board[ToMovePos])) //normal front move
        {
            G_first_play[this->Color] = false;
            if (is_End)
            {
                Board[ToMovePos] = Board[pos];
                Board[pos] = nullptr;
                Board[ToMovePos] = std::make_shared<queen>(this->Color); 
            }
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == 9 && Board[ToMovePos] && Board[ToMovePos]->getColor() != this->Color) ||  //kill enemy
            (pos - ToMovePos == 7 && Board[ToMovePos] && Board[ToMovePos]->getColor() != this->Color))
        {
            G_first_play[this->Color] = false;
            if (is_End)
            {
                Board[ToMovePos] = Board[pos];
                Board[pos] = nullptr;
                Board[ToMovePos] = std::make_shared<queen>(this->Color); 
            }
            return NO_ERROR;
        }
        
    }
    else
    {
        const int BoardEnd[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        bool is_End = false;

        if (std::find(std::begin(BoardEnd), std::end(BoardEnd), ToMovePos) != std::end(BoardEnd))
            is_End = true;

        if ((G_first_play[this->Color] && pos - ToMovePos == -16) ||  //first play of table, front move
            (G_first_play[this->Color] && pos - ToMovePos == -8 && !Board[ToMovePos])) //normal front move
        {
            G_first_play[this->Color] = false;
            if (is_End)
            {
                Board[ToMovePos] = Board[pos];
                Board[pos] = nullptr;
                Board[ToMovePos] = std::make_shared<queen>(this->Color); 
            }
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == -9 && Board[ToMovePos] && Board[ToMovePos]->getColor() != this->Color) || //kill enemy
            (pos - ToMovePos == -7 && Board[ToMovePos] && Board[ToMovePos]->getColor() != this->Color))
        {
            G_first_play[this->Color] = false;
            if (is_End)
            {
                Board[ToMovePos] = Board[pos];
                Board[pos] = nullptr;
                Board[ToMovePos] = std::make_shared<queen>(this->Color); 
            }
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