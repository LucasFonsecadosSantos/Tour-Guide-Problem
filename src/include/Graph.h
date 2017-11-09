/**
 * \file Graph.h
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
 * This files describes the graph data structure header with 
 * all methods prototypes and constants.
 */
#ifndef GRAPH_DATA_STRUCTURE_H
#define GRAPH_DATA_STRUCTURE_H 1

#include "LinkedList.h"

enum getPathMode {
    ALL, SINGLE
};

/**
 * \var minimizedResult
 * 
 * A strcut type with the minimized result.
 * It contains:
 * A vertice array;
 * A trip amount necessary to take all people;
 * A case index of result; (It is necessary for test case)
 */
typedef struct minimizedResult {
    LinkedList *vertices;
    int tripAmount;
    int caseIndex;
};

/**
 * \class Graph
 * 
 * \section CLASS DOCUMENTATION
 * 
 * This class describes a Graph data structure object. Into this, are
 * listed all methods and constructors prototypes with params and data returns.
 * It is used by the algorithm to solve the problem core producing by the object
 * a mathematical modeling with a graph. With the model, it is possible to apply
 * a lot of algorithms as Deep Search and others to solve the question 
 * with efficiency,
 */
class Graph {

    public:

        /**
         * \brief Graph data structure object constructor.
         * 
         * \param int A integer set vertice cardinality.
         * \param int A integer set edge cardinality.
         * \return A Graph data structureobject allocation at 
         * pool machine memory position.
         */
        Graph(int, int);

        /**
         * \brief Graph data structure object constructor overwrited.
         * 
         * This constructor fills the adjacency matrix attribute and
         * sets vertices set cardinality and edges set cardinality values.
         * 
         * \param int A integer set vertices set cardinality.
         * \param int A integer set edges set cardinality.
         * \param int** A integer matrix pointer with graph informations.
         */
        Graph(int, int, int**);

        /**
         * \brief Graph data structure object destructor.
         */
        ~Graph();

        /**
         * \brief setVerticeCardinality
         * 
         * This is vertices set cardinality state modifier method
         * of vertice set cardinality attribute.
         * 
         * @param int A integer vertices set cardinality value.
         * @return void
         */
        void setVerticeCardinality(int);

        /**
         * \brief setEdgeCardinality
         * 
         * This is edge set cardinality state modifier method
         * of edge set cardinality attribute.
         * 
         * @param int A integer edge set cardinality value.
         * @return void
         */
        void setEdgeCardinality(int);

        /**
         * \brief matrixPadding
         * 
         * It is a modifier method of adjacency matrix attribute.
         * 
         * @param int** A integer matrix pointer with all graph informations.
         * @return void
         */
        void matrixPadding(int**);

        int** getAdjacencyMatrix();

        minimizedResult* getBestPathBetweenVertices(int, int, getPathMode);

    
    private:
        
        /**
         * \var verticeCardinality
         * This variable contains the cardinality set value of Graph,
         * where graph is G=(V,E), such that V is a vertices set, where
         * |V| is the vertices set cardinality.
         */
        int verticeCardinality;

        /**
         * \var edgeCardinality
         * This variable contains the cardinality set value of Graph,
         * where graph is G=(V,E), such that E is a edges set, where
         * |E| is the edges set cardinality.
         */
        int edgeCardinality;

        /**
         * \var adjacencyMatrix
         * This is the literal graph description with all edges, represented
         * by the two terminal vertices connected, belonging the vertices set.
         */
        int** adjacencyMatrix;

        int** dynamicMatrixSimpleFactory(int, int);

        LinkedList* graphHiking(int, int, LinkedList*);
};

#endif