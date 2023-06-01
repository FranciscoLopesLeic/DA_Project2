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
            for (int j = progressBarCount; j < 100; ++j)
                cout << " ";
            cout << "] " << static_cast<int>(totalProgress+1) << "%";
            cout.flush();
            progress = 0.0;
        }
    }

    cout << endl;
}


void Graph::load() {
    cout << "\nLoading graph...";

    if(index <= 2 || index >= 6){
        loadNodesToyAndExtraGraph();
    }
    else{
        loadNodesRWGraph();
    }
    loadEdges();

    cout << "Graph loaded successfully!\n";
}


bool Graph::isLoaded() const {
    return !edges.empty();
}

void Graph::resetNodes() {
    for (Node* node : nodes) {
        node->setVisited(false);
        node->setPath(nullptr);
        node->setDistance(numeric_limits<double>::infinity());
    }
}

void Graph::TSP_Backtracking_aux(unsigned int curIndex, unsigned int count, double cost, double &ans, vector<unsigned int> &path, vector<vector<unsigned int>> paths){
    if (count == nodes.size()){
        for (auto e : nodes[curIndex]->getEdges()){
            if (e->getNode1() == 0 || e->getNode2() == 0){
                double new_cost = cost + e->getDistance();
                if (new_cost < ans){
                    ans = new_cost;
                    path = paths[curIndex];
                }
            }
        }
        return;
    }

    for (auto e : nodes[curIndex]->getEdges()){
        int nextPos = e->getNode1() == curIndex ? e->getNode2() : e->getNode1();
        if (!nodes[nextPos]->isVisited()){
            nodes[nextPos]->setVisited(true);
            paths[nextPos] = paths[curIndex];
            paths[nextPos].push_back(nextPos);

            TSP_Backtracking_aux(nextPos, count + 1, cost + e->getDistance(), ans, path, paths);
            nodes[nextPos]->setVisited(false);
        }
    }
}

pair<double, vector<unsigned int>> Graph::TSP_Backtracking(){
    resetNodes();
    nodes[0]->setVisited(true);

    double shortestDistance = std::numeric_limits<double>::max();
    vector<vector<unsigned int>> paths(nodes.size());
    vector<unsigned int> path(nodes.size());
    paths[0].push_back(0);

    TSP_Backtracking_aux(0, 1, 0, shortestDistance, path, paths);

    path.push_back(0);

    return make_pair(shortestDistance, path);
}

list<unsigned int> Graph::prim_generate_MST(){

    list<unsigned int> mst;

    MutablePriorityQueue<Node> q;

    for(auto node: nodes){
        node->setDistance(numeric_limits<double>::infinity());
        node->setPath(nullptr);
        node->setVisited(false);
        q.insert(node);
    }

    for(auto edge: edges){
        edge->setSelected(false);
    }

    Node* startNode = nodes[0];
    startNode->setDistance(0);
    q.decreaseKey(startNode);

    while(!q.empty()){
        Node* curNode = q.extractMin();
        curNode->setVisited(true);
        mst.push_back(curNode->getId());

        for(auto edge: curNode->getEdges()){
            int nextId = edge->getNode1() == curNode->getId() ? edge->getNode2() : edge->getNode1();
            Node* nextNode = nodes[nextId];

            if(!nextNode->isVisited() && edge->getDistance() < nextNode->getDistance()){
                nextNode->setDistance(edge->getDistance());
                nextNode->setPath(edge);
                q.decreaseKey(nextNode);
                edge->setSelected(true);
            }
        }
    }

    return mst;
}

void Graph::dfs_MST(unsigned int root, list<unsigned int> &path) {
    Node* curNode = nodes[root];
    curNode->setVisited(true);
    path.push_back(root);

    for(auto edge: curNode->getEdges()){
        int nextId = edge->getNode1() == curNode->getId() ? edge->getNode2() : edge->getNode1();
        Node* nextNode = nodes[nextId];

        if(!nextNode->isVisited() && edge->isSelected()){
            dfs_MST(nextId, path);
        }
    }
}

double Graph::getPathCost(list<unsigned int> path) const{
    double cost = 0;
    /*
    for(int i = 0; i < path.size() - 1; i++){
        Node* current = nodes[path[i]];
        Node* next = nodes[path[i+1]];

        Edge* edge = current->getEdgeTo(next);
        if(edge == nullptr && !this->isRW()){
            return -1;
        }
        cost += edge? edge->getDistance() : current->getHaversineDistanceTo(next);
    }
     */

    // iterate in list
    auto it = path.begin();
    auto it2 = path.begin();
    it2++;
    for (; it2 != path.end(); it++, it2++) {
        Node* current = nodes[*it];
        Node* next = nodes[*it2];

        Edge* edge = current->getEdgeTo(next);
        if(edge == nullptr && !this->isRW()){
            return -1;
        }
        cost += edge? edge->getDistance() : current->getHaversineDistanceTo(next);
    }
    return cost;
}

pair<double, list<unsigned int>> Graph::TSP_TriangularApproximation(){

    /*
    auto mst = prim_generate_MST();
    mst.push_back(0);
    double cost = getPathCost(mst);
    return make_pair(cost, mst);
     */


    prim_generate_MST();
    list<unsigned int> path;
    for (auto node : nodes) {
        node->setVisited(false);
    }
    dfs_MST(0, path);
    path.push_back(0);
    double cost = getPathCost(path);
    return make_pair(cost, path);

}

bool Graph::isRW() const {
    return index >= 3 && index <= 5;
}

bool Graph::isToy() const {
    return index <= 2;
}