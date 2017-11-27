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
#include "../../include/model/Screen.h"
#include "../../include/model/Graph.h"
#include "../../include/util/DataAccess.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    
    DataAccess *data = new DataAccess(argv[1]);
    int vertexSetCardinality = data->getVertexSetCardinality();
    int edgesSetCardinality = data->getEdgesSetCardinality();
    int functionsAmount = data->getDataValidRowsAmount();
    //int travelersAmount = data->getPeopleAmount();
    //int targetVertex = data->getTargetVertex();
    //int sourceVertex = data->getSourceVertex();
    int **matrix = data->getGraphDescription();
    
    std::cout << "VERTICES "<<vertexSetCardinality << std::endl;
    std::cout << "EDGES "<<edgesSetCardinality << std::endl;
    std::cout << "rows "<<functionsAmount << std::endl;

    for(int i=0;i<functionsAmount; i++) {
        for(int j=0;j<3;j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Graph *graph = new Graph(vertexSetCardinality,edgesSetCardinality,matrix);
    
    int **matrix2 = graph->getAdjacencyMatrix();

    getPathMode mode = ALL;

    minimizedResult *result = graph->getBestPathBetweenVertex(3,7);
    result->tripAmount = 88;

    std::cout << result->caseIndex << std::endl;
    for(int i = 0 ; i < result->vertex->size(); i++) {
        std::cout << result->vertex->at(i) << " - ";
    }
    std::cout << std::endl << result->tripAmount;
    return 0;
}