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
    

   while (table[hashIndex] != NULL && numOfcolision < tableSize)
    {        
        totalInsertCollisions++;
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
    return (key % tableSize);
}

void HashTable::printTable()
{
    for(int i = 1; i < tableSize; i++)
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
    int hashIndex = hashFunction(key);
    int count = 0;
    while (table[hashIndex]->key != key || table[hashIndex] == NULL)
    {    
        totalSearchCollisions++;  
        if(count == tableSize){
            return NULL;
        }  
        hashIndex = (hashIndex + 1) % tableSize;
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
