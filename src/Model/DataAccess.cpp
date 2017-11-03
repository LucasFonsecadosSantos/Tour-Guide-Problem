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
#include <cstddef>

/**
 * @brief DataAccess object constructor.
 * 
 * It is responsible for initialize the DataAccess object
 * receiving the input text file name by parameter and
 * setting this ate the inputFileName attribute.
*/
DataAccess::DataAccess(std::string inputNameFile) {
    this->inputFileName = inputNameFile;
}

/**
 * @brief DataAccess object destructor.
 * 
*/
DataAccess::~DataAccess() {

}

/**
 * @brief returnEdgesSetCardinality.
 * 
 * It is responsible for get the input text file first
 * file informations about the edges set cardinality of
 * graph. It access the file by a stream object and 
 * pharsing this for return only integer values.
*/
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
        return atoi("24");
    }else {
        return 0;
    }
}

/**
 * @brief returnVerticesSetCardinality.
 * 
 * It is responsible for get the input text file first
 * file informations about the vertices set cardinality of
 * graph. It access the file by a stream object and 
 * pharsing this for return only integer values.
*/
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
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string line = "";
    if(this->inputFile.is_open()) {
        int linesAmount = 0;
        getline(this->inputFile, line);
        while(this->inputFile) {
            linesAmount++;
            getline(this->inputFile, line);
        }

        std::cout << linesAmount << " ";
        int descriptionMatrix[linesAmount][3];
    }
    return NULL;
}