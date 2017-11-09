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

Graph::Graph(int verticeCardinality, int edgeCardinality, int** descriptionMatrix) {
    this->verticeCardinality = verticeCardinality;
    this->edgeCardinality = edgeCardinality;
    this->adjacencyMatrix = new int*[this->verticeCardinality];
    for(int i = 0; i < this->verticeCardinality; i++) {
        this->adjacencyMatrix[i] = new int[this->verticeCardinality];
        for(int k = 0; k < this->verticeCardinality; k++) {
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

void Graph::matrixPadding(int** dataMatrix) {
    for(int i = 0; i < this->edgeCardinality; i++) {
        for(int j = 0; j < this->edgeCardinality; j++) {
            this->adjacencyMatrix[dataMatrix[i][0]-1][dataMatrix[i][1]-1] = dataMatrix[i][2];
            //But, the problem describes two-way edges, than, it is a square matrix.
            this->adjacencyMatrix[dataMatrix[i][1]-1][dataMatrix[i][0]-1] = dataMatrix[i][2];
        }
    }
}

int** Graph::getAdjacencyMatrix() {
    return this->adjacencyMatrix;
}

minimizedResult* Graph::getBestPathBetweenVertices(int v1, int v2, getPathMode mode) {
    
    LinkedList *vertexList = new LinkedList();
    minimizedResult *result = new minimizedResult;
    result->vertices = vertexList;
    result->caseIndex = result->tripAmount = 0;
    vertexList = graphHiking(v1,v2, vertexList);

    return result;
}

LinkedList* Graph::graphHiking(int vertex_1, int vertex_2, LinkedList *vertexList) {
    if(vertex_1 == vertex_2) {
        vertexList->add(vertex_1);
        return vertexList;
    }else {
        int biggerValue = 0;
        int tmpVertex = 0;
        for(int i = 0; i < this->verticeCardinality; i++) {
            if(this->adjacencyMatrix[vertex_1-1][i] > biggerValue) {
                biggerValue = this->adjacencyMatrix[vertex_1-1][i];
                tmpVertex = i+1;
                graphHiking(i+1,vertex_2, vertexList);
            }
        }
    }
}
