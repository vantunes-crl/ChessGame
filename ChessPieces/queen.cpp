#include "queen.hpp"

queen::queen(bool b)
{
    Color = b;
}

int queen::play(Board_t &Board, int ToMoveint)
{
    // int pos = this->getPos(Board);
    // int posCpy(pos);

    // if (ToMoveint.x < 0 || ToMoveint.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_size of the Board
    //     return OUT_SIZE;
    // else if (pos.x == ToMoveint.x && pos.y == ToMoveint.y) //Same place
    //     return SAME_PLACE;
    // else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //its a friend
    //     return CANT_MOVE;
    
    // std::list<int> List;
    // for (int i = 0; i < 4; ++i) //check all diagonal
    // {
    //     auto ListCpy = backTrack.checkDiagonal(Board, pos, DIAGONAL_CHECK_CASE(i));
    //     List.insert(List.end(), ListCpy.begin(), ListCpy.end());
    // }

    // //check all vertical/horizontal
    // auto List1 = backTrack.checkVertical(Board, pos, VERTICAL_TOP);
    // auto List2 = backTrack.checkVertical(Board, pos, VERTICAL_BOTTOM);
    // auto List3 = backTrack.checkHorizontal(Board, pos, HORIZONTAL_RIGHT);
    // auto List4 = backTrack.checkHorizontal(Board, pos, HORIZONTAL_LEFT);

    // //append in the main list
    // List.insert(List.end(), List1.begin(), List1.end());
    // List.insert(List.end(), List2.begin(), List2.end());
    // List.insert(List.end(), List3.begin(), List3.end());
    // List.insert(List.end(), List4.begin(), List4.end());

    // //Check in the list of avaliable places, if exists move.
    // for (auto it = List.begin(); it != List.end(); ++it)
    // {
    //     if (ToMoveint.x == it->x && ToMoveint.y == it->y)
    //     {
    //         Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //         Board[pos.x][pos.y] = nullptr;
    //         return NO_ERROR;
    //     }
    // }

    return CANT_MOVE;
}

int queen::type()
{
    if (Color)
        return WHITE_QUEEN;
    else
        return BLACK_QUEEN;
}

int queen::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}


std::shared_ptr<Ichess_pieces> queen::copy()
{
    return std::make_shared<queen>(Color);
}


bool queen::getColor() const
{
    return Color;
}