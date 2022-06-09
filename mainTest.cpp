#include "Ichess_pieces.hpp"
#include "table.hpp"
#include <memory>
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"
#include <gtest/gtest.h>


class PiecesTestSuite : public ::testing::Test
{

protected:
    void SetUp() override
    {
        std::cout << "Setting up test case\n";
        Table[0] = {new rook(0), new horse(0),new bishop(0),new queen(0),new king(0),new bishop(0),new horse(0),new rook(0)};
        Table[1] = {nullptr,    new pawn(0),   new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0)};
        Table[2] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
        Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
        Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
        Table[5] = {nullptr,     nullptr,     nullptr,     new pawn(0),     nullptr,      nullptr,      nullptr,      nullptr};
        Table[6] = {new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1),new pawn(1)};
        Table[7] = {new rook(1), new horse(1),new bishop(1),new queen(1),new king(1),new bishop(1),new horse(1),new rook(1)};
    }

    void TearDown() override
    {
        std::cout << "Tearing down test case\n";
    }
    
    table<Ichess_pieces *> Table;
};


// TEST_F(PiecesTestSuite, test_rook)
// {
//     EXPECT_TRUE(Table[0][0]->play(Table, 0, 7)); //Try pass through a enemy piece vertical
//     EXPECT_TRUE(Table[0][0]->play(Table, 7, 0)); //Try go pass through a friend piece
//     EXPECT_FALSE(Table[0][0]->play(Table, 6, 0)); //move front without limit
//     EXPECT_FALSE(Table[6][0]->play(Table, 5, 0)); //move back
//     EXPECT_TRUE(Table[5][0]->play(Table, 5, 7)); // pass through enemy horizontal

//     //Table.printTable();
// }

// TEST_F(PiecesTestSuite, test_pawn)
// {
//     EXPECT_TRUE(Table[1][1]->play(Table, 1, 0)); //Try move left
//     EXPECT_FALSE(Table[1][1]->play(Table, 2, 1)); //Try move front
//     EXPECT_TRUE(Table[2][1]->play(Table, 1, 1)); //Try move back
//     EXPECT_TRUE(Table[2][1]->play(Table, 4, 1)); //Try move more than 1 
//     Table[2][1]->play(Table, 3, 1);
//     Table[3][1]->play(Table, 4, 1);
//     Table[4][1]->play(Table, 5, 1);
//     EXPECT_FALSE(Table[5][1]->play(Table, 6, 2)); //Try Kill on right
//     EXPECT_FALSE(Table[6][2]->play(Table, 7, 1)); //Try Kill on left

//     //Table.printTable();
// }


TEST_F(PiecesTestSuite, test_bishop)
{
    EXPECT_TRUE(Table[0][2]->play(Table, 0, 2)); //try dont move
    EXPECT_TRUE(Table[0][2]->play(Table, -1, 2)); //out size
    EXPECT_TRUE(Table[0][2]->play(Table, 0, -1)); //out size
    EXPECT_TRUE(Table[0][2]->play(Table, 1, 3)); //atc friend right 
    EXPECT_TRUE(Table[0][2]->play(Table, 1, 1)); //atc frind left
    Table[1][3]->play(Table, 2, 3);
    EXPECT_FALSE(Table[0][2]->play(Table, 5, 7)); //move front right
    EXPECT_FALSE(Table[5][7]->play(Table, 1, 3)); //move back right
    EXPECT_FALSE(Table[1][3]->play(Table, 4, 0)); //move front left
    EXPECT_FALSE(Table[4][0]->play(Table, 1, 3)); //move front left
    Table[1][3]->play(Table, 4, 0); //move front left
    EXPECT_FALSE(Table[4][0]->play(Table, 6, 2)); //kill

    Table.printTable();
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}