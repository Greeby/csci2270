#include<iostream>
#include "Hash.hpp"
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new node*[tableSize];

}
bool HashTable::insertItem(int key)
{
    unsigned int hashIndex = hashFunction(key);
    while(table[hashIndex] != NULL && numOfcolision < tableSize)
    {
        numOfcolision++;
        hashIndex = (hashIndex + numOfcolision^2) % tableSize;
    }
    table[hashIndex] = createNode(key, NULL);
    numOfcolision = 0;
    return true;
}

unsigned int HashTable::hashFunction(int key)
{
    //calculate the hash, check for collision, perform collision resolution if needed
    return (key % tableSize);
}


void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[i]->key << " ";
    }
    cout << endl;   
}

node* HashTable::searchItem(int key)
{
    int hashIndex = hashFunction(key);
    int count = 0;
    while (table[hashIndex] != NULL)
    {      
        if(count == tableSize){
            break;
        }  
        if(table[hashIndex]->key = key){
            return table[hashIndex];
        }

        hashIndex = (hashIndex + 1) % tableSize;
        count++;
    }
    return NULL;
}