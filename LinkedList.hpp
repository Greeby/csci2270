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
        LinkedList();
        void display();
        void search(int value);
        void insert(int value);
};


