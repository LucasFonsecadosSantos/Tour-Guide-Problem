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
//#include "../include/Stack.h"

#include <stack>
#include <vector>
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

std::vector<int>* Graph::BreadthFirstSearch(int sourceVertex, int targetVertex) {
    std::vector<std::stack<int>*> *edgeStacks  = new std::vector<std::stack<int>*>();
    std::stack<int>   *backtrackVerticesStack   = new std::stack<int>();
    std::stack<int>   *backtrackEdgeWeightStack = new std::stack<int>();
    std::vector<bool> *visitedVertex            = visitedVertexArrayFactory();
    bool iterationControl = true;
    int tmpValue = 0;
    int x = 0;

    while(!allVerticesHaveBeenVisited(visitedVertex)) {
    
        //The source vertex will be checked as a visited vertex;
        if(!visitedVertex->at(sourceVertex-1)) {
            visitedVertex->at(sourceVertex-1) = true;
            edgeStacks->push_back(new std::stack<int>());
            backtrackVerticesStack->push(sourceVertex);
        }

        tmpValue = backtrackVerticesStack->top();
        std::vector<int> *neighborhood = getNeighboringVertices(backtrackVerticesStack->top()-1);

        /*
        for(unsigned i = 0 ; i < visitedVertex->size(); i++) {
            if(visitedVertex->at(i)) {
                std::cout << "1" << std::endl;
            }else {
                std::cout << "0" << std::endl;
            }
            std::cout << std::endl << std::endl;
        }*/
        for(unsigned i = 0; i < neighborhood->size(); i++) {
            if(!visitedVertex->at(neighborhood->at(i)-1)) {
                std::cout << "SOURCE VERTEX: " << sourceVertex << " VIZINHO: " << neighborhood->at(i) << std::endl;
                backtrackVerticesStack->push(neighborhood->at(i));
                edgeStacks->at(edgeStacks->size()-1)->push(this->adjacencyMatrix[tmpValue-1][neighborhood->at(i)-1]);
                sourceVertex = neighborhood->at(i);
                break;
            } else if(sourceVertex == targetVertex) {
                backtrackVerticesStack->pop();
                sourceVertex = backtrackVerticesStack->top();
            }
        }


    }

    std::vector<int> *bestRoute = getBestRoute(edgeStacks);
    return bestRoute;
}

std::vector<int>* Graph::getBestRoute(std::vector<std::stack<int>*> *stacks) {
    std::vector<int> *bestRoute = new std::vector<int>();
    int lowerValue = 0;
    int latestLowerValue = 0;
    int element = 0;
    int stackIndex = 0;
    for(unsigned i = 0; i < stacks->size(); i++) {
        while(!stacks->at(i)->empty()) {
            element = stacks->at(i)->top();
            stacks->at(i)->pop();
            if(lowerValue < element) {
                lowerValue = element;
            }
        }
        if(latestLowerValue > lowerValue) {
            stackIndex = i;
        }
        latestLowerValue = lowerValue;
    }
    std::stack<int>* tmpStack = stacks->at(stackIndex);
    while(!tmpStack->empty()) {
        bestRoute->push_back(tmpStack->top());
        tmpStack->pop();
    }
    return bestRoute;
}

std::vector<int>* Graph::getNeighboringVertices(int vertex) {
    std::vector<int> *neighborhood = new std::vector<int>();
    for(int j = 0; j < this->vertexCardinality; j++) {
        if(this->adjacencyMatrix[vertex][j] > 0) {
            neighborhood->push_back(j+1);
        }
    }
    return neighborhood;
}

std::vector<bool>* Graph::visitedVertexArrayFactory() {
    std::vector<bool> *visitedVertex = new std::vector<bool>();
    for(int i = 0; i < this->vertexCardinality; i++) {
        visitedVertex->push_back(false);
    }
    return visitedVertex;
}

bool Graph::allVerticesHaveBeenVisited(std::vector<bool> *visitedVerticesArray) {
    int visitedVertexCounter = 0;
    for(unsigned i = 0; i < visitedVerticesArray->size(); i++) {
        if(visitedVerticesArray->at(i) == true) {
            visitedVertexCounter++;
        }
    }
    if(visitedVertexCounter == visitedVerticesArray->size()) {
        return true;
    }else {
        return false;
    }
  
}