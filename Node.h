#ifndef DA_PROJECT2_NODE_H
#define DA_PROJECT2_NODE_H

#include <list>

#include "Edge.h"

using namespace std;

class Node {
public:
    Node(int id);
    int getId() const;
    list<Edge*> getEdges() const;
    void addEdge(Edge* edge);

private:
    int id;
    list<Edge*> edges;

};


#endif //DA_PROJECT2_NODE_H
