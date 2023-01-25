#pragma once
#include "ATarget.hpp"

class BrickWall: public ATarget{
public:
    BrickWall(): ATarget("Inconspicuous Red-brick Wall"){}
    virtual ATarget *clone() const{
        return new BrickWall();
    }
};