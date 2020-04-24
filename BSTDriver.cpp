#include "BST.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <bits/stdc++.h> 
#include <chrono>
#include <stdlib.h> 
using namespace std::chrono;


int main(int argc, char* argv[]){
    BST Tree;
    int testData[40000];
    float insert[400];
    float search[400];

    ifstream inputFile;
    inputFile.open(argv[1]);

    int number, placement;
    string tempString;
    string line;
    while(getline(inputFile, line)){
        stringstream ss(line);
        while(getline(ss,tempString, ',')){
            number = stoi(tempString);
            testData[placement] = number;
            placement++;
        }
    }
    inputFile.close();
    high_resolution_clock::time_point start; 
    high_resolution_clock::time_point end; 

    int index = 0;
    int timeIndex = 0;
    start = high_resolution_clock::now();
    for(int i=0; i<40000; i++)
    {
        Tree.addNode(testData[i]);

        if(i%100 == 0)
        {
            end = high_resolution_clock::now();
            duration<double, std::milli> time_span = end - start;
            insert[timeIndex] = (float)time_span.count()/100;

            ///////search:
            int arr[100];
            for(int q = 0; q < 100; q++){
                arr[q] = (rand() % (i+1));
            }
            start = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                Tree.findNode(testData[arr[j]]);
            }
            end = high_resolution_clock::now();
            duration<double, std::milli> time_search = end - start;
            search[timeIndex] = (float)time_search.count()/100;
            ///////
            timeIndex++;
            start = high_resolution_clock::now();
        }
        
    }
    //send insert and search into a different file
    ofstream outputFile("insert_search_performance_BST_dataSetB.csv");
    for(int a = 0; a < 400; a++){
        outputFile << insert[a] << " ";
    }
    outputFile << endl;
    for(int z = 0; z < 400; z++){
        outputFile << search[z] << " ";
    }

    outputFile.close();
}