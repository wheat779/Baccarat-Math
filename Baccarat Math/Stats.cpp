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
    if(bonusName == "dragon"){
        dragonQuestionsAsked++;
        dragonTimeTaken += time;
        if(correct){
            dragonsCorrect++;
        }
    }
    else if(bonusName == "panda"){
        pandaQuestionsAsked++;
        pandaTimeTaken += time;
        if(correct){
            pandasCorrect++;
        }
    }
    else if(bonusName == "tie"){
        tieQuestionsAsked++;
        tieTimeTaken += time;
        if(correct){
            tiesCorrect++;
        }
    }
    else std::cout << "Error in updateStats";
}


// Print to screen the statistics of the accuracy and reaction time in answering questions
void Stats::print(){
    /* print:
     ***********
     Statistics
     ***********
     (bonus)accuracy: (double)%
     (bonus) time per question: (double) seconds
     */
    std::cout << "**********" << std::endl << "Statistics" << std::endl << "**********" << std::endl;
    
    std::cout << "Dragon accuracy: " << (double(dragonsCorrect)/double(dragonQuestionsAsked))*100 << "%" << std::endl;
    std::cout << "Dragon time per question: " << double(dragonTimeTaken.count()/dragonQuestionsAsked) << " seconds" << std::endl << std::endl;
    
    std::cout << "Panda accuracy: " << (double(pandasCorrect)/double(pandaQuestionsAsked))*100 << "%" << std::endl;
    std::cout << "Time per panda question: " << double(pandaTimeTaken.count()/pandaQuestionsAsked) << " seconds" << std::endl << std::endl;
    
    std::cout << "Tie accuracy: " << (double(tiesCorrect)/double(tieQuestionsAsked))*100 << "%" << std::endl;
    std::cout << "Time per tie question: " << double(tieTimeTaken.count()/tieQuestionsAsked) << " seconds" << std::endl << std::endl;
}