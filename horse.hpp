#include "Ichess_pieces.hpp"

class horse : public Ichess_pieces
{
    public:
        void play() override;
        std::string type() override;
    
};

