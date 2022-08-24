#include "king.hpp"

king::king(bool b)
{
    Color = b;
}

bool king::checkIfSomeoneCanKill(Ichess_pieces::Board_t Board, int pos)
{
    // Board[pos.x][pos.y] = std::make_shared<king>(Color);
    // for (int i = 0; i < 8; ++i)
    // {
    //     for (int j = 0; j < 8; ++j)
    //     {
    //         if (Board[i][j] != nullptr && Board[i][j]->type() != WHITE_KING && Table[i][j]->type() != BLACK_KING )
    //         {
    //             if (Board[i][j]->getColor() != this->Color && Board[i][j]->play(Table, pos) == 0)
    //                 return true;
    //         }
    //     }
    // }
    // return false;
}

int king::play(Board_t &Board, int ToMoveint)
{

//     int pos = this->getPos(Board);

//     if (ToMoveint.x < 0 || ToMoveint.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //check out size
//         return OUT_SIZE;
//     else if (ToMoveint.x == pos.x && ToMoveint.y == pos.y) //check if is in the same place
//         return SAME_PLACE;
//     else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
//         return CANT_MOVE;
//     else
//     {
//         if (checkIfSomeoneCanKill(Board, {ToMoveint.x, ToMoveint.y}))
//             return CANT_MOVE;
//     }

//    std::list<int> List;
//     for (int i = 0; i < 4; ++i) //check all diagonal
//         List.push_back(*backTrack.checkDiagonal(Board, pos, DIAGONAL_CHECK_CASE(i)).begin());

//     //check all vertical/horizontal
//     List.push_back(*backTrack.checkVertical(Board, pos, VERTICAL_TOP).begin());
//     List.push_back(*backTrack.checkVertical(Board, pos, VERTICAL_BOTTOM).begin());
//     List.push_back(*backTrack.checkHorizontal(Board, pos, HORIZONTAL_RIGHT).begin());
//     List.push_back(*backTrack.checkHorizontal(Board, pos, HORIZONTAL_LEFT).begin());


//     //Check in the list of avaliable places, if exists move.
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

int king::type()
{
    if (Color)
        return WHITE_KING;
    else
        return BLACK_KING;
}

int king::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}


std::shared_ptr<Ichess_pieces> king::copy()
{
    return std::make_shared<king>(Color);
}


bool king::getColor() const
{
    return Color;
}