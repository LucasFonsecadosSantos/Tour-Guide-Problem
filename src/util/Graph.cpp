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
#include "../include/Graph.h"
#include "../include/LinkedList.h"
#include "../include/Queue.h"

#include <iostream>
#include <cstddef>
/**
 * The graph object constructor. It receives by two parameters
 * a set vertex cardinality (integer) and a set edge cardinality
 * and sets this at object state attributes. It also allocates a new
 * adjacency matrix with all edge connections.
 * 
 * \param vertexCardinality An integer that represents a set vercice cardinality.
 * \param edgeCardinality An integer that represents a set edge cardinality.
 */
Graph::Graph(int vertexCardinality, int edgeCardinality) {
    this->vertexCardinality = vertexCardinality;
    this->edgeCardinality = edgeCardinality;
    this->adjacencyMatrix = new int*[this->vertexCardinality];
    for(int i=0; i<this->vertexCardinality; i++) {
        this->adjacencyMatrix[i] = new int[this->vertexCardinality];
    }
}

/**
 * \brief Graph
 * 
 * The graph object constructor overwrited.
 * 
 * \param vertexCardinality A integer vertex set cardinality value.
 * \param edgeCardinality A integer edge set cardinality value.
 * \param descriptionMatrix A integer description matrix pointer with the whole graph functions.
 */
Graph::Graph(int vertexCardinality, int edgeCardinality, int** descriptionMatrix) {
    this->vertexCardinality = vertexCardinality;
    this->edgeCardinality = edgeCardinality;
    this->adjacencyMatrix = new int*[this->vertexCardinality];
    for(int i = 0; i < this->vertexCardinality; i++) {
        this->adjacencyMatrix[i] = new int[this->vertexCardinality];
        for(int k = 0; k < this->vertexCardinality; k++) {
            this->adjacencyMatrix[i][k] = 0;
        }
    }
    this->matrixPadding(descriptionMatrix);
}

/**
 * The graph object destructor. This method unalloc this object
 * of machine memory pool.
 */
Graph::~Graph() {

}

/**
 * \brief matrixPadding
 * 
 * This method is responsible for padding the adjacency matrix of graph
 * receiving a integer matrix pointer with the whole graph description
 * inputed by the user. The graph has a not oriented edges, than, the matrix
 * padding is simetric padding. The adjcency matrix is a square matrix.
 * 
 * \param dataMatrix A integer description graph matrix pointer.
 */
void Graph::matrixPadding(int** dataMatrix) {
    for(int i = 0; i < this->edgeCardinality; i++) {
        for(int j = 0; j < this->edgeCardinality; j++) {
            this->adjacencyMatrix[dataMatrix[i][0]-1][dataMatrix[i][1]-1] = dataMatrix[i][2];
            //But, the problem describes two-way edges, than, it is a square matrix.
            this->adjacencyMatrix[dataMatrix[i][1]-1][dataMatrix[i][0]-1] = dataMatrix[i][2];
        }
    }
}

/**
 * \brief getAdjacencyMatrix
 * 
 * This is an access method that returns the graph
 * adjacency matrix attribute state.
 * 
 * /return int** A integer graph adjacency matrix pointer.
 */
int** Graph::getAdjacencyMatrix() {
    return this->adjacencyMatrix;
}

//return minimizedResult*
void Graph::getBestPathBetweenVertex(int v1, int v2, getPathMode mode) {
    
}

void Graph::BreadthFirstSearch(int sourceVertex, int targetVertex) {
    bool visitedVertex[this->vertexCardinality];
    bool iterationControl = true;
    int tmpVertex = sourceVertex;
    Stack* vertexBacktrackingStack = new Stack();
    LinkedList* vertexList = new LinkedList();
    LinkedList* edgeWeights = new LinkedList();
    
    for(int i = 0; i < this->vertexCardinality; i++)
        visitedVertex[i] = false;
    
    
        /*
    while(iterationControl) {
        if(!visitedVertex[sourceVertex]) {
            visitedVertex[sourceVertex] = true;
            vertexBacktrackingStack->push(vertex);
        }

        //recognizing the vertex neighborhood
        for(int i = 0; i < this->vertexCardinality; i++) {
            if(this->ajacencyMatrix[sourceVertex][i] > 0) {
                vertexList->add(i);
            }
        }
    }*/

}
