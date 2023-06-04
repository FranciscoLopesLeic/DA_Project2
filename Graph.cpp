#include "Graph.h"
#include <functional>

Graph::Graph(int index){
    if(index < 0 || index > 17){
        throw invalid_argument("Invalid graph index");
    }
    this->index = index;
}


/*  FLAGS   */

bool Graph::isRW() const {
    return index >= 3 && index <= 5;
}

bool Graph::isToy() const {
    return index <= 2;
}

bool Graph::isExtra() const {
    return index >= 6 && index <= 17;
}

bool Graph::isLoaded() const {
    return !edges.empty();
}


/*  LOAD    */

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
    if (isRW()) {
        path += "/edges.csv";
    }
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    file.ignore(1000, '\n');
    string line;

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0);

    const double estimatedProgressUnit = static_cast<float>(fileSize) / 100.0;

    if(!isExtra())
        getline(file, line);

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


/*  BACKTRACKING ALGORITHM   */

void Graph::backtracking_aux(unsigned int curIndex, unsigned int count, double cost, double &ans, vector<unsigned int> &path, vector<vector<unsigned int>> paths){
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

            backtracking_aux(nextPos, count + 1, cost + e->getDistance(), ans, path, paths);
            nodes[nextPos]->setVisited(false);
        }
    }
}

pair<double, vector<unsigned int>> Graph::TSP_Backtracking(){
    for (auto node : nodes)
        node->setVisited(false);

    nodes[0]->setVisited(true);

    double shortestDistance = std::numeric_limits<double>::max();
    vector<vector<unsigned int>> paths(nodes.size());
    vector<unsigned int> path(nodes.size());
    paths[0].push_back(0);

    backtracking_aux(0, 1, 0, shortestDistance, path, paths);

    path.push_back(0);

    return make_pair(shortestDistance, path);
}


/*  TRIANGULAR APPROXIMATION HEURISTICS  */

void Graph::prim_generate_MST(){
    for (Node* node : nodes) {
        node->setVisited(false);
    }
    for (Edge* edge : edges) {
        edge->setSelected(false);
    }

    priority_queue<Edge*, vector<Edge*>, function<bool(Edge*, Edge*)>> pq
                                        ([](Edge* a, Edge* b) {return a->getDistance() > b->getDistance();});

    unsigned int sourceId = 0;
    nodes[sourceId]->setVisited(true);

    for (Edge* edge : nodes[sourceId]->getEdges()) {pq.push(edge);}

    while (!pq.empty()) {
        Edge *curEdge = pq.top();
        pq.pop();

        Node *source = curEdge->getNode1() == sourceId ? nodes[curEdge->getNode1()] : nodes[curEdge->getNode2()];
        Node *dest = curEdge->getNode1() == sourceId ? nodes[curEdge->getNode2()] : nodes[curEdge->getNode1()];

        sourceId = dest->getId();

        if (source->isVisited() && dest->isVisited())
            continue;

        curEdge->setSelected(true);
        dest->setVisited(true);

        for (Edge *edge: dest->getEdges()) {
            if (!edge->isSelected()) {
                pq.push(edge);
            }
        }
    }

    for (Node* node : nodes) {
        node->setVisited(false);
    }
}

void Graph::dfsMST(unsigned int curIndex, list<unsigned int> &path){
    Node* curNode = nodes[curIndex];
    curNode->setVisited(true);
    path.push_back(curNode->getId());

    for (Edge* edge : curNode->getEdges()) {
        if (edge->isSelected()) {
            Node* dest = edge->getNode1() == curNode->getId() ? nodes[edge->getNode2()] : nodes[edge->getNode1()];
            if (!dest->isVisited()) {
                dfsMST(dest->getId(), path);
            }
        }
    }
}

pair<double, list<unsigned int>> Graph::TSP_TriangularApproximation(){
    /*
    Triangular Approximation
    Step 1. Generate a minimum spanning tree T of G.
    Step 2. Perform a depth-first search of T, starting at an arbitrary vertex r.
    Step 3. Let L be the list of vertices visited in the order they are visited by the depth-first search.
    Step 4. Return the Hamiltonian cycle H = L + r.
    */

    prim_generate_MST();
    list<unsigned int> order;
    dfsMST(0, order);
    order.push_back(0);
    double cost = getPathCost(order);
    return make_pair(cost, order);
}


/*  NEAREST INSERTION HEURISTICS    */

pair<double, vector<unsigned int>> Graph::TSP_NearestInsertion() {

    /*
    Step 1. Start with a sub-graph consisting of node i only.
    Step 2. Find node r such that cir is minimal and form sub-tour i-r-i. O(n)
    Step 3. (Selection step) Given a sub-tour, find node r not in the sub-tour closest to any node j in the sub-tour; i.e. with minimal crj. O(n^2)
    Step 4. (Insertion step) Find the arc (i, j) in the sub-tour which minimizes cir + crj - cij . Insert r between i and j. O(n)
    Step 5. If all the nodes are added to the tour, stop. Else go to step 3

    Information from: https://www2.isye.gatech.edu/~mgoetsch/cali/VEHICLE/TSP/TSP009__.HTM
    */

    for(auto node : nodes){
        node->setVisited(false);
    }

    vector<unsigned int> path;
    path.push_back(0);
    nodes[0]->setVisited(true);

    unsigned int r = 0;
    double minCost = std::numeric_limits<double>::max();
    for (unsigned int i = 1; i < nodes.size(); i++) {
        auto edge = nodes[0]->getEdgeTo(nodes[i]);
        if(edge == nullptr) continue;
        double cost = edge->getDistance();
        if (cost < minCost) {
            minCost = cost;
            r = i;
        }
    }
    path.push_back(r);
    nodes[r]->setVisited(true);

    while (path.size() < nodes.size()) {
        r = 0;
        minCost = std::numeric_limits<double>::max();

        for (unsigned int k = 0; k < nodes.size(); k++) {
            if (!nodes[k]->isVisited()) {
                double nearestDist = std::numeric_limits<double>::max();
                for (unsigned int j : path) {
                    auto edge = nodes[j]->getEdgeTo(nodes[k]);
                    if(edge == nullptr) continue;
                    double dist = edge->getDistance();
                    if (dist < nearestDist) {
                        nearestDist = dist;
                        r = k;
                    }
                }
                if (nearestDist < minCost) {
                    minCost = nearestDist;
                }
            }
        }

        unsigned int insertionIndex = 0;
        double minInsertionCost = std::numeric_limits<double>::max();

        for (unsigned int i = 0; i < path.size() - 1; i++) {
            unsigned int j = i + 1;

            auto edge1 = nodes[path[i]]->getEdgeTo(nodes[r]);
            auto edge2 = nodes[r]->getEdgeTo(nodes[path[j]]);
            auto edge3 = nodes[path[i]]->getEdgeTo(nodes[path[j]]);

            if(edge1 == nullptr || edge2 == nullptr || edge3 == nullptr) return make_pair(-1, vector<unsigned int>());

            double insertionCost = edge1->getDistance() +
                                   edge2->getDistance() -
                                   edge3->getDistance();
            if (insertionCost < minInsertionCost) {
                minInsertionCost = insertionCost;
                insertionIndex = j;
            }
        }

        path.insert(path.begin() + insertionIndex, r);
        nodes[r]->setVisited(true);
    }

    path.push_back(0);
    double cost = getPathCost(path);
    return make_pair(cost, path);
}


/*  CALCULATE PATH'S TOTAL COST */

double Graph::getPathCost(list<unsigned int> path) const{
    double cost = 0;

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

double Graph::getPathCost(vector<unsigned int> path) const{
    double cost = 0;

    for (unsigned int i = 0; i < path.size() - 1; i++) {
        Node* current = nodes[path[i]];
        Node* next = nodes[path[i + 1]];

        Edge* edge = current->getEdgeTo(next);
        if(edge == nullptr && !this->isRW()){
            cout << "Edge not found: " << current->getId() << " -> " << next->getId() << endl;
            return -1;
        }
        cost += edge? edge->getDistance() : current->getHaversineDistanceTo(next);
    }
    return cost;
}