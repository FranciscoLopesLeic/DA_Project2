#include "Graph.h"

Graph::Graph(int index){
    if(index < 0 || index > 17){
        throw invalid_argument("Invalid graph index");
    }
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
        case 6:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_25.csv";
        case 7:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_50.csv";
        case 8:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_75.csv";
        case 9:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_100.csv";
        case 10:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_200.csv";
        case 11:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_300.csv";
        case 12:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_400.csv";
        case 13:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_500.csv";
        case 14:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_600.csv";
        case 15:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_700.csv";
        case 16:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_800.csv";
        case 17:
            return "../Data/Extra_Fully_Connected_Graphs/Extra_Fully_Connected_Graphs/edges_900.csv";
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
        case 6:
            return 25;
        case 7:
            return 50;
        case 8:
            return 75;
        case 9:
            return 100;
        case 10:
            return 200;
        case 11:
            return 300;
        case 12:
            return 400;
        case 13:
            return 500;
        case 14:
            return 600;
        case 15:
            return 700;
        case 16:
            return 800;
        case 17:
            return 900;
        default:
            cout << "Invalid graph index" << endl;
            return 0;
    }
}

void Graph::loadNodesToyAndExtraGraph() {
    int numberNodes = getNumberNodes();

    for(int i = 0; i < numberNodes; i++){
        Node* node = new Node(i);
        nodes.push_back(node);
    }
}

void Graph::loadNodesRWGraph() {
    string path = getPath() + "/nodes.csv";

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

        int id = stoi(row[0]);
        double longitude = stod(row[1]);
        double latitude = stod(row[2]);

        Node* node = new Node(id, latitude, longitude);
        nodes.push_back(node);
    }
}
void Graph::loadEdges() {
    string path = getPath();
    if (index > 2 && index < 6) {
        path += "/edges.csv";
    }
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    file.ignore(1000, '\n');
    string line;

    // Get the total number of lines in the file (estimate)
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0);

    // Estimate the progress based on the file size
    const double estimatedProgressUnit = static_cast<float>(fileSize) / 100.0;

    // Skip the header line
    getline(file, line);

    // Loading edges
    float progress = 0.0;
    float totalProgress = 0.0;

    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            row.push_back(token);
        }

        int id1 = stoi(row[0]);
        int id2 = stoi(row[1]);
        double distance = stod(row[2]);

        Node* node1 = nodes[id1];
        Node* node2 = nodes[id2];

        Edge* edge = new Edge(id1, id2, distance);
        edges.push_back(edge);

        node1->addEdge(edge);
        node2->addEdge(edge);

        progress += line.size() + 1; // Add the size of the line plus the newline character

        //Update progress bar
        if (progress >= estimatedProgressUnit && index > 2 && index < 6) {
            totalProgress += (progress / estimatedProgressUnit);
            int progressBarCount = static_cast<int>(totalProgress);
            cout << "\r" << "[";
            for (int j = 0; j < progressBarCount; ++j)
                cout << "#";
            for (int j = progressBarCount; j < 50; ++j)
                cout << " ";
            cout << "] " << static_cast<int>(totalProgress+1) << "%";
            cout.flush();
            progress = 0.0;
        }
    }

    cout << endl;
}


void Graph::load() {
    cout << "Loading graph " << index << endl;

    if(index <= 2 || index >= 6){
        loadNodesToyAndExtraGraph();
    }
    else{
        loadNodesRWGraph();
    }
    loadEdges();
}


bool Graph::isLoaded() const {
    return !edges.empty();
}

void Graph::tspBTRec(unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int& minDist, unsigned int path[]) {
    if (curIndex == getNumberNodes()) {
        // add the distance back to the initial node
        curDist += nodes[curPath[getNumberNodes() - 1]]->getDistanceToAdjacentNode(curPath[0]);
        if (curDist < minDist) {
            minDist = curDist;
            // Copy the current state to the array storing the best state found so far
            for (unsigned int i = 0; i < getNumberNodes(); i++) {
                path[i] = curPath[i];
            }
        }
        return;
    }
    // Try to move to the i-th vertex if the total distance does not exceed the best distance found and the vertex is not yet visited in curPath
    for (const Edge* edge : nodes[curPath[curIndex - 1]]->getEdges()) {
        unsigned int i = (edge->getNode1() == curPath[curIndex - 1]) ? edge->getNode2() : edge->getNode1();
        if (!nodes[i]->isVisited() && curDist + edge->getDistance() < minDist) {
            nodes[i]->setVisited(true);
            curPath[curIndex] = i;
            tspBTRec(curIndex + 1, curDist + edge->getDistance(), curPath, minDist, path);
            nodes[i]->setVisited(false);
        }
    }
}

unsigned int Graph::TSP_Backtracking(unsigned int path[]) {
    unsigned int curPath[getNumberNodes()]; // static memory allocation is faster :)
    unsigned int minDist = std::numeric_limits<unsigned int>::max();

    // Assumes path starts at node 0 ...
    curPath[0] = 0;
    nodes[0]->setVisited(true);
    // ... so in the first recursive call curIndex starts at 1 rather than 0
    tspBTRec(1, 0, curPath, minDist, path);
    nodes[0]->setVisited(false);
    return minDist;
}


