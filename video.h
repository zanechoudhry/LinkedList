//Video.H
//Choudhry, Zane
//Zchoudhry

#ifndef video_h
#define video_h

#include <string>

using namespace std;

// A class that stores video information
class Video
{
private:
	string title;
	string url;
	string comment;
	double length;
	int rating;

public:

	// Constructor
	Video(string title, string url, string comment, double length, int rating);
	
	// Get methods
	void print();
	int getRating();
	double getLength();
	string getComment();
	string getUrl();
	string getTitle();
};

#endif
