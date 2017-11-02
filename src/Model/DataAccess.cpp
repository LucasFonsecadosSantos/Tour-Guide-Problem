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
#include <string>
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
    this->inputFile.open(inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string firstLine;
    if(this->inputFile.is_open()) {
        this->inputFile.write((char*) &firstLine, sizeof(this->inputFileName));
    }
    std::cout << firstLine.substr(0);
    this->inputFile.close();
    return 3;
}

int** DataAccess::returnGraphDescription() {

}