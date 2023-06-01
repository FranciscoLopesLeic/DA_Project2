#ifndef DA_PROJECT2_NODE_H
#define DA_PROJECT2_NODE_H

#include <list>
#include <cmath>

#include "Edge.h"

using namespace std;

class Node {
public:
    int queueIndex = 0;
    Node(int id);
    Node(int id, double latitude, double longitude);
    int getId() const;
    list<Edge*> getEdges() const;
    void addEdge(Edge* edge);
    bool isVisited() const;
    void setVisited(bool v);
    double getLatitude() const;
    double getLongitude() const;
    double getDistanceTo(Node* other) const;
    void setPath(Edge* p);
    Edge* getPath() const;
    void setDistance(double d);
    double getDistance() const;
    Edge* getEdgeTo(Node* node) const;
    double getHaversineDistanceTo(Node* node) const;

    bool operator<(Node& node) const;

private:
    int id;
    double latitude;
    double longitude;
    double distance;
    list<Edge*> edges;
    Edge* path;
    bool visited;
};


#endif //DA_PROJECT2_NODE_H
