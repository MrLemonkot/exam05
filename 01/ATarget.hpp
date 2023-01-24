#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
public:
    ATarget(){}
    ATarget(std::string type): type(type){}
    virtual ~ATarget(){}
    ATarget(const ATarget &other){
        *this = other;
    }
    ATarget &operator = (const ATarget &other){
        this -> type = other.type;
        return *this;
    }

    virtual ATarget *clone () const = 0;
    const std::string &getType() const{
        return type;
    }

    void getHitBySpell(const ASpell &spell) const;
private:
    std::string type;
};