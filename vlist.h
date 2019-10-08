//Vlist.h
//Zane Choudhry
//zchoudhry

#ifndef VLIST_H
#define VLIST_H

using namespace std;
#include"video.h"

class Vlist
{
    public:
        Vlist();//constructor
        ~Vlist(); // destructor
        bool insert(Video *video);
        int getLength() {return m_length;}//returning the amount of items in the list
        void print(); // printing all the items in the list
        bool lookUp(string title); // looking up a string in the linked list
        bool removeVideo(string title); // removing a specific video from the list
    

    private:
class Node
{
    public:
        Node(Video *video, Node *next) {m_video = video; m_next = next;}
        ~Node() {delete m_video;}
        Video *m_video;
        Node *m_next;
};
    Node *m_head;
    int m_length;
};

#endif
