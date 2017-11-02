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

        int** adjacencyMatrix;

    public:

        /**
         * \brief Graph data structure object constructor.
         * \param int A integer set vertice cardinality.
         * \param int A integer set edge cardinality.
         * \return A Graph data structureobject allocation at 
         * pool machine memory position.
         */
        Graph(int, int);

        /**
         * \brief Graph data structure object destructor.
         */
        ~Graph();

        void setVerticeCardinality(int);

        void setEdgeCardinality(int);

        void matrixPadding(int**);

};

#endif