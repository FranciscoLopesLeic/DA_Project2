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

    void TSP_Backtracking_aux(unsigned int curIndex, unsigned int count, double cost, double &ans, vector<unsigned int> &path, vector<vector<unsigned int>> paths);
    pair<double, vector<unsigned int>> TSP_Backtracking();
};


#endif //DA_PROJECT2_GRAPH_H
