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
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string firstLine = "";
    if(this->inputFile.is_open()) {
        getline(this->inputFile, firstLine);
        std::string x = "";
        int k = firstLine.size();
        while(firstLine[k-1] != ' ') {
            x += firstLine[k-1];
            k--;
        }
        k=x.size();
        firstLine = "";
        while(k >= 0) {
            firstLine += x[k];
            k--;
        }
        this->inputFile.close();
        return atoi(TEM QUE RETORNAR A STRING CONVERTIDA PRA INTEIRO);
    }else {
        return 0;
    }
}

int DataAccess::returnVerticesSetCardinality() {
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string firstLine = "";
    if(this->inputFile.is_open()) {
        getline(this->inputFile, firstLine);
        std::string x = "";
        int k = 0;
        while(firstLine[k] != ' ' && k < firstLine.size()) {
            x+=firstLine[k];
            k++;
        }
        this->inputFile.close();
        return atoi(x.c_str());
    }else {
        return 0;
    }
}

int** DataAccess::returnGraphDescription() {

}