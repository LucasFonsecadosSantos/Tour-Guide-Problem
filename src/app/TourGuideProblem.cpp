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
#include "../include/Screen.h"
#include "../include/Graph.h"
#include "../include/DataAccess.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    
    DataAccess *data = new DataAccess(argv[1]);
    int verticesSetCardinality = data->returnVerticesSetCardinality();
    int edgesSetCardinality = data->returnEdgesSetCardinality();
    int functionsAmount = data->getDataValidRowsAmount();
    int **matrix = data->returnGraphDescription();
    //int** adjacencyMatrix = new int*[verticesSetCardinality];
    
    std::cout << "VERTICES "<<verticesSetCardinality << std::endl;
    std::cout << "EDGES "<<edgesSetCardinality << std::endl;
    std::cout << "rows "<<functionsAmount << std::endl;

    for(int i=0;i<functionsAmount; i++) {
        for(int j=0;j<3;j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Graph *graph = new Graph(verticesSetCardinality,edgesSetCardinality,matrix);
    
    int **matrix2 = graph->getAdjacencyMatrix();

    getPathMode mode = ALL;

    //minimizedResult* resultProcess = graph->getBestPathBetweenVertices(3,5,mode);
    
    std::cout << "MATRIZ ADJANCENCIA: " << std::endl;
    for(int i=0; i<verticesSetCardinality; i++) {
        for(int j=0; j<verticesSetCardinality; j++) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}