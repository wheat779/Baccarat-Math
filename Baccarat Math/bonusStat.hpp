//
//  bonusStat.hpp
//  Baccarat Math
//
//  Created by Cameron K on 10/19/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#ifndef bonusStat_hpp
#define bonusStat_hpp

#include <stdio.h>
#include <string>
#include <chrono>
#include <map>

#endif /* bonusStat_hpp */

/*
 Class is an object used to track the statistics of a single bonus.
 questionsAsked and questionsCorrect to track accuracy, and timeTaken to track time.
 */
class bonusStat{
    int questionsAsked = 0;
    int questionsCorrect = 0;
    std::chrono::duration<double> timeTaken;
    
public:
    
    // 
    
    // Setters
    void setQuestionsAsked(int numQuestions);
    void setQuestionsCorrect(int numCorrect);
    void setTimeTaken(std::chrono::duration<double> time);
    void incrementQuestionsAsked();
    void incrementQuestionsCorrect();
    void addNewTime(std::chrono::duration<double> time);
    
    // Getters
    int getQuestionsAsked();
    int getQuestionsCorrect();
    std::chrono::duration<double> getTimeTaken();
};