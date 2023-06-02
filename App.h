/**
 * @file App.h
 * @brief App class header file
 */

#ifndef APP_H
#define APP_H

#include "Graph.h"

#include <chrono>

using namespace std;


/**
 * @brief Class that represents the application
 */
class App{
public:
    /**
    * @brief Constructor of the class
     *
     * Time complexity: O(1)
    */
    App();

    /**
     * @brief Runs the application
     *
     * Time complexity: O(1)
     */
    void run();

private:
    static const int NUMBER_GRAPHS = 18;/**< Number of graphs */

    vector<Graph*> graphs;/**< Vector of graphs */
    void menuOption1();/**< Menu option 1 */
    void menuOption2();/**< Menu option 2 */
    void menuOption3();/**< Menu option 3 */

    Graph* getGraphFromUser() const;/**< Gets a graph from the user */
};


#endif //APP_H