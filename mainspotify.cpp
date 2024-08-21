#include <iostream>
#include <string>
#include "classesheader.h"
#include"playlistheader.h"
#include"libraryheader.h"
#include "queueheader.h"

#include <iomanip>


using namespace std;




int main() {
    int choice;


    do {
        system("cls");
        cout << "------------------------" << endl
            << "|  Welcome to Spotify  |" << endl
            << "------------------------" << endl << endl
            << "What would you like to do?" << endl << endl
            << "1- Browse playlist menu..." << endl
            << "2- Browse library menu..." << endl
            << "3- Browse queue menu..." << endl
            << "Enter your choice (1-3): ";
        cin >> choice;

        // Handle user input and perform actions based on the choice
        switch (choice) {
        case 1:
            system("cls");
            // Implement playlist menu functionality
            cout << "You selected Browse playlist menu." << endl << "Loading...";
            Sleep(1500);
            playlistmenu();
            break;
        case 2:
            system("cls");
            // Implement library menu functionality
            cout << "You selected Browse library menu." << endl << "Loading...";
            Sleep(1500);
            librarymenu();
            break;
        case 3:
            system("cls");
            // Implement queue menu functionality
            cout << "You selected Browse queue menu." << endl << "Loading...";
            Sleep(1500);
            queuemenu();
            break;
        default:
            // Handle invalid input
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
        }
    } while (choice != 0);


    return 0;
}