//
//  Question.hpp
//  Baccarat Math
//
//  Created by Cameron K on 10/4/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#ifndef Question_hpp
#define Question_hpp


#include <stdio.h>
#include <string>
#include "Bonus.hpp"
#include "Stats.hpp"
#include "Global_Functions.hpp"
#include <iostream>
#include <chrono>

class Question{
    
    
    /* 
     Object used to track the information about the current bonus being
     asked about, e.g. name and payout ratio
     */
    Bonus questionBonus;
    /*
     Object to track the statistics of how many questions the user has gotten
     correct and how fast they were at answering each bonus type.
     */
    Stats questionStats;
    // Currently asking questions?
    bool questioning = true;
    // Did the user get the question correct?
    bool userWasCorrect = false;
    // Generate bonuses with dollar chips
    bool dollarChips = false;
    // Uses selected bonus, if applicable
    std::string userSelectedBonus = "NA";
    // Randomly generate bonuses?
    bool randomBonuses = false;
    // The high and low amount of dollars
    int dollarFloor = 0;
    int dollarCeiling = 300;
    
public:
    
    // run main loop where bonus questions are asked bonus questions until they say "exit"
    void runQuestionLoop();
    
    // Set bonus params based on user input
    void startingOptionsPrompt();
    
    // Ask user if they want to include dollar chips and increment bonuses by one dollar
    void queryDollarChips();
    
    // Ask user if they want to be asked random bonus types
    void queryRandomBonus();
    
    // Set user's floor and ceiling for bonuses generated
    void queryDollarFloorCeiling();
    
    // Make sure the user's input makes sense
    bool checkFloorCeilingInput();

    // Ask user to set the lower/upper limit for bonuses
    void queryFloorCeiling();
    
    // Randomly generate an amount for the bonus based on user input floor/ceiling
    int generateAmountOnBonus();
    
    // Output a question and set the correctAnswer var to the value
    void generateQuestion();
    
    //Getters
    int getDollarCeiling();
    int getDollarFloor();

    
};

#endif /* Question_hpp */
