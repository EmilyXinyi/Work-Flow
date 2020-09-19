//
//  main.cpp
//  HackRiceX2020
//
//  Created by Emily Chen on 2020/9/18.
//  Copyright © 2020年 HackRiceX2020. All rights reserved.
//

// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// #include <boost/iostream/stream.hpp>
#include "schedule.h"

using namespace std;



int main() {
    vector<string> workerNames;
    int numofA, numofB, numofC;
    
    //reading file
    //file format: numOfWorkers, workNames, numOfA, numOfB, numOfC
    ifstream myfile;
    myfile.open("example.txt", ios::in);
    if (myfile.is_open())
    {
        int numOfWorkers;
        string line;
        getline(myfile, line);
        numOfWorkers = stoi(line);
        
        for (int i=0; i<numOfWorkers; i++)
        {
            getline(myfile, line);
            workerNames.push_back(line);
        }
        
        getline(myfile, line);
        numofA = stoi(line);
        getline(myfile, line);
        numofB = stoi(line);
        getline(myfile, line);
        numofC = stoi(line);
        
    }
    myfile.close();
    
    schedule(numofA, numofB, numofC, &workerNames);
    return (0); 
}
