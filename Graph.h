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

    // paths to the csv files
    const string GRAPH0_PATH = "../Data/Toy-Graphs/Toy-Graphs/shipping.csv";
    const int GRAPH0_NODES = 14;
    const string GRAPH1_PATH = "../Data/Toy-Graphs/Toy-Graphs/stadiums.csv";
    const int GRAPH1_NODES = 11;
    const string GRAPH2_PATH = "../Data/Toy-Graphs/Toy-Graphs/tourism.csv";
    const int GRAPH2_NODES = 5;

    const string GRAPH3_FOLDER = "../Data/Real-world Graphs/Real-world Graphs/graph1";
    const int GRAPH3_NODES = 1000;
    const string GRAPH4_FOLDER = "../Data/Real-world Graphs/Real-world Graphs/graph2";
    const int GRAPH4_NODES = 5000;
    const string GRAPH5_FOLDER = "../Data/Real-world Graphs/Real-world Graphs/graph3";
    const int GRAPH5_NODES = 10000;

    void loadEdges(string& path);
    void loadToyGraph();
    void loadRWGraph();

    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    Graph(int index);

    void load();

    bool isLoaded() const;
};


#endif //DA_PROJECT2_GRAPH_H
