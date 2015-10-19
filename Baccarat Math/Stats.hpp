//
//  Stats.hpp
//  Baccarat Math
//
//  Created by Cameron K on 10/18/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>
#include <chrono>
#include <iostream>

#endif /* Stats_hpp */


class Stats{
    
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
    // Set statistics for user to check progress, etc.
    void update(std::string bonusName, std::chrono::duration<double> time, bool correct);
    void print();
};