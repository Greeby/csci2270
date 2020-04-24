#include "BST.hpp"
#include <iostream>

using namespace std;

BST::BST(){
    root = NULL;
}

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
        currNode = new Node();
        currNode->key = key;
        currNode->left = NULL;
        currNode->right = NULL;
        return currNode;
    }
    else if(currNode->key < key){
        currNode->right = addNodeHelper(currNode->right,key);
    }
    else{
         currNode->left = addNodeHelper(currNode->left,key);
    }
}

void BST::addNode(int key){
    if(root == NULL){
        root = addNodeHelper(root, key);
    }
    else{
        addNodeHelper(root,key);
    }
}


Node* findNodeHelper(Node* currNode, int key){
    if(currNode == NULL){
        return NULL;
    }
    if(currNode->key == key){
        return currNode;
    }
    if(currNode->key  > key){
        return findNodeHelper(currNode->left, key);
    }
    else{
        return findNodeHelper(currNode->right, key);
    }
}

void BST::findNode(int key) {
    Node* currnode = findNodeHelper(root, key);
    if(currnode == NULL){
        cout << "Node not found.";
    }
}