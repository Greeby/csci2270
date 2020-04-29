#include "hash.hpp"
#include<iostream>
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new node*[tableSize];

}
bool HashTable::insertItem(int key)
{
    node* currNode = table[hashFunction(key)];
    if(currNode == NULL){
        currNode = createNode(key, NULL);
    }
    else{
        totalInsertCollisions++;
        while(currNode->next != NULL)
        {
            totalInsertCollisions++;
            currNode = currNode->next;
        }
        currNode->next = createNode(key, NULL);
    }
    
    return true;
}

unsigned int HashTable::hashFunction(int key)
{
    //calculate the hash, check for collision, perform collision resolution if needed
    return (key % tableSize);
}

void HashTable::printTable()
{
    node* currNode;
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[i] << " ";
        //print the list at index
        currNode = table[i];
        while(currNode)
        {
            cout << currNode->key << " ";
            currNode = currNode ->next;
        }
    }
    cout << endl;   
}

node* HashTable::searchItem(int key)
{
    node * currNode = table[hashFunction(key)];
    //loop through the LL
    while(currNode)
    {
        if(currNode->key != key){
            totalSearchCollisions++;
            currNode = currNode->next;
        }
        else{
            return currNode;
        }
    }   
    return NULL;
}

int HashTable::getTotalInsertCol(){
    int I = totalInsertCollisions;
    totalInsertCollisions = 0;
    return I;
}

int HashTable::getTotalSearchCol(){
    int S = totalSearchCollisions;
    totalSearchCollisions = 0;
    return S;
}
