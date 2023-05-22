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

    void loadEdges(string& path);

    string getPath() const;
    int getNumberNodes() const;

    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    Graph(int index);

    void load();

    bool isLoaded() const;
};


#endif //DA_PROJECT2_GRAPH_H
