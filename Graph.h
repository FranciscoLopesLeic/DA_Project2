/**
 * @file Graph.h
 * @brief This file contains the declaration of the Graph class.
 */

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>

#include "Node.h"
#include "Edge.h"

using namespace std;

/**
 * @brief The Graph class represents a graph.
 */
class Graph {
private:
    int index;/**< Index of the graph */

    void loadNodesToyAndExtraGraph();/**< Loads the nodes of the toy and extra graphs */
    void loadNodesRWGraph();/**< Loads the nodes of the RW graph */
    void loadEdges();/**< Loads the edges of the graph */

    string getPath() const;/**< Gets the path of the graph file */

    vector<Node*> nodes;/**< Vector of nodes */
    vector<Edge*> edges;/**< Vector of edges */

public:
    /**
     * @brief Constructor of the class
     *
     * Time complexity: O(1)
     *
     * @param index Index of the graph
     */
    Graph(int index);
    /**
     * @brief Loads the graph by invoking appropriate functions based on the value of 'index'.
     *
     * O(max(numberNodes, N + M))
     */
    void load();
    /**
     * @brief Checks if the graph is loaded.
     *
     * @return True if the graph is loaded (has edges), false otherwise.
     *
     * Time complexity: O(1)
     */
    bool isLoaded() const;
    /**
     * @brief Returns the number of nodes based on the current graph index.
     *
     * @return The number of nodes in the graph based on the graph index.
     *
     * Time complexity: O(1)
     */
    int getNumberNodes() const;
    /**
     * @brief Checks if the graph is a read-write (RW) graph.
     *
     * @return True if the graph is a read-write (RW) graph, false otherwise.
     *
     * Time complexity: O(1)
     */
    bool isRW() const;
    /**
     * @brief Checks if the graph is a toy graph.
     *
     * @return True if the graph is a toy graph, false otherwise.
     *
     * Time complexity: O(1)
     */
    bool isToy() const;

    /**
     * @brief Auxiliary function for backtracking to find the shortest path visiting all nodes starting from a given index.
     *
     * @param curIndex The current index (position) in the graph being explored.
     * @param count The count of visited nodes in the current path.
     * @param cost The accumulated cost (distance) of the current path.
     * @param ans Reference to the variable storing the shortest path cost.
     * @param path Reference to the vector storing the nodes of the shortest path.
     * @param paths Vector of vectors storing the paths explored so far.
     *
     * Time complexity: O(N!)
     */
    void backtracking_aux(unsigned int curIndex, unsigned int count, double cost, double &ans, vector<unsigned int> &path, vector<vector<unsigned int>> paths);

    /**
     * @brief Solves the Traveling Salesman Problem (TSP) using the backtracking algorithm.
     *
     * @return A pair consisting of the shortest distance and the vector of node indices representing the shortest Hamiltonian cycle.
     *
     * Time complexity: O(N!)
     */
    pair<double, vector<unsigned int>> TSP_Backtracking();


    /**
     * @brief Generates the MST of the graph using Prim's algorithm.
     *
     * Time complexity: O(N + MlogM)
     */
    void prim_generate_MST();

    /**
     * @brief Performs a Depth-First Search (DFS) starting from a given index in the Minimum Spanning Tree (MST).
     *
     * @param curIndex The current index (position) in the MST being explored.
     * @param path Reference to the list storing the indices of visited nodes in the order they are visited.
     *
     * Time complexity: O(M)
     */
    void dfsMST(unsigned int curIndex, list<unsigned int> &path);

    /**
     * @brief Calculates the cost (distance) of a given path in the graph.
     *
     * @param path The list of node indices representing a path in the graph.
     * @return The cost (distance) of the path. Returns -1 if an invalid edge is encountered and the graph is not a read-write (RW) graph.
     *
     * Time complexity: O(P) being P the size of the path
     */
    double getPathCost(list<unsigned int> path) const;

    /**
     * @brief Solves the Traveling Salesman Problem (TSP) using the Triangular Approximation algorithm.
     *
     * @return A pair consisting of the shortest distance and the list of node indices representing the shortest Hamiltonian cycle.
     *
     * Time complexity: O(N + MlogM)
     */
    pair<double, list<unsigned int>> TSP_TriangularApproximation();

    /**
     * @brief Solves the Traveling Salesman Problem (TSP) using the Nearest Insertion algorithm.
     *
     * @return A pair consisting of the cost of the tour and the vector of node indices representing the tour.
     *
     * Time complexity: O(N^2)
     */
    pair<double, vector<unsigned int>> TSP_NearestInsertion();
};


#endif //DA_PROJECT2_GRAPH_H
