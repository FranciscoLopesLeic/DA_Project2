#include "Node.h"

Node::Node(int id) {
    this->id = id;
    this->latitude = -1;
    this->longitude = -1;
    this->path = nullptr;
    this->visited = false;
    this->distance = numeric_limits<double>::infinity();
}

Node::Node(int id, double latitude, double longitude) {
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
    this->visited = false;
}

int Node::getId() const {
    return id;
}

list<Edge*> Node::getEdges() const {
    return edges;
}

void Node::addEdge(Edge* edge) {
    edges.push_back(edge);
}


bool Node::isVisited() const {
    return visited;
}

void Node::setVisited(bool v) {
    this->visited = v;
}

double Node::getLatitude() const {
    return latitude;
}

double Node::getLongitude() const {
    return longitude;
}

double Node::getDistanceTo(Node* other) const {
    int id2 = other->getId();
    for(Edge* edge : edges){
        if(edge->getNode1() == id2 || edge->getNode2() == id2){
            return edge->getDistance();
        }
    }
    return this->getHaversineDistanceTo(other);
}

double Node::getHaversineDistanceTo(Node* node) const {
    double lat1 = this->latitude;
    double lon1 = this->longitude;
    double lat2 = node->getLatitude();
    double lon2 = node->getLongitude();

    double R = 6371e3; // metres
    double phi1 = lat1 * M_PI / 180; // φ, λ in radians
    double phi2 = lat2 * M_PI / 180;
    double deltaPhi = (lat2-lat1) * M_PI / 180;
    double deltaLambda = (lon2-lon1) * M_PI / 180;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
            cos(phi1) * cos(phi2) *
            sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return R * c; // in metres
}

void Node::setPath(Edge* p){
    this->path = p;
}

Edge* Node::getPath() const {
    return path;
}

void Node::setDistance(double d){
    this->distance = d;
}

double Node::getDistance() const {
    return distance;
}

bool Node::operator<(Node& node) const {
    return this->distance < node.distance;
}
