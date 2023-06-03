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
        cout << "1. Backtracking Algorithm\n";
        cout << "2. Triangular Approximation Heuristics\n";
        cout << "3. Nearest Insertion Heuristics\n";
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
    cout << "0. Go back\n";
    cout << "1. shipping.csv (toy)\n";
    cout << "2. stadiums.csv (toy)\n";
    cout << "3. tourism.csv (toy)\n";
    cout << "4. graph1 (real world)\n";
    cout << "5. graph2 (real world)\n";
    cout << "6. graph3 (real world)\n";
    cout << "7. edges_25.csv (extra)\n";
    cout << "8. edges_50.csv (extra)\n";
    cout << "9. edges_75.csv (extra)\n";
    cout << "10. edges_100.csv (extra)\n";
    cout << "11. edges_200.csv (extra)\n";
    cout << "12. edges_300.csv (extra)\n";
    cout << "13. edges_400.csv (extra)\n";
    cout << "14. edges_500.csv (extra)\n";
    cout << "15. edges_600.csv (extra)\n";
    cout << "16. edges_700.csv (extra)\n";
    cout << "17. edges_800.csv (extra)\n";
    cout << "18. edges_900.csv (extra)\n";
    cout << "Enter your choice: ";
    int graphToUse = getOptionFromUser();
    if (graphToUse <= 0 || graphToUse > NUMBER_GRAPHS) {
        cout << "Invalid graph choice.\n";
        return nullptr;
    }
    Graph *graph = graphs[graphToUse-1];
    if(!graph->isLoaded()){
        auto startTime = std::chrono::high_resolution_clock::now();
        graph->load();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        cout << "Time spent loading: " << duration.count() << " milliseconds\n\n";
    }
    return graph;
}

void App::menuOption1() {
    Graph *graph = getGraphFromUser();
    if(graph == nullptr){
        return;
    }

    cout << "Running backtracking algorithm...\n";
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = graph->TSP_Backtracking();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    cout << "\n>>> RESULT: ";
    if(graph->getNumberNodes() <= 100){
        cout << "\nThe shortest path is: ";
        for (unsigned int i : result.second) {
            cout << i << " ";
        }
    }

    cout << "\nThe distance is: " << result.first << endl;
    cout << "Time spent: " << duration.count() << " milliseconds" << endl;

    waitForKey();
}

void App::menuOption2() {
    Graph *graph = getGraphFromUser();
    if(graph == nullptr){
        return;
    }

    cout << "Running triangular approximation heuristics...\n";
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = graph->TSP_TriangularApproximation();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    if(result.first == -1){
        cout << "\n>>> It was not possible to find a path\n";
        waitForKey();
        return;
    }

    cout << "\n>>> RESULT: ";
    if(graph->getNumberNodes() <= 100){
        cout << "\nThe shortest path is: ";
        for (unsigned int i : result.second) {
            cout << i << " ";
        }
    }

    cout << "\nThe distance is: " << result.first << endl;
    cout << "Time spent: " << duration.count() << " milliseconds" << endl;

    waitForKey();
}

void App::menuOption3() {
    Graph *graph = getGraphFromUser();
    if(graph == nullptr){
        return;
    }

    cout << "Running insertion heuristics...\n";

    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = graph->TSP_NearestInsertion();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    if(result.first == -1){
        cout << "\n>>> It was not possible to find a path\n";
        waitForKey();
        return;
    }

    cout << "\n>>> RESULT: ";
    // cout << "\nThe path contains the right number of nodes? " << (result.second.size() == graph->getNumberNodes()+1 ? "Yes" : "No");
    if(graph->getNumberNodes() <= 100){
        cout << "\nThe shortest path is: ";
        for (unsigned int i : result.second) {
            cout << i << " ";
        }
    }

    cout << "\nThe distance is: " << result.first << endl;
    cout << "Time spent: " << duration.count() << " milliseconds" << endl;

    waitForKey();
}