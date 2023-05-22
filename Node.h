#ifndef DA_PROJECT2_NODE_H
#define DA_PROJECT2_NODE_H

#include <list>
#include <cmath>

#include "Edge.h"

using namespace std;

class Node {
public:
    Node(int id);
    Node(int id, double latitude, double longitude);
    int getId() const;
    list<Edge*> getEdges() const;
    void addEdge(Edge* edge);
    int getPrevious() const;
    void setPrevious(int prev);
    bool isVisited() const;
    void setVisited(bool v);
    double getLatitude() const;
    double getLongitude() const;
    double getHaversineDistanceTo(Node* node) const;
    double getDistanceToAdjacentNode(int id) const;

private:
    int id;
    double latitude;
    double longitude;
    list<Edge*> edges;
    int previous;
    bool visited;

};


#endif //DA_PROJECT2_NODE_H
