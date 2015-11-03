//
//  bonusStat.cpp
//  Baccarat Math
//
//  Created by Cameron K on 10/19/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#include "bonusStat.hpp"

/**
 Set total number of questions asked for the bonus
 */
void bonusStat::setQuestionsAsked(int numQuestions){
    questionsAsked = numQuestions;
}
/**
 set total number of correct answers for the bonus
 */
void bonusStat::setQuestionsCorrect(int numCorrect){
    questionsCorrect = numCorrect;
}
/**
 Set total amount of time taken for a bonus
 */
void bonusStat::setTimeTaken(std::chrono::duration<double> time){
    timeTaken = time;
}

/**
    Return int questionsAsked from bonusStat
 */
int bonusStat::getQuestionsAsked(){
    return questionsAsked;
}
/**
    @return int number of questionsCorrect
 */
int bonusStat::getQuestionsCorrect(){
    return questionsCorrect;
}
/**
    @return chrono duration double timeTaken
 */
std::chrono::duration<double> bonusStat::getTimeTaken(){
    return timeTaken;
}
/**
    Increments number of questions asked for that bonus by one
 */
void bonusStat::incrementQuestionsAsked(){
    questionsAsked++;
}
/**
 Increments number of questions correct for that bonus by one
 */
void bonusStat::incrementQuestionsCorrect(){
    questionsCorrect++;
}
/**
 Adds new time recording for a bonus, increasing its total time by that amount
 */
void bonusStat::addNewTime(std::chrono::duration<double> time){
    timeTaken += time;
}