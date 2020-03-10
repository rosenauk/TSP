#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

#include <iostream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out("tsp_example_1.txt.tour");
    in.open("tsp_example_1.txt");

    int trash;
    int size;

    while (!in.eof()) {
        in >> trash >> trash;

        in >> size;
    }

    int* unvisited = new int [size];
    int* x = new int[size];
    int* y = new int[size];
    int* visited = new int[size];

    while (!in.eof()) {

        for (int i = 0; i < size; i++)
        {
            in >> unvisited[i] >> x[i] >> y[i];
        }
    }

    int current = 0;
    visited[0] = 0;

    for (int j = 1; j < size; j++)
    {
        int shortest = 99999;
        int shortNode;
        for (int k = 0; k < size; k++)
        {
            //distance formula for current node to all other nodes

            int dis = 99999;
            if (k != current)
            {
                //dist uses unvisited 'current' x and y and unvisited 'k' x and y
                dis = sqrt(pow(x[current] - x[k], 2) + pow(y[current] - y[k], 2));
                if (dis < shortest)
                {
                    shortest = dis;
                    shortNode = k;
                }
            }


        }

        visited[j] = shortNode;

    }
}

