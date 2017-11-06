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
#include "../Include/Pharser.h"

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
    this->pharser = new Pharser();
}

/**
 * @brief DataAccess object destructor.
 * 
*/
DataAccess::~DataAccess() {
    this->pharser->~Pharser();
    this->pharser = NULL;
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
        std::string* tokens = this->pharser->getTokens(firstLine);
        this->inputFile.close();
        return atoi(tokens[1].c_str());
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
        std::string* tokens = this->pharser->getTokens(firstLine);
        this->inputFile.close();
        return atoi(tokens[0].c_str());
    }else {
        return 0;
    }
}

/**
 * @brief returnGraphDescription
 * 
 * This method is responsible for returning all conections (edges)
 * in the graph. It gets the string tokens by data text file line,
 * convert this to integer value and returns for the caller method.
 * 
 * @return int** A integer matrix pointer with all terminal vertices.
 */



int DataAccess::getDataValidRowsAmount() {
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string line = "";
    int linesAmount = 0;
    if(this->inputFile.is_open()) {
        getline(this->inputFile, line);
        while(this->inputFile) {
            if(line != "") {
                linesAmount++;
            }
            getline(this->inputFile, line);
        }
    }
    this->inputFile.close();
    return linesAmount-2;
}

int** DataAccess::returnGraphDescription() {
    int rowsAmount = getDataValidRowsAmount();
    int** descriptionMatrix = new int*[rowsAmount];
    for(int i = 0; i < rowsAmount; i++) {
        descriptionMatrix[i] = new int[3];
    }
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string line = "";
    std::string* tokens;
    int counterLines = 0;
    getline(this->inputFile, line); //This row ensures that the first line where read.
    if(this->inputFile.is_open()) {
        while(this->inputFile) {
            getline(this->inputFile, line);
            if(line == "") {
                continue;
            }else {
                tokens = this->pharser->getTokens(line);
                
                //THE PROBLEM IS HEREEEEEEE
                
                for(int i = 0; i < 3; i++) {
                    descriptionMatrix[counterLines][i] = atoi(tokens[i].c_str());
                }
                counterLines++;
            }
        }
        this->inputFile.close();
        return descriptionMatrix;
    }
    return NULL;
}
/*
int** DataAccess::returnGraphDescription() {
    int linesAmount = getDataLinesAmount();
    std::cout << linesAmount;
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string line = "";
    if(this->inputFile.is_open()) {
        int** descriptionMatrix = new int*[linesAmount];
        for(int i=0; i<linesAmount; i++) {
            descriptionMatrix[i] = new int[3];
        }
        this->inputFile.clear();
        this->inputFile.seekg(0, std::ios::beg);
        getline(this->inputFile, line);
        std::string* tmpString;
        int counterLines = 0;
        while(this->inputFile) {
            getline(this->inputFile, line);
            if(line == "") {
                for(int i=0; i<3; i++) {
                    descriptionMatrix[counterLines][i] = 0;
                }
                continue;
            }else if(line != "") {
                tmpString = this->pharser->getTokens(line);
                for(int i=0; i<3; i++) {
                    descriptionMatrix[counterLines][i] = atoi(tmpString[i].c_str());
                }
            }
            counterLines++;
        }
        return descriptionMatrix;
    }else {
        return NULL;
    }
}*/

/**
 * @brief fast_atoi
 * 
 * This is a faster atoi method than native c++ atoi for convertion
 * a const char to integer types.
 * 
 * @param str A const char pointer that will be convert to integer.
 * @return int A integer value result of convertion.
 */
int DataAccess::fast_atoi(const char * str) {
    int val = 0;
    while(*str) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}