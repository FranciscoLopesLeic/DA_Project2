#include "Edge.h"
#include "Node.h"

Edge::Edge(Node* node1, Node* node2, double distance) : node1(node1), node2(node2), distance(distance) {}

Node* Edge::getNode1() const {
    return node1;
}

Node* Edge::getNode2() const {
    return node2;
}

double Edge::getDistance() const {
    return distance;
}

int Edge::getNode1Id() const {
    return node1->getId();
}

int Edge::getNode2Id() const {
    return node2->getId();
}
