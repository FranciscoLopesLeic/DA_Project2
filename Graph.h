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

    void loadNodesToyGraph();
    void loadNodesRWGraph();
    void loadEdges();

    string getPath() const;
    int getNumberNodes() const;

    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    Graph(int index);
    void load();
    bool isLoaded() const;

    unsigned int tspBT(const unsigned int **dists, unsigned int path[]);
    void tspBTRec(const unsigned int **dists, unsigned int n, unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int &minDist, unsigned int path[]);
};


#endif //DA_PROJECT2_GRAPH_H
