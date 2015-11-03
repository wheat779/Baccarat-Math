//
//  Global_Functions.cpp
//  Baccarat Math
//
//  Created by Cameron K on 10/8/15.
//  Copyright © 2015 Cameron K. All rights reserved.
//

#include "Global_Functions.hpp"



// Get an int from the user, test it, return it
int getUserInt(std::string intPrompt){
    std::cout << intPrompt << std::endl;
    
    bool validResponse = 0;
    int userInt = -1;
    std::string userResponse = "";
    
    while(!validResponse){
        getline(std::cin, userResponse);
        std::stringstream stream(userResponse);
        if(stream >> userInt){
            validResponse = true;
        }
        else{
            std::cout << std::endl << "Invalid Number, try again." << std::endl;
        }
    }
    return userInt;
}

// Query a user using argument stringPrompt and return their string response
std::string getUserStringResponse(std::string stringPrompt){
    std::cout << stringPrompt << std::endl;
    
    std::string response;
    getline(std::cin, response);
    
    return response;
}


// Query a user using argument boolPrompt and return a bool
bool getUserBoolResponse(std::string boolPrompt){
    
    bool userAnswered = false;
    
    while(userAnswered == false){
        std::cout << boolPrompt << std::endl;
        std::string response = "";
        getline(std::cin, response);
        if(response == "yes" || response == "Yes"
           || response == "yeah" || response == "Yeah"
           || response == "yep" || response == "Yep"
           || response == "true" || response == "True"){
            return true;
        }
        else if(response == "no" || response == "No"
                || response == "nope" || response == "Nope"
                || response == "false" || response == "False"){
            return false;
        }
        else{
            std::cout << "I didn't understand \"" << response << "\". please answer with a 'yes' or 'no', etc. " << std::endl;
        }
        
    }
    std::cout << "Error in getUserBoolResponse()";
    return false;
}