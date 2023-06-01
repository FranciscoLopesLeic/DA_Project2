#include "Node.h"

Node::Node(int id) {
    this->id = id;
    this->latitude = 0;
    this->longitude = 0;
    this->path = nullptr;
    this->visited = false;
    this->distance = numeric_limits<double>::infinity();
}

Node::Node(int id, double latitude, double longitude) {
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
    this->path = nullptr;
    this->visited = false;
    this->distance = numeric_limits<double>::infinity();
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
            edge->print();
            return edge->getDistance();
        }
    }
    return this->getHaversineDistanceTo(other);
}

double Node::getHaversineDistanceTo(Node* node) const {

    double rad_lat1 = this->latitude * M_PI / 180;
    double rad_lon1 = this->longitude * M_PI / 180;
    double rad_lat2 = node->getLatitude() * M_PI / 180;
    double rad_lon2 = node->getLongitude() * M_PI / 180;
    double delta_lat = rad_lat2 - rad_lat1;
    double delta_lon = rad_lon2 - rad_lon1;
    double aux = pow(sin(delta_lat/2), 2) + cos(rad_lat1) * cos(rad_lat2) * pow(sin(delta_lon/2), 2);
    double c = 2.0 * atan2(sqrt(aux), sqrt(1.0-aux));
    double earthradius = 6371000;
    return earthradius * c;
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

Edge* Node::getEdgeTo(Node* node) const {
    int id2 = node->getId();
    for(Edge* edge : edges){
        if(edge->getNode1() == id2 || edge->getNode2() == id2){
            return edge;
        }
    }
    return nullptr;
}