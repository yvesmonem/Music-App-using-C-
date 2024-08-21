#ifndef classesheader_h
#define classesheader_h
#include<string>
#include <set>
#include <queue>
#include<list>
#include <iomanip>
#include <Windows.h>

using namespace std;


struct song {
	string artist;
	string title;

	song() :title(""), artist("") {}

	song(string y, string x) {
		artist = y;
		title = x;

	}

	friend ostream& operator << (ostream& os, song r) {
		os << setw(7) << left << "Title:" << setw(20) << left << r.title
			<< setw(8) << left << "Artist:" << r.artist;
		return os;
	}

	bool operator ==(song other) {
		return(artist == other.artist) && (title == other.title);
	}
	bool operator < (const song other) const {
		return title < other.title;

	}


};

struct playlist {
	string playlistname;

	playlist() :playlistname("") {}

	playlist(string x) {
		playlistname = x;
	}

	list <song> pname;
	list<song>::const_iterator it;

	void addsong(song t) {
		for (song b : pname)
		{
			if (b == t)
			{
				cout << "The book is already found in the library." << endl;
				return;
			}
		}

		//Add the book to the library.
		pname.push_back(t);


	}


	void removesong(song s) {
		bool isFound = false;
		for (it = pname.begin(); it != pname.end(); it++) {
			song currentsong = *it;
			if (currentsong.title == s.title && currentsong.artist == s.artist) {

				//Pass the iterator as a parameter to the erase function to remove the book from the library.
				pname.erase(it);
				isFound = true;
				break;
			}
		}
		if (isFound == false)
			cout << "Song" << s.title << "is not found in the library." << endl;


	}


	void displayplaylist() {

		cout << "The songs in the playlist " << playlistname << " are :" << endl << endl;
		for (it = pname.begin(); it != pname.end(); it++) {
			cout << *it << endl;
		}
	}

	bool checkempty() {
		return pname.empty();
	}
	bool operator < (const playlist other) const {
		return playlistname < other.playlistname;

	}


};

struct library {
	set <song> librarysong;
	set <playlist> libraryplaylist;


	void addelement(const song song) {
		librarysong.insert(song);
	}

	void addelement(const playlist playlist) {
		libraryplaylist.insert(playlist);
	}


	bool checkempty() {
		return librarysong.empty() && libraryplaylist.empty();
	}

	int returnsize() {
		int size1=0, size2=0;
		size1 = librarysong.size();
		size2 = libraryplaylist.size();

		
		return size1 + size2;

	}
	bool findelement(song s) {
		if (librarysong.find(s) != librarysong.end())
			return true;
		else
			return false;
	}
	bool findelement(playlist p) {
		if (libraryplaylist.find(p) != libraryplaylist.end())
			return true;
		else
			return false;
	}

};


struct q {
	queue <song> queuemanager;

	void addsong(song r) {
		queuemanager.push(r);
	}
	bool emptyqueue() {
		return queuemanager.empty();
	}
	void playqueue() {
		while (!queuemanager.empty()) {
			cout << "Now playing: " << endl << endl << queuemanager.front() << endl;
			queuemanager.pop();
			Sleep(2000);
			system("cls");

		}
			
		

	}
};


#endif
