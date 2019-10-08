//Main.cpp
//Choudhry, Zane
//Zchoudhry

#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;


int main()
{
    //Declaration of all the variable needed for the project
    string title;
    string url;
    string comment;
    double length;
    string command;
    int rating;
    Vlist vlist;
    string searchTitle;
    string remove;
    
    //keep looping while the user is inserting a valid command
    while (getline(cin, command)){
        if(command=="insert"){
	
        getline(cin,title); //read in title
        getline(cin, url); //read in url
        getline(cin, comment); // read in comment
        cin >> length; // read in length
        cin >> rating; // read in rating
        cin.ignore();
          
        //insert the video into the list taking in the Video parameters
        Video *video = new Video(title, url, comment, length, rating);
        vlist.insert(video);
        }
        //if command is equal to print print out all the elements in the list
        else if(command == "print"){
            vlist.print();
        }
        //if command is equal remove remove the specific node requested by the user
        else if (command == "remove") {
            getline(cin,remove); //take in the title and put it into the remove function
            if (vlist.removeVideo(remove) == true) {
                vlist.removeVideo(remove);

            }
            //standard error if title isnt in list
            else{
                cerr << "Title "<< "<" << remove << ">" << " not in list, could not delete." << endl;
            }
        }
        //if comamnd is equal to length print out the amount of items in the linked list
        else if(command == "length"){
            cout << vlist.getLength() << endl;
        }
        //if command is equal to lookup print the title out if it is in the list else print out to standard error
        else if (command == "lookup") {
            getline(cin, searchTitle);
            if(vlist.lookUp(searchTitle) == false){
                cerr <<"Title " << "<" << searchTitle << ">" << " not in list." << endl;
            }
           
            
        }
        else{
            cerr <<"<"<< command <<">" << " is not a legal command, giving up." << endl;
            return 1;
        }
    
    }
    

    return 0;
	
}
  

    
	


