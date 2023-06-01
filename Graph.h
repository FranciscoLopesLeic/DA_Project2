#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

#include "Node.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"

using namespace std;


class Graph {
private:
    int index;

    void loadNodesToyAndExtraGraph();
    void loadNodesRWGraph();
    void loadEdges();
    void resetNodes();

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

    vector<unsigned int> prim_generate_MST();
    void dfs_MST(unsigned int root, vector<unsigned int> &path);
    double getPathCost(vector<unsigned int> path) const;
    pair<double, vector<unsigned int>> TSP_TriangularApproximation();
};


#endif //DA_PROJECT2_GRAPH_H
