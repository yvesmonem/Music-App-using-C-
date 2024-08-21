#include <iostream>
#include "Header.h"
#include <string>
#include<Windows.h>
#include <iomanip>


using namespace std;


void playlistmenu() {
	song s1("Kid Cudi", "Scott Mescudi");
	song s2("Kid Cudi", "Enter Galactic");
	song s3("NF", "Running");
	song s4("Kanye West", "Famous");
	song s5("Drake", "Headlines");
	song s6("Kanye", "Flashing Lights");

	playlist myplaylist("playlist1");

	myplaylist.addsong(s1);
	myplaylist.addsong(s2);
	myplaylist.addsong(s3);
	myplaylist.addsong(s4);
	myplaylist.addsong(s5);
	myplaylist.addsong(s6);


	int choice;

	do {
		system("cls");
		cout << "-----SPOTIFY APP-----" << endl << endl << endl
			<< "What would you like to do?" << endl
			<< "1- Display songs in playlist." << endl
			<< "2- Add song to playlist." << endl
			<< "3- Remove song from playlist." << endl
			<< "4- Check if playist is empty." << endl << endl
			<< " Enter your choice below: " << endl << endl;

		cin >> choice;

		string x, y, t, u;
		song test1, test2;

		switch (choice) {
		case 1:
			system("cls");
			myplaylist.displayplaylist();
			Sleep(5000);
			break;

		case 2:
			system("cls");

			cout << "What's the name of the song you would like to add? " << endl;
			cin >> x;
			cout << "What's the name of the artist? " << endl;
			cin >> y;
			test1 = song(x, y);
			myplaylist.addsong(test1);
			break;

		case 3:
			system("cls");

			cout << "What song do you want to remove? " << endl;
			cin >> t;
			cout << "What's the artists name?" << endl;
			cin >> u;
			test2 = song(t, u);
			myplaylist.removesong(test2);
			break;

		case 4:
			system("cls");
			if (myplaylist.checkempty()) {
				cout << "Your playlist " << myplaylist.playlistname << " is empty." << endl;
			}
			else {
				cout << "Playlist " << myplaylist.playlistname << " is not empty." << endl;
			}
			break;



		default:
			cout << "Invalid entry." << endl << endl;
			break;


		}


	} while (choice != 0);






}