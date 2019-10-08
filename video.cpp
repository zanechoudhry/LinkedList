//Video.cpp
//Choudhry, Zane
//Zchoudhry

#include "video.h"
#include <iostream>

using namespace std;

// Create a video
Video::Video(string title, string url, string comment, double length, int rating)
{
	this->title = title;
	this->url = url;
	this->comment = comment;
	this->length = length;
	this->rating = rating;
}

// Print the video
void Video::print()
{
	cout << title << ", ";
	cout << url << ", ";
	cout << comment << ", ";
	cout << length << ", ";

	for (int i = 0; i < rating; i++)
		cout << "*";

}

// Access rating
int Video::getRating()
{
	return rating;
}

// Access length
double Video::getLength()
{
	return length;
}

// Access comment
string Video::getComment()
{
	return comment;
}

// Access url
string Video::getUrl()
{
	return url;
}

// Access title 
string Video::getTitle()
{
	return title;
}
