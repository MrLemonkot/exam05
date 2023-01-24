#pragma once
#include <iostream>

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
};
