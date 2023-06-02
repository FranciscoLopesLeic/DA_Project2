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


class Graph {
private:
    int index;

    void loadNodesToyAndExtraGraph();
    void loadNodesRWGraph();
    void loadEdges();

    string getPath() const;

    vector<Node*> nodes;
    vector<Edge*> edges;

public:
    Graph(int index);
    void load();
    bool isLoaded() const;
    int getNumberNodes() const;
    bool isRW() const;
    bool isToy() const;

    void TSP_Backtracking_aux(unsigned int curIndex, unsigned int count, double cost, double &ans, vector<unsigned int> &path, vector<vector<unsigned int>> paths);
    pair<double, vector<unsigned int>> TSP_Backtracking();

    void prim_generate_MST();
    void dfsMST(unsigned int curIndex, list<unsigned int> &path);
    double getPathCost(list<unsigned int> path) const;
    pair<double, list<unsigned int>> TSP_TriangularApproximation();
};


#endif //DA_PROJECT2_GRAPH_H
