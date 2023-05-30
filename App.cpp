#include <iostream>

#include "App.h"

App::App() {
    for(int i = 0; i < NUMBER_GRAPHS; i++){
        graphs.push_back(new Graph(i));
    }
}

void waitForKey() {
    cout << "\nPress ENTER to continue ";
    cin.ignore();
    cin.get();
}


int getOptionFromUser() {
    int choice;
    cin >> choice;
    return choice;
}


void App::run() {
    while (true) {
        cout << "\n\n=========== SELECT A STRATEGY TO SOLVE T.S.P. ===========\n";
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
                std::cout << "\nGoodbye!\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

Graph* App::getGraphFromUser() const {
    cout << "\n\n=========== SELECT A GRAPH ===========\n";
    cout << ">> 0-2 are toy graphs (shipping.csv, stadiums.csv, tourism.csv)\n";
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

    cout << "Running backtracking algorithm...\n";
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = graph->TSP_Backtracking();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    cout << "\nThe shortest path is: ";
    for (unsigned int i : result.second) {
        cout << i << " ";
    }
    cout << "\nThe distance is: " << result.first << endl;
    cout << "Time spent: " << duration.count() << " milliseconds" << endl;

    waitForKey();
}

void App::menuOption2() {
    Graph *graph = getGraphFromUser();

    cout << "Running triangular approximation algorithm...\n";
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = graph->TSP_TriangularApproximation();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    cout << "\nThe shortest path is: ";
    for (unsigned int i : result.second) {
        cout << i << " ";
    }
    cout << "\nThe distance is: " << result.first << endl;
    cout << "Time spent: " << duration.count() << " milliseconds" << endl;

    waitForKey();
}

void App::menuOption3() {
    Graph *graph = getGraphFromUser();
    // Implement the functionality for option 3 here
    waitForKey();
}