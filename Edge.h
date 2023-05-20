#ifndef DA_PROJECT2_EDGE_H
#define DA_PROJECT2_EDGE_H


class Edge {
private:
    int node1;
    int node2;
    double distance;

public:
    Edge(int node1, int node2, double distance);
    int getNode1() const;
    int getNode2() const;
    double getDistance() const;
};


#endif //DA_PROJECT2_EDGE_H
