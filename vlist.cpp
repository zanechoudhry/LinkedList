//vlist.cpp
//Zane Choudhry
//zchoudhry


#include<iostream>
#include"video.h"
#include "vlist.h"
using namespace std;
Vlist::Vlist(){
    m_length = 0; // initializing variable to NULL
    m_head = NULL;
}
Vlist::~Vlist(){
    
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }

}
bool Vlist::insert(Video *video){
    Node* current = m_head;
    bool duplicate = false;
    
    //keep looping until current is NULL
    while (current != NULL)
    {
        if (current->m_video->getTitle() == video->getTitle()){
            duplicate = true; // return true if there is a duplicate value in the list
            
        }
        current = current->m_next; // traverse the pointer
    }
    
    //if there isnt a duplicate in the list
    if(duplicate == false){
        
    if (m_head == NULL || m_head->m_video->getTitle() > video->getTitle()) {
        m_head = new Node(video, m_head);
        ++m_length; //increment the number of elements in the list
        return true;
    }
    else{
        Node *node = m_head;
        while (node->m_next != NULL && node->m_next->m_video->getTitle() < video->getTitle()) {
            node = node->m_next;
        }
        node->m_next = new Node(video, node->m_next);
        ++m_length;
        return true;
    }
    }
    return false;
    
}


void Vlist::print(){
    Node *ptr = m_head;
 
    //keep going until the ptr is NULL
    while (ptr!=NULL) {
        Video *v1 = ptr->m_video;
        v1->print(); // print out all the videos in the list
        cout << endl;
        ptr = ptr->m_next; //traverse the pointer
        
    }
    
    ptr = m_head; // reset the pointer back the the beginning in case print function is called multiple times
    
}

bool Vlist::lookUp(string title){
    
        Node* current = m_head;
    
    //keep looping until pointer reaches NULL
        while (current != NULL)
        {
            if (current->m_video->getTitle() == title){//if the title requested by the user is equal to the title in the list print out the whole vidoe
            current->m_video->print();
            cout << endl;
                return true;
            }
            current = current->m_next; //traverse the pointer
        }
    return false;
}

bool Vlist::removeVideo(string title){
    
        bool result = false;
        if (m_head != NULL) {
            if (m_head->m_video->getTitle() == title) {
                Node *nodeToDelete = m_head;
                m_head = m_head->m_next;
                delete nodeToDelete; // delete the item that the user wanted deleted
                --m_length; // decrement the amount of items in the list if video is rmeoved
                result = true;
            } else {
                Node *node = m_head;
                while (node->m_next != NULL && node->m_next->m_video->getTitle() != title) {
                    node = node->m_next; // traverse the list
                }
                if (node->m_next != NULL) {
                    Node *nodeToDelete = node->m_next;
                    node->m_next = nodeToDelete->m_next;
                    delete nodeToDelete;
                    --m_length; // decrement the amount of items in the list if a item is removed
                    result = true;
                }
            }
        }
        return result;
}




