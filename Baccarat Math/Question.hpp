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
#include "Global_Functions.hpp"
#include <iostream>
#include <chrono>

class Question{
    
    Bonus questionBonus;
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
    
    // Stat tracking variables for each bonus
    int totalQuestionsAsked = 0;
    
    int dragonQuestionsAsked = 0;
    int dragonsCorrect = 0;
    std::chrono::duration<double> dragonTimeTaken;
    
    int pandaQuestionsAsked = 0;
    int pandasCorrect = 0;
    std::chrono::duration<double> pandaTimeTaken;
    
    int tieQuestionsAsked = 0;
    int tiesCorrect = 0;
    std::chrono::duration<double> tieTimeTaken;
    
    
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
    
    // Set statistics for user to check progress, etc.
    void updateStats(std::chrono::duration<double> time, bool correct);
    void printStats();
    
    //Getters
    int getDollarCeiling();
    int getDollarFloor();

    
};

#endif /* Question_hpp */
