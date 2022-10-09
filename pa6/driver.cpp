#include <iostream>
#include <fstream> // .txt
#include <string>
#include "graph.h"
#define FILE "travelingSalesman.txt"
#define NUM_CITIES 5
#define MPG 40 // miles per gallon

void adjacencyMatrix(int[][NUM_CITIES]);
void calcPathCost(int[][NUM_CITIES], int[][NUM_CITIES]);
std::string optimalPath(int[][NUM_CITIES], int[][NUM_CITIES]);

int main(){
    int paths[NUM_CITIES][NUM_CITIES] = {0};
    int costs[NUM_CITIES][NUM_CITIES];
    std::fstream fout;
    fout.open(FILE, std::ios::out | std::ios::app);
    
    // generate path permutations
    calcPathCost(paths, costs);
    std::string bestPath = optimalPath(paths, costs);

    fout << "You can take " << /*list of all paths*/"" << std::endl;
    fout << "The best path to take is " << bestPath << std::endl;
    /* 
    - a .txt file with your initial values for the miles from one city to the other
    - a .txt file which includes all possible paths and the best one selected by the algorithm
    */

    fout.close();
    return 0;
}

void adjacencyMatrix(int paths[][NUM_CITIES]){
    // paths[0][3] = 178.3; // path 0 - 3 has a weight of 178.3 (miles)
}

void calcPathCost(int paths[][NUM_CITIES], int costs[][NUM_CITIES]){
    for(int i=0; i<NUM_CITIES; i++){
        for(int j=0; j<NUM_CITIES; j++){
            costs[i][j] = (paths[i][j]) * MPG;
        }
    }
}

std::string optimalPath(int paths[][NUM_CITIES], int costs[][NUM_CITIES]){
    int costPerMile[NUM_CITIES][NUM_CITIES];
    std::string bestPath;

    for(int i=0; i<NUM_CITIES; i++){
        for(int j=0; j<NUM_CITIES; j++){
            costPerMile[i][j] = paths[i][j] / costs[i][j]; 
        }
    }

    // find best path based on above info
    return bestPath;
}

/*
Consider 5 cities of interest, namely a) Reno, 
b) San Francisco, c) Salt Lake City, d) Seattle, 
and e) Las Vegas. 

Use information on the road 
network and derive the miles from one city to 
the other.

Assume a fixed metric of Miles Per Gallon = 40 and 
derive the cost of each transition **in terms of miles**

- Create a graph with each of its vertices corresponding to one of 
these cities and its edges being weighted by the associated miles 
for each trip. Note that if (and only if) you go from city A to B 
you must go through C, then you must add one edge from A to C and 
one edge from C to B and there is no need to add an edge directly 
from A to B.
- Solve the Traveling Salesman Problem such that traveling salesman 
starts from Reno, visits **all cities** in the above list and returns 
to Reno. 

Solve this problem in the brute force-way, i.e. by 
identifying all possible paths.
*/