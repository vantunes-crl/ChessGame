#include "pawn.hpp"

pawn::pawn(bool b)
{
    Color = b;
}

int pawn::play(Board_t &Board, int ToMoveint)
{
    // int pos = this->getPos(Board);

    // if (ToMoveint.x < 0 || ToMoveint.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //verify if not out_size
    //     return OUT_SIZE;
    // else if (pos.x == ToMoveint.x && pos.y == ToMoveint.y) //verify if is the same position
    //     return SAME_PLACE;
    // else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //friend
    //     return CANT_MOVE;

    // std::list<int> List;
    
    // //Check vertical and diagonal  DIAGONAL_BOTTOM_LEFT, DIAGONAL_BOTTOM_RIGHT if Black
    // //Check vertical and diagonal  DIAGONAL_TOP_LEFT, DIAGONAL_TOP_RIGHT if white
    // //Same for the Vertical TOP/BOTTOM
    // if (!this->getColor())
    // {
    //     for (int i = 2; i < 4; ++i)
    //         List.push_back(*backtrack.checkDiagonal(Board, pos, DIAGONAL_CHECK_CASE(i)).begin());
    //     List.push_back(*backtrack.checkVertical(Board, pos, VERTICAL_TOP).begin());
    // }   
    // else
    // {
    //     for (int i = 0; i < 2; ++i)
    //         List.push_back(*backtrack.checkDiagonal(Board, pos, DIAGONAL_CHECK_CASE(i)).begin());
    //     List.push_back(*backtrack.checkVertical(Board, pos, VERTICAL_BOTTOM).begin());
    // }

    // auto it = List.begin();
    // if (it->x == ToMoveint.x && it->y == ToMoveint.y && Board[ToMovePos.x][ToMovePos.y]) //check if can kill diagonal right
    // {
    //     Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //     Board[pos.x][pos.y] = nullptr;
    //     return NO_ERROR;
    // }
    // ++it;
    // if (it->x == ToMoveint.x && it->y == ToMoveint.y && Board[ToMovePos.x][ToMovePos.y]) //check if can kill diagonal left
    // {
    //     Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //     Board[pos.x][pos.y] = nullptr;
    //     return NO_ERROR;
    // }
    // ++it;
    // if (it->x == ToMoveint.x && it->y == ToMoveint.y && !Board[ToMovePos.x][ToMovePos.y]) //no one in front
    // {
    //     Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //     Board[pos.x][pos.y] = nullptr;
    //     return NO_ERROR;
    // }

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