#include <iostream>

#include "App.h"

App::App() {
    for(int i = 0; i < NUMBER_GRAPHS; i++){
        graphs.push_back(new Graph(i));
    }
}


void App::run() {
    while (true) {
        cout << "SELECT A STRATEGY:\n";
        cout << "1. Backtracking algorithm\n";
        cout << "2. Triangular Approximation\n";
        cout << "3. Our heuristics\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";

        int choice = getOptionFromUser();

        switch (choice) {
            case 1:
                menuOption1();
                break;
            case 2:
                menuOption2();
                break;
            case 3:
                menuOption3();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int App::getOptionFromUser() const {
    int choice;
    cin >> choice;
    return choice;
}

Graph* App::getGraphFromUser() const {
    cout << "SELECT A GRAPH:\n";
    cout << ">> 0-2 are toy graphs\n";
    cout << ">> 3-5 are real-world graphs\n";
    cout << ">> 6-17 are extra graphs\n";
    cout << "Your choice: ";
    int graphToUse = getOptionFromUser();
    if (graphToUse < 0 || graphToUse > NUMBER_GRAPHS) {
        cout << "Invalid graph choice.\n";
        return nullptr;
    }
    Graph *graph = graphs[graphToUse];
    if(!graph->isLoaded()){
        graph->load();
    }
    return graph;
}

void App::menuOption1() {
    Graph *graph = getGraphFromUser();
    /*
    cout << "Enter the starting node: ";
    unsigned int startingNode = getOptionFromUser();
    if (startingNode >= graph->getNumberNodes()) {
        cout << "Invalid starting node.\n";
        return;
    }
     */
    unsigned int path[graph->getNumberNodes()];
    unsigned int distance = graph->TSP_Backtracking(path);
    cout << "The shortest path is: ";
    for (int i = 0; i < graph->getNumberNodes(); i++) {
        cout << path[i] << " ";
    }
    cout << "\nThe distance is: " << distance << endl;
}

void App::menuOption2() {
    Graph *graph = getGraphFromUser();
    // Implement the functionality for option 2 here
}

void App::menuOption3() {
    Graph *graph = getGraphFromUser();
    // Implement the functionality for option 3 here
}