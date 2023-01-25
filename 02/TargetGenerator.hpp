#pragma once
#include <vector>
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"

class TargetGenerator{
public:
    TargetGenerator(){
        targets.clear();
    }
    ~TargetGenerator(){}

    void learnTargetType(ATarget* target){
        if(target){
            for(std::vector <ATarget *>:: iterator it = targets.begin(); it != targets.end(); it++){
                if((*it) -> getType() == target->getType())
                return;
            }
            targets.push_back(target);
        }
    }
    void forgetTargetType(std::string const &target){
        for(std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++){
            if((*it)-> getType() == target){
                targets.erase(it);
                return;
            }
        }
    }
    ATarget* createTarget(std::string const &target){
        for(std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++){
            if((*it)->getType() == target){
                return (*it)->clone();
            }
        }
        return NULL;
    }

private:
    TargetGenerator(const TargetGenerator&){}
    TargetGenerator &operator = (const TargetGenerator&){
        return *this;
    }
    std::vector <ATarget *> targets;
};