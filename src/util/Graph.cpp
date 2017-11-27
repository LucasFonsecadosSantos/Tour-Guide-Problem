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
#include "../../include/Graph.h"
#include "../../include/LinkedList.h"

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

minimizedResult* Graph::getBestPathBetweenVertex(int sourceVertex, int targetVertex) {
    std::vector<bool> *whiteVertices = new std::vector<bool>();
    std::vector<bool> *grayVertices  = new std::vector<bool>();
    std::vector<bool> *blackVertices = new std::vector<bool>();
    std::vector<std::vector<int>*> *edgesWeightVectors = new std::vector<std::vector<int>*>();
    std::vector<int> *verticesStack = new std::vector<int>();

    for(unsigned i = 0 ; i < this->vertexCardinality ; i++) {
        whiteVertices->push_back(true);
        grayVertices->push_back(false);
        blackVertices->push_back(false);
    }

    if(whiteVertices->at(sourceVertex-1)) {
        edgesWeightVectors = DepthFirstSearch(sourceVertex, targetVertex, edgesWeightVectors, whiteVertices, grayVertices, blackVertices, verticesStack);
    }

    return getBestRoute(edgesWeightVectors, verticesStack);
}

std::vector<std::vector<int>*>* Graph::DepthFirstSearch(int u, int target, std::vector<std::vector<int>*> *edgesWeightVectors,std::vector<bool> *whiteVertices, std::vector<bool> *grayVertices, std::vector<bool> *blackVertices, std::vector<int> *verticesStack) {
    bool hasOcurrency;
    verticesStack->push_back(u);
    for(unsigned i = 0; i < whiteVertices->size(); i++) {
        if(!whiteVertices->at(i)) {
            hasOcurrency = true;
            break;
        }
    }
    if(!hasOcurrency) {
        edgesWeightVectors->push_back(new std::vector<int>());
    }
    hasOcurrency = false;
    whiteVertices->at(u-1) = false;
    grayVertices->at(u-1) = true;
    std::vector<int> *neighborhood = getNeighboringVertices(u-1);
    for(unsigned i = 0 ; i < neighborhood->size() ; i++) {
        if(neighborhood->at(i) == target) {
            //Add edge weight into edge weight vector for comparation after the algorithm execution;
            edgesWeightVectors->at(edgesWeightVectors->size()-1)->push_back(this->adjacencyMatrix[u-1][neighborhood->at(i)-1]);
            //It creates a new edge weight vector for new path
            edgesWeightVectors->push_back(new std::vector<int>(edgesWeightVectors->at(edgesWeightVectors->size()-1)->begin(),edgesWeightVectors->at(edgesWeightVectors->size()-1)->end()));
            //It removes the last edge weight of new path vector;
            edgesWeightVectors->at(edgesWeightVectors->size()-1)->pop_back();
            edgesWeightVectors->at(edgesWeightVectors->size()-1)->pop_back();
            break;
        }else {
            if(whiteVertices->at(neighborhood->at(i)-1)) {
                hasOcurrency = true;
                edgesWeightVectors->at(edgesWeightVectors->size()-1)->push_back(this->adjacencyMatrix[u-1][neighborhood->at(i)-1]);
                DepthFirstSearch(neighborhood->at(i), target, edgesWeightVectors, whiteVertices, grayVertices, blackVertices, verticesStack);
            }else {
                hasOcurrency = false;
            }
        }
    }
    if(!hasOcurrency) {
        edgesWeightVectors->at(edgesWeightVectors->size()-1)->pop_back();
        blackVertices->at(u-1) = true;
    }
    blackVertices->at(u-1) = true;
    whiteVertices->at(u-1) = false;
    grayVertices->at(u-1) = false;
    return edgesWeightVectors;
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

minimizedResult* Graph::getBestRoute(std::vector<std::vector<int>*> *edges, std::vector<int> *verticesStack) {
    edges->pop_back();
    std::vector<int> *tmpVector;
    int lowerValues[edges->size()];
    int lowerValue = 0;
    int vectorIndex = 0;
    for(unsigned i = 0 ; i < edges->size(); i++) {
        tmpVector = edges->at(i);
        lowerValue = tmpVector->at(0);
        for(unsigned y = 0 ; y < tmpVector->size(); y++) {
            if(lowerValue > tmpVector->at(y)) {
                lowerValue = tmpVector->at(y);
            }
        }
        lowerValues[i] = lowerValue;
    }
    lowerValue = lowerValues[0];
    for(unsigned i = 0 ; i < edges->size() ; i++) {
        if(lowerValue < lowerValues[i]) {
            lowerValue = lowerValues[i];
            vectorIndex = i;
        }
    }
    minimizedResult* result = new minimizedResult;
    result->caseIndex = 0;
    result->vertex = new std::vector<int>();
    std::cout << verticesStack->size() << std::endl;
    for(int i = 0 ; i < verticesStack->size(); i++) {
        result->vertex->push_back(verticesStack->at(i));
        verticesStack->pop_back();
    }
    return result;
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