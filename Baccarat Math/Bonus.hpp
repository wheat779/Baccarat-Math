//
//  Bonus.hpp
//  Baccarat Math
//
//  Created by Cameron K.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#ifndef Bonus_hpp
#define Bonus_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>
#include "Global_Functions.hpp"
//#include "Question.hpp"



class Bonus{
    // The name of the bonus, e.g. "dragon", "panda".
    std::string name = "NA";
    // The ratio of the payout bonus, e.g. 40:1, 25:1
    int payoutRatio = 0;
    // The amount placed on the bonus
    int bonusAmount = 0;
    // The correct answer for the bonus payout. E.g. $30 dragon = $1,200
    std::string correctAnswer = "";
    
public:
    // Randomly generate a bonus
    void generateRandBonus();
    // Set bonus to a specific type
    void queryBonus();
    // Randomly generate bonus and correct answer
    void printQuestion();

    // Setter
    void setCorrectAnswer(std::string correctAnswer);
    void setCorrectAnswer(int correctAnswer);
    
    // getters
    std::string getBonusName();
    int getBonusRatio();
    int getBonusAmount();
    std::string getCorrectAnswer();
};

#endif /* Bonus_hpp */
