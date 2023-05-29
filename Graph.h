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

    string getPath() const;

    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    Graph(int index);
    void load();
    bool isLoaded() const;

    int getNumberNodes() const;

    unsigned int TSP_Backtracking(unsigned int path[]);
    void tspBTRec(unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int& minDist, unsigned int path[]);
};


#endif //DA_PROJECT2_GRAPH_H
