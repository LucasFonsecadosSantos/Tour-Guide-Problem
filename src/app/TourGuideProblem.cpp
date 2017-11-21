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
#include "../include/Stack.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    
    DataAccess *data = new DataAccess(argv[1]);
    int vertexSetCardinality = data->getVertexSetCardinality();
    int edgesSetCardinality = data->getEdgesSetCardinality();
    int functionsAmount = data->getDataValidRowsAmount();
    int **matrix = data->getGraphDescription();
    //int** adjacencyMatrix = new int*[vertexSetCardinality];
    
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

    std::vector<int> *list = graph->BreadthFirstSearch(1,7);
    for(unsigned i = 0 ; i > list->size(); i++) {
        std::cout << list->at(i) << " as" << std::endl;
    }
    //if(list == NULL) {
      //  std::cout << "HOLLY";
   // }
    /*
    for(int i=1; i<=vertexSetCardinality; i++) {
        std::cout << i << ": " << list->get(i) << " ";
        std::cout << std::endl;
        list->remove(list->get(i));
    }
    
    std::cout << "MATRIZ ADJANCENCIA: " << std::endl;
    for(int i=0; i<vertexSetCardinality; i++) {
        for(int j=0; j<vertexSetCardinality; j++) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    return 0;
}