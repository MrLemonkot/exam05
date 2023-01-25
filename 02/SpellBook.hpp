#pragma once
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"

class SpellBook{
public:
    SpellBook(){
        spells.clear();
    }
    ~SpellBook(){}

    void learnSpell(ASpell* spell){
        if(spell){
            for(std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++){
                if ((*it)->getName() == spell->getName())
                    return;
            }
            spells.push_back(spell);
        }
    }

    void forgetSpell(std::string const &spell){
        for(std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++){
            if((*it) -> getName() == spell){
                spells.erase(it);
                return;
            }
        }
    }

    ASpell* createSpell(std::string const &spell){
        for(std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++){
            if((*it) -> getName() == spell){
                return (*it)->clone();
            }
        }
        return NULL;
    }

private:
    SpellBook(const SpellBook&){}
    SpellBook &operator = (const SpellBook&){
        return *this;
    }
    std::vector<ASpell *> spells;
};