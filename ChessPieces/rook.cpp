#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

int rook::play(Board_t &Board, int ToMoveint)
{
//     int pos = this->getPos(Board);
//     std::list<int> List;

//     if (ToMoveint.x < 0 || ToMoveint.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_side of the Board
//         return OUT_SIZE;
//     else if (pos.x != ToMoveint.x && pos.y != ToMoveint.y) //just can move to left or right not both
//         return CANT_MOVE;
//     else if (pos.x == ToMoveint.x && pos.y == ToMoveint.y) // check if its the same pos
//         return SAME_PLACE;
//     else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
//         return CANT_MOVE;
//     else if (pos.x != ToMoveint.x) //BackTrack of Vertical
//     {
//         List = backtrack.checkVertical(Board, pos, VERTICAL_TOP);
//         auto List2 = backtrack.checkVertical(Board, pos, VERTICAL_BOTTOM);
//         List.insert(List.end(), List2.begin(), List2.end());
//     }
//     else  //BackTrack of Horizontal
//     {
//         List = backtrack.checkHorizontal(Board, pos, HORIZONTAL_RIGHT);
//         auto List2 = backtrack.checkHorizontal(Board, pos, HORIZONTAL_LEFT);
//         List.insert(List.end(), List2.begin(), List2.end());
//     }

//     for (auto it = List.begin(); it != List.end(); ++it)
//     {
//         if (ToMoveint.x == it->x && ToMoveint.y == it->y)
//         {
//             Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
//             Board[pos.x][pos.y] = nullptr;
//             return NO_ERROR;
//         }
//     }

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