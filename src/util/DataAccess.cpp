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
#include "../include/DataAccess.h"
#include "../include/Parser.h"

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
    this->parser = new Parser();
}

/**
 * @brief DataAccess object destructor.
 * 
*/
DataAccess::~DataAccess() {
    this->parser->~Parser();
    this->parser = NULL;
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
        std::string* tokens = this->parser->getTokens(firstLine);
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
        std::string* tokens = this->parser->getTokens(firstLine);
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
    return linesAmount-3;
}

int** DataAccess::returnGraphDescription() {
    int rowsAmount = getDataValidRowsAmount();
    int** descriptionMatrix = this->dynamicMatrixSimpleFactory(rowsAmount,3);
    int counterLines = 0;
    std::string line = "";
    std::string* tokens;
    this->inputFile.open(this->inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);

    if(this->inputFile.is_open()) {
        while(this->inputFile && counterLines <= rowsAmount) {
            
                getline(this->inputFile, line);
                if(line == "") {
                    continue;
                }else {
                    if(counterLines > 0) {
                        tokens = this->parser->getTokens(line);
                        for(int i = 0; i < this->parser->tokensCounter(line); i++) {
                            descriptionMatrix[counterLines-1][i] = atoi(tokens[i].c_str());
                        }
                    }
                }
            
            counterLines++;
        }
        this->inputFile.close();
        return descriptionMatrix;
    }
    return NULL;
}

int DataAccess::getSourceVertex() {
    int** descriptionMatrix = this->returnGraphDescription();
    int rowsAmount          = this->getDataValidRowsAmount();
    return descriptionMatrix[rowsAmount][0];
}

int DataAccess::getTargetVertex() {
    int** descriptionMatrix = this->returnGraphDescription();
    int rowsAmount          = this->getDataValidRowsAmount();
    return descriptionMatrix[rowsAmount][1];
}

int DataAccess::getPeoplesAmount() {
    int** descriptionMatrix = this->returnGraphDescription();
    int rowsAmount          = this->getDataValidRowsAmount();
    return descriptionMatrix[rowsAmount][2];
}

int** DataAccess::dynamicMatrixSimpleFactory(int size_i, int size_j) {
    int** matrix = new int*[size_i];
    for(int i = 0; i < size_i; i++) {
        matrix[i] = new int[size_j];
        for(int j = 0; j < size_j; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
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