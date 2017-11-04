#include "../Include/Pharser.h"

#include <string>

Pharser::Pharser() {

}

Pharser::~Pharser() {

}

std::string* Pharser::getConectionsTokens(std::string line) {
    std::string* tokensArray = new std::string[3];
    int tokensCounter = 0;
    bool control = false;

    for(int i=0; i<line.size(); i++) {
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