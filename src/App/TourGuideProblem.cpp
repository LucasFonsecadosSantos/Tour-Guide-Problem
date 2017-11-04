/**
 * \file TourGuideProblem.cpp
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
 * This file contains ...
 */
#include "../Include/Screen.h"
#include "../Include/Graph.h"
#include "../Include/DataAccess.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

    DataAccess* data = new DataAccess(argv[1]);
    //data->returnEdgesSetCardinality();
    //data->returnVerticesSetCardinality();
    int** matrix = data->returnGraphDescription();

    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            std::cout << "MATRIX: " <<matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}