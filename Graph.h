#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "Edge.h"

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

    double TSP_Backtracking(unsigned int startingNode, vector<unsigned int>& path);
    void TSP_BT_rec(unsigned int visitedNodes, unsigned int curIndex, double curDist, vector<unsigned int>& curPath, double& minDist, vector<unsigned int>& path);
};


#endif //DA_PROJECT2_GRAPH_H
