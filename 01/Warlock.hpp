#pragma once
#include <iostream>
#include <vector>
#include "Fwoosh.hpp"
#include "Dummy.hpp"
class Warlock{
    
public:
    Warlock(std::string name, std::string title): name(name), title(title){
        std::cout << name << ": This looks like another boring day.\n";
        spells.clear();
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
            for (std::vector <ASpell*>::iterator it = spells.begin(); it != spells.end(); it++){
                if ((*it)->getName() == spell->getName())
                    return;
            }
            spells.push_back(spell);
        } 
    }

    void forgetSpell(std::string spell){
        for (std::vector <ASpell*>::iterator it = spells.begin(); it != spells.end(); it++){
                if ((*it)->getName() == spell){
                    spells.erase(it);
                    return;
                }
        }
    }

    void launchSpell(std::string spell, ATarget &target){
       for (std::vector <ASpell*>::iterator it = spells.begin(); it != spells.end(); it++){
                if ((*it)->getName() == spell){
                    (*it)->launch(target);
                    return;
                }
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

    std::vector<ASpell*> spells;
};
