#include<iostream>
#include "Hash.hpp";
using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
}

bool HashTable::insertItem(int key)
{
    node *newNode = createNode(key, NULL);
    table[hashFunction(key)] = newNode;
}

unsigned int HashTable::hashFunction(int key)
{
    //calculate the hash, check for collision, perform collision resolution if needed
    int hash = key % tableSize;

    //check if there is a collision
    if(table[hash] == 0)
    {
        return hash;
    }
    //otherwise commense the collision resloution
    else
    {
        //if the hash value is the last index we will increment back one for our loop
        if(hash == tableSize - 1)
        {
            hash = hash - 1;
        }
        //linear probe starting from the collision point
        for(int i = hash + 1; i < tableSize; i++)
        {
            //check for open spot
            if(table[i] == NULL)
            {
                return i;
            }
            //check if we are at the end of the list and reset if we are
            if(i == tableSize-1)
            {
                i = -1;
            }
            //check if we are back at our original hash and break if we did
            if(i == hash)
            {
                //The list is already full
                break;
            }  
        }
    }  
}

void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[0] << " ";
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

