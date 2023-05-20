#include "Graph.h"

Graph::Graph(int index){
    this->index = index;

    int number_nodes;
    switch(index) {
        case 0:
            number_nodes = GRAPH0_NODES;
            break;
        case 1:
            number_nodes = GRAPH1_NODES;
            break;
        case 2:
            number_nodes = GRAPH2_NODES;
            break;
        case 3:
            number_nodes = GRAPH3_NODES;
            break;
        case 4:
            number_nodes = GRAPH4_NODES;
            break;
        case 5:
            number_nodes = GRAPH5_NODES;
            break;
        default:
            cout << "Invalid graph index" << endl;
            return;
    }

    for(int i = 0; i < number_nodes; i++) {
        nodes.push_back(new Node(i));
    }
}

void Graph::loadEdges(string& path){
    ifstream file(path);

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    file.ignore(1000, '\n');
    string line;

    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            row.push_back(token);
        }

        int id1 = stoi(row[0]);
        int id2 = stoi(row[1]);
        double distance = stod(row[2]);

        Node *node1 = nodes[id1];
        Node *node2 = nodes[id2];

        Edge* edge = new Edge(id1, id2, distance);
        edges.push_back(edge);

        node1->addEdge(edge);
        node2->addEdge(edge);
    }
}

void Graph::loadToyGraph() {
    string path;

    switch (index) {
        case 0:
            path = GRAPH0_PATH;
            break;
        case 1:
            path = GRAPH1_PATH;
            break;
        case 2:
            path = GRAPH2_PATH;
            break;
        default:
            cout << "Invalid graph index" << endl;
            return;
    }

    loadEdges(path);
}

void Graph::loadRWGraph() {
    string folder;

    switch (index) {
        case 3:
            folder = GRAPH3_FOLDER;
            break;
        case 4:
            folder = GRAPH4_FOLDER;
            break;
        case 5:
            folder = GRAPH5_FOLDER;
            break;
        default:
            cout << "Invalid graph index" << endl;
            return;
    }

    string path = folder + "/edges.csv";

    loadEdges(path);
}

void Graph::load() {
    cout << "Loading graph " << index << endl;
    switch (index) {
        case 0:
        case 1:
        case 2:
            loadToyGraph();
            break;
        case 3:
        case 4:
        case 5:
            loadRWGraph();
            break;
        default:
            cout << "Invalid graph index" << endl;
            break;
    }
}


bool Graph::isLoaded() const {
    return !edges.empty();
}