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

#include "Parser.h"

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

        /**
         * \var inputFileName Input data text file name.
         */
        std::string inputFileName;

        /**
         * \var pharser A pharser object for information extraction of strings.
         * 
         */
        Parser* parser;

        /**
         * \brief fast_atoi
         * 
         * \return int A integer converted by const char type.
         */
        int fast_atoi(const char*);

    public:

        /**
         * \brief DataAccess object constructor.
         * 
         */
        DataAccess(std::string);

        /**
         * \brief a DataAccess object destructor.
         * 
         */
        ~DataAccess();

        /**
         * \brief returnEdgesSetCardinality
         * 
         * \return int A integer edge set cardinality.
         */
        int returnEdgesSetCardinality();

        /**
         * \brief returnVerticesSetCardinality
         * 
         * \return int A integer vertices set cardinality.
         */
        int returnVerticesSetCardinality();

        /**
         * \brief returnGraphDescription
         * 
         * This method returns the graph text representation with all
         * edges wrote.
         * 
         * \return int** A integer matrix pointer with the whole graph information.
         */
        int** returnGraphDescription();

        /**
         * \brief getDataValidRowsAmount
         * 
         * \return int A integer valid rows amount counted.
         */
        int getDataValidRowsAmount();
};

#endif