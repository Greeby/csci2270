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
        totalInsertCollisions++;
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
    int count = 1;
    while (table[hashIndex]->key != key || table[hashIndex] == NULL)
    {    
        totalSearchCollisions++;  
        if(count == tableSize){
            return NULL;
        }  
        hashIndex = (hashIndex + count^2) % tableSize;
        count++;        
    }
    return table[hashIndex];
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
