#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

   /* Node(int k) {
        key = k;
    }*/
};

class BST{
    private:
        Node* root;
    public:
        BST();
        void printBST();
        void addNode(int key);
        void findNode(int key);
};
