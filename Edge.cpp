#include "Edge.h"

Edge::Edge(int node1, int node2, double distance) : node1(node1), node2(node2), distance(distance) {
    this->selected = false;
}

int Edge::getNode1() const {
    return node1;
}

int Edge::getNode2() const {
    return node2;
}

double Edge::getDistance() const {
    return distance;
}

bool Edge::isSelected() const {
    return selected;
}

void Edge::setSelected(bool s) {
    this->selected = s;
}
