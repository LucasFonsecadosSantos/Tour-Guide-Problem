/**
 * \file DataAccess.h
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
#ifndef DATA_ACCESS_H
#define DATA_ACCESS_H 1
#include <string>
#include <fstream>

/**
 * \class DataAccess
 * 
 * \section CLASS DOCUMENTATION
 * 
 * This class describes the DataAccess object. This object is responsible
 * for provides the access and all manipulations of the data files. It
 * loads and writes data text files.
 * 
 */
class DataAccess {
    private:
        
        /**
         * \var inputFile This is a input file of data access object.
         */
        std::fstream inputFile;

        /**
         * \var outputFile This is a output file of data access object.
         */
        std::fstream outputFile;

        std::string inputFileName;

    public:
        DataAccess(std::string);
        ~DataAccess();
        int returnEdgesSetCardinality();
        int returnVerticesSetCardinality();
        int** returnGraphDescription();
};

#endif