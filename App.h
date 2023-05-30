#ifndef APP_H
#define APP_H

#include "Graph.h"

#include <chrono>

using namespace std;

class App{
public:
    App();
    void run();

private:
    static const int NUMBER_GRAPHS = 18;

    vector<Graph*> graphs;
    void menuOption1();
    void menuOption2();
    void menuOption3();

    Graph* getGraphFromUser() const;
};


#endif //APP_H