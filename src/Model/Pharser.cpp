#include "../Include/Pharser.h"

#include <string>
#include <iostream>

Pharser::Pharser() {

}

Pharser::~Pharser() {

}

int Pharser::tokensCounter(std::string stringLine) {
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

std::string* Pharser::getConectionsTokens(std::string line) {
    int tokensAmount = tokensCounter(line);
    std::string* tokensArray = new std::string[tokensAmount];
    std::cout << "TOKENS AMOUNT: " << tokensAmount;
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