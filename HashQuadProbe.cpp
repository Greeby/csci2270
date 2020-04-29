#include<iostream>
#include "Hash.hpp"
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
}

bool HashTable::insertItem(int key)
{
    int hashIndex = hashFunction(key);
    while(table[hashIndex] != NULL)
    {
        numOfcolision++;
        hashIndex = (hashIndex + numOfcolision^2) % tableSize;
    }
    table[hashIndex] = createNode(key, NULL);
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
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[0]->key << " ";
    }
    cout << endl;   
}

node* HashTable::searchItem(int key)
{
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i]->key = key)
        {
            return table[i];
        } 
    }   
    return NULL;
}

