/**
 * \file Pharser.h
 * \date 05/11/2017
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
 * This file describes the Pharser object, responsible for identifying
 * multiples tokens and parts on specifc string.
 * After this verification, it returns to the caller method all information
 * coleted by your methods.
 */
#ifndef PHARSER_OBJECT_H
#define PHARSER_OBJECT_H 1

#include <string>

/**
 * \class Pharser
 * 
 * This class represents the Pharser object, responsible for identifying
 * multiples tokens and parts on specifc string.
 * After this verification, it returns to the caller method all information
 * coleted by your methods.
 */
class Pharser {
    private:
    public:
        
        /**
         * \brief Pharser object constructor.
         */
        Pharser();

        /**
         * \brief Pharser object destructor.
         */
        ~Pharser();

        /**
         * \brief getTokens method prototype.
         * 
         * It is repsonsible for colleting the information
         * by a received string and return this.
         */
        std::string* getTokens(std::string);

        /**
         * \brief 
         * 
         * @param std::string 
         * @return int 
         */
        int tokensCounter(std::string);
};

#endif