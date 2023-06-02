/**
 * @file Edge.h
 * @brief Edge class header file
 */

#ifndef DA_PROJECT2_EDGE_H
#define DA_PROJECT2_EDGE_H

#include <iostream>

/**
 * @brief Class that represents an edge
 */
class Edge {
private:
    int node1;/**< First node */
    int node2;/**< Second node */
    double distance;/**< Distance between the two nodes */
    bool selected;/**< True if the edge is selected, false otherwise */

public:
    /**
     * @brief Constructor of the class
     *
     * Time complexity: O(1)
     *
     * @param node1 First node
     * @param node2 Second node
     * @param distance Distance between the two nodes
     */
    Edge(int node1, int node2, double distance);
    /**
     * @brief Gets the first node
     *
     * Time complexity: O(1)
     *
     * @return First node
     */
    int getNode1() const;
    /**
     * @brief Gets the second node
     *
     * Time complexity: O(1)
     *
     * @return Second node
     */
    int getNode2() const;
    /**
     * @brief Gets the distance between the two nodes
     *
     * Time complexity: O(1)
     *
     * @return Distance between the two nodes
     */
    double getDistance() const;
    /**
     * @brief Gets if the edge is selected
     *
     * Time complexity: O(1)
     *
     * @return True if the edge is selected, false otherwise
     */
    bool isSelected() const;
    /**
     * @brief Sets if the edge is selected
     *
     * Time complexity: O(1)
     *
     * @param s True if the edge is selected, false otherwise
     */
    void setSelected(bool s);
    /**
     * @brief Prints the edge
     *
     * Time complexity: O(1)
     */
    void print();
};


#endif //DA_PROJECT2_EDGE_H
