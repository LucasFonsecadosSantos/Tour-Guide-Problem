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
    std::vector<bool> *partialVisitedState      = visitedVertexArrayFactory();
    std::vector<int> *neighborhood;
    bool iterationControl = true;
    bool hasOcurrency = false;
    int tmpValue = 0;
    int x = 0;

    while(!allVerticesHaveBeenVisited(visitedVertex, targetVertex)) {
        if(!visitedVertex->at(sourceVertex-1)) {

                if(!backtrackVerticesStack->empty()) {
                    std::cout << "TOPO: " << backtrackVerticesStack->top() << std::endl;
                    if(backtrackVerticesStack->top() != sourceVertex)
                        backtrackVerticesStack->push(sourceVertex);
                }else {
                    backtrackVerticesStack->push(sourceVertex);
                }
            
        }

        neighborhood = getNeighboringVertices(sourceVertex-1);
        
        if(neighborhood->size() > 0) {
            for(unsigned i = 0 ; i < neighborhood->size() ; i++) {
                if(!visitedVertex->at(neighborhood->at(i)-1) && !searchOnStack(sourceVertex, backtrackVerticesStack)) {
                    //TEM VISINHO PRA SER VISITADO
                    //empilha peso da aresta
                    std::cout << "SOURCE: " << sourceVertex << " NEI: " << neighborhood->at(i) << std::endl;
                    hasOcurrency = true;
                    sourceVertex = neighborhood->at(i);
                    backtrackVerticesStack->push(sourceVertex);
                    break;
                }else {
                    //ESSE VIZINHO JA NAO PODE SER VISITADO
                    hasOcurrency = false;
                }
            }
            if(!hasOcurrency) {
                //TOODS OS VIZINHOS JA FORAM VISITADOS
                visitedVertex->at(sourceVertex-1) = true;
                backtrackVerticesStack->pop();
                if(!backtrackVerticesStack->empty()) {
                    sourceVertex = backtrackVerticesStack->top();
                }
            }
        }else {
            //NAO TEM VIZINHO
            visitedVertex->at(sourceVertex-1) = true;
            backtrackVerticesStack->pop();
            if(!backtrackVerticesStack->empty()) {
                sourceVertex = backtrackVerticesStack->top();
            }
        }

        
    }
    

    //std::vector<int> *bestRoute = getBestRoute(edgeStacks);
    return NULL;
}

bool Graph::searchOnStack(int element, std::stack<int> *stack) {
    std::stack<int>* tmpStack = new std::stack<int>();
    bool contains = false;
    while(!stack->empty()) {
        if(element == stack->top()) {
            contains = true;
        }
        tmpStack->push(stack->top());
        stack->pop();
    }
    while(!tmpStack->empty()) {
        stack->push(tmpStack->top());
        tmpStack->pop();
    }
    delete tmpStack;
    return contains;
}

std::vector<int>* Graph::getBestRoute(std::vector<std::stack<int>*> *stacks) {
   
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

bool Graph::allVerticesHaveBeenVisited(std::vector<bool> *visitedVerticesArray, int targetVertex) {
    int visitedVertexCounter = 0;
    for(unsigned i = 0; i < visitedVerticesArray->size(); i++) {
        if((visitedVerticesArray->at(i) == true) && (visitedVerticesArray->at(i) != targetVertex)) {
            visitedVertexCounter++;
        }
    }
    if(visitedVertexCounter == visitedVerticesArray->size()-1) {
        return true;
    }else {
        return false;
    }
  
}