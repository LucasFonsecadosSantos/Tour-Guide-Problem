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

#include <vector>
#include <stack>

enum getPathMode {
    ALL, SINGLE
};

/**
 * \var minimizedResult
 * 
 * A strcut type with the minimized result.
 * It contains:
 * A vertex array;
 * A trip amount necessary to take all people;
 * A case index of result; (It is necessary for test case)
 */
struct minimizedResult {
    std::vector<int> *vertex;
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
         * \param int A integer set vertex cardinality.
         * \param int A integer set edge cardinality.
         * \return A Graph data structureobject allocation at 
         * pool machine memory position.
         */
        Graph(int, int);

        /**
         * \brief Graph data structure object constructor overwrited.
         * 
         * This constructor fills the adjacency matrix attribute and
         * sets vertex set cardinality and edges set cardinality values.
         * 
         * \param int A integer set vertex set cardinality.
         * \param int A integer set edges set cardinality.
         * \param int** A integer matrix pointer with graph informations.
         */
        Graph(int, int, int**);

        /**
         * \brief Graph data structure object destructor.
         */
        ~Graph();

        /**
         * \brief setV'erticeCardinality
         * 
         * This is vertex set cardinality state modifier method
         * of vertex set cardinality attribute.
         * 
         * \param int A integer vertex set cardinality value.
         * \return void
         */
        void setVertexCardinality(int);

        /**
         * \brief setEdgeCardinality
         * 
         * This is edge set cardinality state modifier method
         * of edge set cardinality attribute.
         * 
         * \param int A integer edge set cardinality value.
         * \return void
         */
        void setEdgeCardinality(int);

        /**
         * \brief matrixPadding
         * 
         * It is a modifier method of adjacency matrix attribute.
         * 
         * \param int** A integer matrix pointer with all graph informations.
         * \return void
         */
        void matrixPadding(int**);

        int** getAdjacencyMatrix();

        minimizedResult* getBestPathBetweenVertex(int, int);

    
    private:
        
        /**
         * \var vertexCardinality
         * This variable contains the cardinality set value of Graph,
         * where graph is G=(V,E), such that V is a vertex set, where
         * |V| is the vertex set cardinality.
         */
        int vertexCardinality;

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
         * by the two terminal vertex connected, belonging the vertex set.
         */
        int** adjacencyMatrix;

        minimizedResult* getBestRoute(std::vector<std::vector<int>*>*, std::vector<int>*);

        std::vector<bool>* visitedVertexArrayFactory();
        
        std::vector<int>* getNeighboringVertices(int);
        
        bool searchOnStack(int,std::stack<int>*);
        
        std::vector<std::vector<int>*>* DepthFirstSearch(int u,int target, std::vector<std::vector<int>*> *edgesWeightVectors,std::vector<bool>*whiteVertices, std::vector<bool> *grayVertices, 
        std::vector<bool> *blackVertices, std::vector<int> *verticesStack);
        
        bool allVerticesHaveBeenVisited(std::vector<bool>*, int);
        
        int** dynamicMatrixSimpleFactory(int, int);
};

#endif