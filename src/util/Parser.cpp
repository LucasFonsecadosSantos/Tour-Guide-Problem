/**
 * \file Parser.h
 * \date 05/11/2017
 * \author Lucas Fonseca dos Santos
 * \copyright GNU-3 Public License.
 * 
 * \section FILE DOCUMENTATION
 * 
 * FEDERAL UNIVERSITY OF LAVRAS - Algorithms in Graphs Discipline
 * PROFESSOR: MAYRON MOREIRA.
 * TOUR GUIDE PROBLEM SOLUTION SOFTWARE.
 * WRITTEN BY: LUCAS FONSECA DOS SANTOS (201712078).
 * 
 * This file describes the Parser object, responsible for identifying
 * multiples tokens and parts on specifc string.
 * After this verification, it returns to the caller method all information
 * coleted by your methods.
 */
#include "../include/Parser.h"

#include <string>

/**
 * \brief Parser object constructor.
 * 
 */
Parser::Parser() {

}

/**
 * \brief Parser object destructor.
 * 
 */
Parser::~Parser() {

}

/**
 * \brief tokensCounter
 * 
 * This method is responsible for counting all tokens presents
 * in a string.
 * 
 * \return int A integer tokens counted amount value.
 */
int Parser::tokensCounter(std::string stringLine) {
    int counter = 0;
    bool control = false;
    for(int i = 0; i < stringLine.size(); i++) {
        if(stringLine[i] == ' ' 
        || stringLine[i] == ',' 
        || stringLine[i] == '.'
        || stringLine[i] == '\\'
        ) {
            control = false;
            continue;
        }else {
            if(!control) {
                ++counter;
            }
            control = true;
        }
    }
    return counter;
}

/**
 * \brief getTokens
 * 
 * \return std::string A standart string object pointer array with all tokens coleted.
 */
std::string* Parser::getTokens(std::string line) {
    int tokensAmount = tokensCounter(line);
    std::string* tokensArray = new std::string[tokensAmount];
    int tokensCounter = 0;
    bool control = false;
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == ' ') {
            continue;
        }else {
            control = false;
            tokensArray[tokensCounter] += line[i];
            if(line[i+1] == ' ') {
                control = true;
            }
        }
        if(control) {
            tokensCounter++;
        }
    }
    return tokensArray;
} 