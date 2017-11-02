/**
 * \file Screen.h
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
 * This file describes the screen object header with all methods prototypes
 * and constants used by this object.
 */
#ifndef SCREEN_OBJECT_H
#define SCREEN_OBJECT_H 1

/**
 * \class Screen
 * 
 * \section CLASS DOCUMENTATION
 * 
 * This class describes the Screen object used by the algorithm to print
 * out all processing results and states. This is a simple object
 * with few methods and simple implementations only for the screen manager,
 * used for increase the class cohesion.
 */
class Screen {
    
    private:

    public:
        
        /**
         * @brief Screen Constructor
         * 
         * @return The object allocation on memory pool of machine.
         */
        Screen();

        /**
         * @brief Screen object destructor.
         */
        ~Screen();

        /**
         * @brief Screen showResults() method prototype.
         * 
         * @return void
         */
        void ShowResults();
};

#endif