#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;
};

class LinkedList{
    private:
        Node* head;
    public:
        void display();
        Node* search(int value);
        void insert(Node* previous, int value);
};


