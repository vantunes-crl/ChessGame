#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP

#include <iostream>
#include "table.hpp"

class Ichess_pieces
{
    public:
        virtual void play(table<Ichess_pieces *> &Table) = 0;
        virtual std::string type() = 0;
        

    virtual ~Ichess_pieces() {};
};


#endif