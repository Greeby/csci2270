#include<iostream>
#include "Hash.hpp"
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
    }
}

bool HashTable::insertItem(int key)
{
    int hashIndex = hashFunction(key);
    while (table[hashIndex] != NULL && numOfcolision < tableSize)
    {
        numOfcolision++;
        hashIndex = (hashIndex + 1) % tableSize;
    }
    table[hashIndex] = createNode(key, NULL);
    numOfcolision = 0;
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
        if(table[i] != NULL)
        cout << table[i]->key << " ";
        else
        {
            cout<< "Table[" << i << "] is NULL ";
        }
        
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

