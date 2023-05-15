#include <iostream>

#include "App.h"

void App::run() {
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Option 1\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                menuOption1();
                break;
            case 2:
                menuOption2();
                break;
            case 3:
                return;  // Exit the loop to quit the application
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void App::menuOption1() {
    std::cout << "You chose option 1.\n";
    // Implement the functionality for option 1 here
}

void App::menuOption2() {
    std::cout << "You chose option 2.\n";
    // Implement the functionality for option 2 here
}