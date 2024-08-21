#include <iostream>
#include "classesheader.h"
#include <string>
#include<Windows.h>
#include <iomanip>
#include<limits>


#ifndef librarytheader_h
#define librarytheader_h


using namespace std;


void librarymenu() {
	song s1("Kid Cudi", "Scott Mescudi");
	song s2("Kid Cudi", "Enter Galactic");
	song s3("NF", "Running");
	song s4("Kanye West", "Famous");
	song s5("Drake", "Headlines");
	song s6("Kanye", "Flashing Lights");

	playlist myplaylist("playlist1");

	library mainlib;

	myplaylist.addsong(s1);
	myplaylist.addsong(s2);
	myplaylist.addsong(s3);
	myplaylist.addsong(s4);
	myplaylist.addsong(s5);
	myplaylist.addsong(s6);


	mainlib.addelement(s1);
	mainlib.addelement(s2);
	mainlib.addelement(s3);
	mainlib.addelement(s4);
	mainlib.addelement(s5);
	mainlib.addelement(s6);

	mainlib.addelement(myplaylist);

	int choice,choice1;


	do {
		system("cls");
		cout << "------------------------" << endl
			<< "|  Welcome to Spotify  |" << endl
			<< "------------------------" << endl << endl
			<< "What would you like to do?" << endl << endl
			<< "1- Add song or playlist to library." << endl
			<< "2- Check if library is empty." << endl
			<< "3- Return the number of elements in library." << endl
			<< "4- Find an element in the library." << endl << endl
			<< "Enter your choice (1-3) " << endl
			<< "Or enter 0 to return to main menu:";

		cin >> choice;

		string x, y, t, u;
		song test1, test2;
		playlist xy;

		switch (choice) {

		case 1:
			system("cls");
			int choice1;
			cout << "Would you like to add a song(1) or a playlist(2)" << endl
				<< "Enter choice: ";
			cin >> choice1;
			if (choice1 == 1) {
				cout << "What's the name of the song you would like to add? " << endl;
				getline(cin, x);
				cout << "What's the name of the artist? " << endl;
				getline(cin, y);
				test1 = song(y, x);
				mainlib.addelement(test1);
				cout << "Song added!" << endl;

			}
			else if (choice1 == 2) {

				cout << "What's the name of the playlist you would like to add?" << endl;
				getline(cin, x);
				playlist xy(x);
				mainlib.addelement(xy);
				cout << "Playlist added!" << endl;
			}
			else {
				cout << "Invalid choice" << endl;
				Sleep(1000);
				librarymenu();
			}
			break;

		case 2:
			system("cls");

			cout << "Checking if library empty...." << endl;
			Sleep(2000);
			if (mainlib.checkempty()) {
				cout << "Library is empty.";
				Sleep(1500);

			}

			else {
				cout << "Library is not empty.";
				Sleep(1500);
			}
			break;

		case 3:
			system("cls");
			cout << "The total number of elements in your playlist is : " << mainlib.returnsize();
			Sleep(1500);
			break;

		case 4:
			system("cls");

			
		    cout << "Would you like to find a song (1) or a playlist (2):" << endl;
		    cin >> choice1;
		    
		    if (choice1 == 1) {
		    	cout << "What's the name of the song you would like to find? " << endl;
		    	cin.ignore();
		    	getline(cin, x);
		    
		    	cout << "What's the name of the artist? " << endl;
		    	cin.ignore();
		    	getline(cin, y);
		    
		    	test1 = song(y, x);
		    	if (mainlib.findelement(test1)) {
		    		cout << "The song: " << test1.title << " was found.";
		    	}
		    	else {
		    		cout << "The song: " << test1.title << " was not found.";
		    	}
		    	Sleep(2000);
		    	break;
		    
		    }
		    else if (choice1 == 2) {
		    	cout << "What's the name of the playlist you would like to find?" << endl;
				cin.ignore();
		    	getline(cin, x);
		    	playlist xy(x);
		    	if (mainlib.findelement(xy)) {
		    		cout << "The playlist: " << xy.playlistname << " was found.";
		    	}
		    	else {
		    		cout << "The playlist: " << xy.playlistname << " was not found.";
		    	}
				Sleep(2000);
		    	break;
		    }
		    else {
		    	cout << "Invalid choice" << endl;
		    	Sleep(1000);
		    	
		    
		    }		

			

			break;
			
		}

	} while (choice != 0);


}
#endif



	

