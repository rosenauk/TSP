/*Brayden*/

#include<iostream>
#include<cmath>
#include<iomanip>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>

#include "point.h"
#include "node.h"
#include "graph.h"

using namespace std;

/*
 * This function read the data in from the given data.txt file 
 * and then stores it in a 2d vector.
 */
vector <vector <int> > read_text() {
    ifstream rf;
    
	rf.open("test-input-1.txt");    //open our file
    if(rf.good() != true) { 
		cout << "Error!" << endl;   //if unsuccessful, quit
        exit(0);
	}
    
    int x, y, trash;
    vector <vector <int> > coordinates;
    vector <int> X;
    vector <int> Y;

    while(!rf.eof()) {
        rf >> trash;
        rf >> x;
        rf >> y;
        X.push_back(x);
        Y.push_back(y);
    } 
    coordinates.push_back(X);
    coordinates.push_back(Y);
   
    rf.close(); //close our file

    return coordinates;
}


int main()
{
    Point **p;

    vector<vector<int> > coordinates = read_text();
    int size = coordinates[0].size();
    
    cout << "Size: " << size << endl;
    for(int i = 0; i < size; i++) {
        cout << "( " << coordinates[0][i] << ", " << coordinates[1][i] << " )"<< endl;;

    }
    vector <int> X = coordinates[0];
    vector <int> Y = coordinates[1];

    p = new Point*[size];
    Graph graph(size);
    for(int i = 0; i < size; i++) {
        p[i] = new Point(X[i], Y[i]);
        Node n(i, p[i]);
        graph.setNode(n);
    }

    graph.setGraph();
   // graph.TSP();
    
    return 0;

}

