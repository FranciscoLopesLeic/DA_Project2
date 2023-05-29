#include <iostream>

#include "App.h"

App::App() {
    for(int i = 0; i < NUMBER_GRAPHS; i++){
        graphs.push_back(new Graph(i));
    }
}


void App::run() {
    while (true) {
        cout << "Menu:\n";
        cout << "1. Option 1\n";
        cout << "2. 2-approximation TSP algorithm\n";
        cout << "3. Option 3\n";
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
    cout << "Choose a graph: ";
    int graphToUse = getOptionFromUser();
    if (graphToUse < 0 || graphToUse >= NUMBER_GRAPHS) {
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

    // Implement the functionality for option 1 here
}

void App::menuOption2() {
    Graph *graph = getGraphFromUser();
    if(graph == nullptr){
        return;
    }
    cout << "Starting 2-approximation TSP algorithm!" << endl;
    vector<int> tspPath = graph->tsp2Approximation();
    cout << "Finished 2-approximation TSP algorithm!" << endl;
    for (int i : tspPath) {
        cout << i << " ";
    }
    cout << endl;
}

void App::menuOption3() {
    Graph *graph = getGraphFromUser();
    // Implement the functionality for option 3 here
}