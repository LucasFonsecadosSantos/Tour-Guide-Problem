/**
 * \file Graph.cpp
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
 * This files describes the graph data structure implementation 
 * with the object constructors and all methods implementation.
 */
#include "../Include/Graph.h"

/**
 * The graph object constructor. It receives by two parameters
 * a set vertice cardinality (integer) and a set edge cardinality
 * and sets this at object state attributes. It also allocates a new
 * adjacency matrix with all edge connections.
 * 
 * \param verticeCardinality An integer that represents a set vercice cardinality.
 * \param edgeCardinality An integer that represents a set edge cardinality.
 */
Graph::Graph(int verticeCardinality, int edgeCardinality) {
    this->verticeCardinality = verticeCardinality;
    this->edgeCardinality = edgeCardinality;
    this->adjacencyMatrix = new int*[this->verticeCardinality];
    for(int i=0; i<this->verticeCardinality; i++) {
        this->adjacencyMatrix[i] = new int[this->verticeCardinality];
    }
}

Graph::Graph(int verticeCardinality, int edgeCardinality, int** adjacencyMatrix) {
    this->verticeCardinality = verticeCardinality;
    this->edgeCardinality = edgeCardinality;
    this->adjacencyMatrix = adjacencyMatrix;
}

/**
 * The graph object destructor. This method unalloc this object
 * of machine memory pool.
 */
Graph::~Graph() {

}

void Graph::matrixPadding(int** dataMatrix) {
    for(int i=0; i<this->verticeCardinality; i++) {
        for(int j=0; j<this->verticeCardinality; j++) {
            this->adjacencyMatrix[i][j] == dataMatrix[i][j];
        }
    }
}