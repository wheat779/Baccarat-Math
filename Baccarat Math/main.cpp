/*
 Baccarat math.
 
 A program made to help a friend apply for a job. 
 
 Asks user questions about various bonus types which pay out at a certain ratio,
 and tells them if they are correct or incorrect, and offers the ability for them
 to check statistics about they performance. A question example would be:
 
 "How much is $30 on dragon"
 
 As a dragon has a payout ratio of 40:1, the answer would be $1,200 (30*40).
 */


#include <iostream>
#include <string>
#include <ctime>
#include "Bonus.hpp"
#include "Question.hpp"
#include "Global_Functions.hpp"



int main(){
    std::srand(std::time(0));
    Question test1;
    
    test1.runQuestionLoop();
}
