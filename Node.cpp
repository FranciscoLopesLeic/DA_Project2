#include "Node.h"

Node::Node(int id) : id(id) {}

int Node::getId() const {
    return id;
}

list<Edge*> Node::getEdges() const {
    return edges;
}

void Node::addEdge(Edge* edge) {
    edges.push_back(edge);
}