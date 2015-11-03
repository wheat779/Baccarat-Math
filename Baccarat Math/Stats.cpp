//
//  Stats.cpp
//  Baccarat Math
//
//  Created by Cameron K on 10/18/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#include "Stats.hpp"

/*
 Use chrono::duration<double> time information to update the average time for
 that question subtype, and bool correct to update the accuracy for that
 question subtype.
 */
void Stats::update(std::string bonusName, std::chrono::duration<double> time, bool correct){
    
    if(statsMap.find(bonusName) == statsMap.end()){
        bonusStat newBonus;
        newBonus.setQuestionsAsked(1);
        if(correct){
            newBonus.setQuestionsCorrect(1);
        }
        else{
            newBonus.setQuestionsCorrect(0);
        }
        newBonus.setTimeTaken(time);
        statsMap[bonusName] = newBonus;
    }
    else if(statsMap.find(bonusName) != statsMap.end()){
        statsMap[bonusName].incrementQuestionsAsked();
        if(correct){
            statsMap[bonusName].incrementQuestionsCorrect();
        }
        statsMap[bonusName].addNewTime(time);
    }
    
    
}


// Print to screen the statistics of the accuracy and reaction time in answering questions
void Stats::print(){
    
    
    // Define iterator type for printing statsMap
    typedef std::map<std::string, bonusStat>::iterator it_type;
    
    /* print:
     ***********
     Statistics
     ***********
     (bonus)accuracy: (double)%
     (bonus) time per question: (double) seconds
     */

    std::cout << "**********" << std::endl << "Statistics" << std::endl << "**********" << std::endl;

    // iterator printing loop through statsMap
    for(it_type iterator = statsMap.begin(); iterator != statsMap.end(); iterator++){
        
        // (bonus) accuracy: (double)%
        std::cout << iterator-> first << " accuracy: " <<
        double(iterator -> second.getQuestionsCorrect())/double(iterator -> second.getQuestionsAsked())*100 << "%" << std::endl;
        
        // (bonus) time per question: (double) seconds
        std::cout << iterator -> first << " time per question: "
        << double(iterator -> second.getTimeTaken().count()/iterator -> second.getQuestionsAsked()) << " seconds" <<  std::endl << "**********" << std::endl;
    }
}