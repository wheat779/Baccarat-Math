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
#include <map>
#include "bonusStat.hpp"
#include <string>

#endif /* Stats_hpp */

/*
 Class made for tracking user variables regarding accuracy and time.
 
 */
class Stats{
    std::map<std::string, bonusStat> statsMap;
    
public:
    // Set statistics for user to check progress, etc.
    void update(std::string bonusName, std::chrono::duration<double> time, bool correct);
    void print();
};