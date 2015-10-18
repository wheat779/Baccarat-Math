//
//  Bonus.cpp
//  Baccarat Math
//
//  Created by Cameron K on 10/4/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#include "Bonus.hpp"
#include <ostream>


/*
 Randomly generate a bonus and set its name and payout ratio
 */
void Bonus::generateRandBonus(){
    
    int randSelect = rand()%3;
    
    if(randSelect == 0){
        name = "dragon";
        payoutRatio = 40;
    }
    
    else if(randSelect == 1){
        name = "panda";
        payoutRatio = 25;
    }
    
    else if(randSelect == 2){
        name = "tie";
        payoutRatio = 8;
    }
    
}

// Take user's input to select which bonus they want to practice
void Bonus::queryBonus(){
    
    bool validResponse = 0;
    
    while(!validResponse){
        std::string userResponse = getUserStringResponse("What bonus do you want questions for?");
    
        if(userResponse == "dragon" || userResponse == "Dragon"){
            name = "dragon";
            payoutRatio = 40;
            validResponse = 1;
        }
    
        else if(userResponse == "panda" || userResponse == "Panda"){
            name = "panda";
            payoutRatio = 25;
            validResponse = 1;
        }
    
        else if(userResponse == "tie" || userResponse == "Tie"){
            name = "tie";
            payoutRatio = 8;
            validResponse = 1;
        }
        // secret bonus inclusion
        else if(userResponse == "tiger" || userResponse == "Tiger"){
            name = "tiger";
            payoutRatio = 30;
            validResponse = 1;
        }
        else{
            std::cout << std::endl << "I did not understand " << userResponse << ", please specify a bonus name: e.g. \"panda\", \"dragon\", or \"tie\"" << std::endl;
        }
    }
}

// Getter for bonus name
std::string Bonus::getBonusName(){
    return name;
}

// Getter for payout ratio
int Bonus::getBonusRatio(){
    return payoutRatio;
}

int Bonus::getBonusAmount(){
    return bonusAmount;
}
std::string Bonus::getCorrectAnswer(){
    return correctAnswer;
}

void Bonus::setCorrectAnswer(std::string correct){
    correctAnswer = correct;
}
void Bonus::setCorrectAnswer(int intCorrectAns){
    std::ostringstream convert;
    convert << intCorrectAns;
    
    correctAnswer = convert.str();
    
    
    
}