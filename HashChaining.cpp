#include "HashTest.hpp"
#include<iostream>
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
}

bool HashTable::insertItem(int key)
{
    node* currNode = table[hashFunction(key)];
    while(currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = createNode(key, NULL);
    return true;
}

unsigned int HashTable::hashFunction(int key)
{
    //calculate the hash, check for collision, perform collision resolution if needed
    int hash = key % tableSize;

    return hash;
}

void HashTable::printTable()
{
    node* currNode;
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[0] << " ";
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
    node * currNode; 
 
    currNode = table[hashFunction(key)];
    //loop through the LL
    while (currNode)
       {
           if(currNode->key == key)
           {
               return currNode;
           }
           else
           {
               currNode = currNode->next;
           }    
        }   
    return NULL;
}

