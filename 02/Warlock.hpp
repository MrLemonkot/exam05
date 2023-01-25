#pragma once
#include <iostream>
#include <vector>
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "SpellBook.hpp"
class Warlock{
    
public:
    Warlock(std::string name, std::string title): name(name), title(title){
        std::cout << name << ": This looks like another boring day.\n";
    }
    ~Warlock(){
        std::cout << name << ": My job here is done!\n";
    }

    const std::string &getName() const{
        return name;
    }

    const std::string &getTitle() const{
        return title;
    }

    void setTitle(const std::string &title){
        this -> title = title;
    }
    void introduce() const{
        std::cout << name << ": I am " << name << ", " << title << "!\n";
    }

    void learnSpell(ASpell *spell){
        if (spell){
            spells.learnSpell(spell);
        } 
    }

    void forgetSpell(const std::string &spell){
        spells.forgetSpell(spell);
    }

    void launchSpell(const std::string &spell, ATarget &target){
       ASpell *spell_obj = spells.createSpell(spell);
       if(spell_obj){
           spell_obj->launch(target);
       }
    }


private:
    Warlock(){}
    Warlock(const Warlock &other){
        *this = other;
    }
    Warlock &operator = (const Warlock &other){
        this -> name = other.getName();
        this -> title = other.getTitle();
        return *this;
    }

    std::string name;
    std::string title;

    SpellBook spells;
};
