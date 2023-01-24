#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
public: 
    ASpell(std::string name, std::string effects): name(name), effects(effects){}
    ASpell(){}
    ~ASpell(){}
    ASpell(const ASpell &other){*this = other;}
    ASpell &operator = (const ASpell &other){
        this -> name = other.name;
        this -> effects = other.effects;

        return *this;
    }
    const std::string &getName() const{
        return name;
    }
    const std::string &getEffects() const{
        return effects;
    }

    virtual ASpell *clone() const = 0;
    void launch(const ATarget &target) const;

private:
    std::string name;
    std::string effects;
};