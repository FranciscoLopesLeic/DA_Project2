/**
 * @file Node.h
 * @brief Definition of the Node class.
 */

#ifndef DA_PROJECT2_NODE_H
#define DA_PROJECT2_NODE_H

#include <list>
#include <cmath>

#include "Edge.h"

using namespace std;


/**
 * @class Node
 * @brief Represents a node in a graph.
 */
class Node {
public:
    int queueIndex = 0;

    /**
     * @brief Constructs a Node object with the given ID.
     *
     * @param id The ID of the node.
     *
     * Time complexity: O(1)
     */
    Node(int id);
    /**
     * @brief Constructs a Node object with the given ID, latitude, and longitude.
     *
     * @param id The ID of the node.
     * @param latitude The latitude coordinate of the node.
     * @param longitude The longitude coordinate of the node.
     *
     * Time complexity: O(1)
     */
    Node(int id, double latitude, double longitude);
    /**
     * @brief Gets the ID of the node.
     *
     * @return The ID of the node.
     *
     * Time complexity: O(1)
     */
    int getId() const;

    /**
     * @brief Gets a list of edges connected to the node.
     *
     * @return A list of edges connected to the node.
     *
     * Time complexity: O(1)
     */
    list<Edge*> getEdges() const;

    /**
     * @brief Adds an edge to the node's list of edges.
     *
     * @param edge The edge to be added.
     *
     * Time complexity: O(1)
     */
    void addEdge(Edge* edge);
    /**
     * @brief Checks if the node has been visited.
     *
     * @return True if the node has been visited, false otherwise.
     *
     * Time complexity: O(1)
     */
    bool isVisited() const;
    /**
     * @brief Sets the visited state of the node.
     *
     * @param v The visited state to be set.
     *
     * Time complexity: O(1)
     */
    void setVisited(bool v);
    /**
     * @brief Gets the latitude coordinate of the node.
     *
     * @return The latitude coordinate of the node.
     *
     * Time complexity: O(1)
     */
    double getLatitude() const;
    /**
     * @brief Gets the longitude coordinate of the node.
     *
     * @return The longitude coordinate of the node.
     *
     * Time complexity: O(1)
     */
    double getLongitude() const;
    /**
     * @brief Gets the distance to another node.
     *
     * @param other The other node.
     * @return The distance to the other node.
     *
     * Time complexity: O(E)
     */
    double getDistanceTo(Node* other) const;


    /**
     * @brief Sets the path (edge) from the previous node to this node.
     *
     * @param p The path (edge) to be set.
     *
     * Time complexity: O(1)
     */
    void setPath(Edge* p);

    /**
     * @brief Gets the path (edge) from the previous node to this node.
     *
     * @return The path (edge) from the previous node to this node.
     *
     * Time complexity: O(1)
     */
    Edge* getPath() const;

    /**
     * @brief Sets the distance from the starting node to this node.
     *
     * @param d The distance to be set.
     *
     * Time complexity: O(1)
     */
    void setDistance(double d);

    /**
     * @brief Gets the distance from the starting node to this node.
     *
     * @return The distance from the starting node to this node.
     *
     * Time complexity: O(1)
     */
    double getDistance() const;

    /**
     * @brief Gets the edge between this node and another node.
     *
     * @param node The other node.
     * @return The edge between this node and the other node, or nullptr if no edge exists.
     *
     * Time complexity: O(E)
     */
    Edge* getEdgeTo(Node* node) const;

    /**
     * @brief Calculates the Haversine distance between this node and another node.
     *
     * @param node The other node.
     * @return The Haversine distance between this node and the other node.
     *
     * Time complexity: O(1)
     */
    double getHaversineDistanceTo(Node* node) const;

    /**
     * @brief Overloaded less-than operator to compare nodes.
     *
     * @param node The node to compare with.
     * @return True if this node is less than the given node, false otherwise.
     *
     * Time complexity: O(1)
     */
    bool operator<(Node& node) const;

private:
    int id;/**< The ID of the node. */
    double latitude;/**< The latitude coordinate of the node. */
    double longitude;/**< The longitude coordinate of the node. */
    double distance;/**< The distance from the starting node to this node. */
    list<Edge*> edges;/**< A list of edges connected to the node. */
    Edge* path;/**< The path (edge) from the previous node to this node. */
    bool visited;/**< The visited state of the node. */
};


#endif //DA_PROJECT2_NODE_H
