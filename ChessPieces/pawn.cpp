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

static bool checkOpositeEdges(const int &pos, const int &ToMovePos)
{
    const int LeftEdges[8] = {0, 8, 16, 24, 32, 40, 48, 56};
    const int RightEdges[8] = {7, 15, 23, 31,39, 47, 55, 63};

    bool PosLeft = false;
    bool PosRight = false;
    bool ToMovePosLeft = false;
    bool ToMovePosRight = false;

    if (std::find(std::begin(LeftEdges), std::end(LeftEdges), pos) != std::end(LeftEdges))
        PosLeft = true;
    if (std::find(std::begin(RightEdges), std::end(RightEdges), pos) != std::end(RightEdges))
        PosRight = true;
    if (std::find(std::begin(RightEdges), std::end(RightEdges), ToMovePos) != std::end(RightEdges))
        ToMovePosRight = true;
    if (std::find(std::begin(LeftEdges), std::end(LeftEdges), ToMovePos) != std::end(LeftEdges))
        ToMovePosLeft = true;
    
    if (ToMovePosRight == PosRight || ToMovePosLeft == PosLeft)
        return true;
    return false;
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
    
    if (!checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;
    
    //white 1 black 0
    if (this->Color)
    {
        if ((Board.getFirstPlay(this->Color) && pos - ToMovePos == 16) ||  //first play of table, front move
            (Board.getFirstPlay(this->Color) && pos - ToMovePos == 8 && !Board[ToMovePos])) //normal front move
        {
            Board.getFirstPlay(this->Color) = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == 9 && Board[ToMovePos] ) ||  //kill enemy right
            (pos - ToMovePos == 7 && Board[ToMovePos] )) //kill enemy left
        {
            Board.getFirstPlay(this->Color) = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if (pos - ToMovePos == 8 && !Board[ToMovePos]) //normal move
        {
            Board.getFirstPlay(this->Color) = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
    }
    else
    {
        if ((Board.getFirstPlay(this->Color) && pos - ToMovePos == -16) ||  //first play of table, front move
            (Board.getFirstPlay(this->Color) && pos - ToMovePos == -8 && !Board[ToMovePos])) //normal front move
        {
            Board.getFirstPlay(this->Color) = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if ((pos - ToMovePos == -9 && Board[ToMovePos] )  ||  //kill enemy left
            (pos - ToMovePos == -7 && Board[ToMovePos] )) //kill enemy right
        {
            Board.getFirstPlay(this->Color) = false;
            move(Board[ToMovePos], Board[pos], checkEnd(ToMovePos));
            return NO_ERROR;
        }
        else if (pos - ToMovePos == -8 && !Board[ToMovePos]) //normal move
        {
            Board.getFirstPlay(this->Color) = false;
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