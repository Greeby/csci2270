#include "LinkedList.hpp"
#include <iostream>

using namespace std;


void LinkedList::display(){
    Node* current = head;
    cout << "== CURRENT PATH ==" << endl;
    while(current != nullptr){
        cout << current->key << " -> "; 
        current = current->next; 
    }
    cout << "===" << endl;
}

Node* LinkedList::search(int value){
    Node* current = head;
    while(current != 0){ 
        if(current->key == value) return current; 
        else  current = current->next;  
    }
    return 0;  
}

void LinkedList::insert(Node* previous, int value)
{
    if(previous == NULL){
        Node* tmp = new Node();
        tmp->next = head;
        head = tmp;
        tmp->key = value;
    }
    else{
        Node* newnode = new Node();
            newnode->key = value;
        Node* temp;
            temp = previous->next;
        previous->next = newnode;
            newnode->next = temp;
    }
}