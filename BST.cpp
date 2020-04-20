#include "BST.hpp"
#include <iostream>

using namespace std;


void printTreeInOrderHelper(Node* currNode){
    if(currNode){
        printTreeInOrderHelper(currNode->left);
        cout <<"Node: "<<currNode->key << endl;
        printTreeInOrderHelper(currNode->right);
    }
}

void BST::printBST(){
    if(root == NULL){
        cout << "Tree is Empty. Cannot print";
    }
    printTreeInOrderHelper(root);
    cout << endl;
}




Node* addNodeHelper(Node* currNode, int key)
{
    if(currNode == NULL){
        currNode = new Node(key); 
    }
    else if(currNode->key < key){
        currNode->right = addNodeHelper(currNode->right,key);
    }
    else if(currNode->key > key){
        currNode->left = addNodeHelper(currNode->left,key);
    }
    return currNode;
}

void BST::addNode(int key){
    root = addNodeHelper(root, key);
}




void findNode(int key);



Node* findNodeHelper(Node* currNode, int key){
    if(currNode == NULL)
        return NULL;
    if(currNode->key == key)
        return currNode;

    if(currNode->key  > key)
        return findNodeHelper(currNode->left, key);

    return findNodeHelper(currNode->right, key);
}


void BST::findNode(int key) {
    Node* currnode = findNodeHelper(root, key);
    if(currnode != NULL){
      cout << "Node Info:" << endl;
      cout << "==================" << endl;
      cout << "Key:" << currnode->key << endl;
    }
    else{
      cout << "Node not found." << endl;    
    }
}