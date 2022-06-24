#pragma once

#include "Ichess_pieces.hpp"

class BackTrack
{
    public:
        std::list<Pos> BackTrackAvalPlacesList(const Pos &PiecesPos, Ichess_pieces::Table_t &Table);
        void BackTrackAvalPlacesPrint(const Pos &PiecesPos, Ichess_pieces::Table_t &Table);
};