//
//  Question.cpp
//  Baccarat Math
//
//  Created by Cameron K on 10/4/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#include "Bonus.hpp"
#include "Question.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

/*
 Query user to set class variables that determine what bonus questions are asked
 */
void Question::startingOptionsPrompt(){
    std::cout << "Hello Frank!" << std::endl << std::endl;
    std::cout << "Enter \"stats\" during the question phase to get statistics on bonus accuracy/time" << std::endl;
    std::cout << "Enter \"exit\" during the question phase to exit the program." << std::endl << std::endl;

    /*
     See if user wants bonuses set to random, if not then let them choose
     a specific bonus to be asked questions about.
     */
    queryRandomBonus();
    if(!randomBonuses){
        questionBonus.queryBonus();
    }
    // Ask user what the minimum (floor) and maximum (ceiling) bonus size should be
    queryFloorCeiling();
    queryDollarChips();
}

/*
 Ask if user if they want to include dollar chips, i.e. have bonuses in increments of 
 one dollar (1,2,3..). If they answer no, bonuses are instead incremented by five dollar 
 chips (5,10,15...).
 */
void Question::queryDollarChips(){
    dollarChips = getUserBoolResponse("Use dollar chips in payout questions?");
}

// Ask user if they want bonuses to be randomly selected from a list
void Question::queryRandomBonus(){
    randomBonuses = getUserBoolResponse("Do you want to be asked questions with randomly generated bonuses?");
}

// Ask user to specify the min and max bonus size for randomly generated bonuses
void Question::queryFloorCeiling(){
    
    bool validInput = false;
    while(!validInput){
    dollarFloor = getUserInt("Choose a minimum amount placed on a bonus.");
    dollarCeiling = getUserInt("Choose a maximum amount placed on a bonus.");
    
    // Check user responses for errors
    validInput = checkFloorCeilingInput();
    
    }
}

// Check to see if the user has input a valid floor/ceiling for bonuses
bool Question::checkFloorCeilingInput(){
    
    //Ensure the floor is lower than the ceiling
    if(dollarFloor > dollarCeiling){
        std::cout << "The maximum bonus cannot be less than the minimum bonus" << std::endl;
        return false;
    }
    else if(dollarFloor < 0){
        std::cout << "The minimum bonus cannot be less than 0" << std::endl;
        return false;
    }
    else if(dollarCeiling > 10000){
        std::cout << "The maximum bonus cannot be greater than 10,000" << std::endl;
        return false;
    }
    // If it doesn't have any of the above problems...
    return true;
}

// Main loop. Sets class variables, and then asks bonus questions until user says "exit"
void Question::runQuestionLoop(){

    startingOptionsPrompt();
    
    std::cout << std::endl << std::endl;
    
    // Loop ends when user enters "exit" as answer
    while(questioning){
    generateQuestion();
    }
    
}

/*
 Output a bonus question, format: How much is (amount) on (bonus)
 
 Measure the amount of time it takes a user to answer the question and whether 
 they were right and use that information to update the bonus statistics.
 
 Output those statistics of the user enters 'stats' or quit the program if they enter 'exit'.
 */
void Question::generateQuestion(){
    std::string response = "";
    bool userWasCorrect = 0;
    
    if(randomBonuses){
        questionBonus.generateRandBonus();
    }
    int amount = generateAmountOnBonus();
    
    // Measure start time for question statistics
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    
    
    // Query user
    std::cout << "How much is " << amount << " on " << questionBonus.getBonusName();
    questionBonus.setCorrectAnswer(amount * questionBonus.getBonusRatio());
    
    // Record response and determine if it's correct
    response = getUserStringResponse("");
    userWasCorrect = response == questionBonus.getCorrectAnswer();
    
    // Measure end time to get total time elapsed waiting for user response
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> userTime = end - start;
    
    
    if(userWasCorrect){
        std::cout << std::endl << "Correct!" << std::endl;
    }
    // Output statistics if user enters "stats"
    else if(response == "stats" || response == "Stats"){
        questionStats.print();
    }
    // End loop if user says "exit"
    else if(response == "quit" || response == "exit"){
        questioning = 0;
    }
    // If user is incorrect, give correct answer
    else{
        std::cout << std::endl << "Incorrect! " << amount << " x " << questionBonus.getBonusRatio() << " = " <<questionBonus.getCorrectAnswer() << std::endl << std::endl;
    }
    // Update statistics
    questionStats.update(questionBonus.getBonusName(), userTime, userWasCorrect);
}

/*
 Return a randomly generated int using the user's specified variables.
 
 
 */
int Question::generateAmountOnBonus(){
    
    // Find the span between the upper and lower bound, this is amount of numbers we can generate
    int span = dollarCeiling - dollarFloor;
    
    int bonusAmount = (rand() % span) + dollarFloor;
    
    // If the user wants an bonus amount to be generated using dollar chips (i.e. in increments of 1)
    // then we are finished
    if(dollarChips == 1){
        return bonusAmount;
    }
    /*
     If the user wants their bonus to not include dollar chips (i.e. incremented in 5s) then we
     remove the amounts that don't end in five or zero by dividing and then multiplying by five,
     this effectively rounds all numbers down to the nearest multiple of five.
     
     The advantage of this rounding down method: if the user input a floor and/or ceiling containing
     units of a dollar (e.g. "103") the following method will round down the randomly generated 
     amount. e.g. if the user wants a number between "0" and "104" but says they want the question 
     to not include dollar chips, a random generation of "104" will automatically be rounded down 
     to 100. Thus we can never exceed our ceiling but don't need a special case of rounding for 
     when the floor or ceiling amounts are not devisible by 5.
     */
    else{ // dollar chips == 0
        return (bonusAmount / 5) * 5;
    }
}

