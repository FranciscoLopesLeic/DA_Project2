#ifndef DA_PROJECT2_EDGE_H
#define DA_PROJECT2_EDGE_H

#include <iostream>

class Edge {
private:
    int node1;
    int node2;
    double distance;
    bool selected;

public:
    Edge(int node1, int node2, double distance);
    int getNode1() const;
    int getNode2() const;
    double getDistance() const;
    bool isSelected() const;
    void setSelected(bool s);
    void print();
};


#endif //DA_PROJECT2_EDGE_H
