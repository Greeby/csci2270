#include "LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::display(){
    Node* current = head;
    cout << "== CURRENT PATH ==" << endl;
    while(current != nullptr){
        cout << current->key << " -> "; 
        current = current->next; 
    }
    cout << "===" << endl;
}

void LinkedList::search(int value){
    Node* current = head;
    while(current != NULL){ 
        if(current->key == value) return; 
        else  current = current->next;  
    }
    return;  
}

void LinkedList::insert(int value)
{
    Node* newNode = new Node();
    newNode->next = NULL;
    newNode->key = value;

    Node* curr = head;

    if(head == NULL){
        head = newNode;
        // std::cout << "brian";
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        
        curr->next = newNode;
    }
    
}