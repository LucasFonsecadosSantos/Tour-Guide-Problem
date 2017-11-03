/**
 * \file DataAccess.cpp
 * \date 02/11/2017
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
 * This files describes ...
 */
#include "../Include/DataAccess.h"
#include <fstream>
#include <string.h>
#include <vector>
#include <iostream>

DataAccess::DataAccess(std::string inputNameFile) {
    this->inputFileName = inputNameFile;
}

DataAccess::~DataAccess() {

}

int DataAccess::returnEdgesSetCardinality() {

}

int DataAccess::returnVerticesSetCardinality() {
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string firstLine;
    if(this->inputFile.is_open()) {
        getline(this->inputFile, firstLine);
    }
    std::string x = "";
    bool stopCondition = false;
    bool hasOccurrency = false;
    for(int i=0; i<firstLine.size(); i++) {
        if(firstLine[i] != ' ' && !stopCondition) {
            x += firstLine[i];
            hasOccurrency = true;
        } if(firstLine[i] == ' ' && hasOccurrency) {
            stopCondition = true;
        }
    }
    this->inputFile.close();
    return atoi(x.c_str());
}

int** DataAccess::returnGraphDescription() {

}