#include "Graph.h"

Graph::Graph(int index){
    this->index = index;
}

string Graph::getPath() const {
    switch (index) {
        case 0:
            return "../Data/Toy-Graphs/Toy-Graphs/shipping.csv";
        case 1:
            return "../Data/Toy-Graphs/Toy-Graphs/stadiums.csv";
        case 2:
            return "../Data/Toy-Graphs/Toy-Graphs/tourism.csv";
        case 3:
            return "../Data/Real-world Graphs/Real-world Graphs/graph1";
        case 4:
            return "../Data/Real-world Graphs/Real-world Graphs/graph2";
        case 5:
            return "../Data/Real-world Graphs/Real-world Graphs/graph3";
        default:
            cout << "Invalid graph index" << endl;
            return "";
    }
}

int Graph::getNumberNodes() const {
    switch (index) {
        case 0:
            return 14;
        case 1:
            return 11;
        case 2:
            return 5;
        case 3:
            return 1000;
        case 4:
            return 5000;
        case 5:
            return 10000;
        default:
            cout << "Invalid graph index" << endl;
            return 0;
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

void Graph::load() {
    cout << "Loading graph " << index << endl;

    int numberNodes = getNumberNodes();
    for(int i = 0; i < numberNodes; i++){
        Node *node = new Node(i);
        nodes.push_back(node);
    }

    string path = getPath();
    if(index > 2){
        path += "/edges.csv";
    }

    loadEdges(path);
}


bool Graph::isLoaded() const {
    return !edges.empty();
}