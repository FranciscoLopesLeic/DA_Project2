#ifndef DA_PROJECT2_EDGE_H
#define DA_PROJECT2_EDGE_H

class Node;

class Edge {
private:
    Node* node1;
    Node* node2;
    double distance;

public:
    Edge(Node* node1, Node* node2, double distance);
    Node* getNode1() const;
    Node* getNode2() const;
    int getNode1Id() const;
    int getNode2Id() const;
    double getDistance() const;
};


#endif //DA_PROJECT2_EDGE_H
