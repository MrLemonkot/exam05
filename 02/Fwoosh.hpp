#pragma once
#include "ASpell.hpp"

class Fwoosh: public  ASpell{
public:
    Fwoosh(): ASpell("Fwoosh", "fwooshed"){}
    virtual ASpell *clone() const{
        return new Fwoosh();
    }
};

