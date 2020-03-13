#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in;
    ofstream out;


    in.open(argv[1]);

    string output = string(argv[1]);
    output += ".tour";

    out.open(output.c_str());



    int trash;
    int size;

    while (!in.eof()) {

        in >> size;
        in >> trash >> trash;
    }

    in.close();


    in.open(argv[1]);
    size = size + 1;

    int* unvisited = new int[size];
    int* x = new int[size];
    int* y = new int[size];
    int* visited = new int[size];

    while (!in.eof()) {

        for (int i = 0; i < size; i++)
        {
            in >> unvisited[i] >> x[i] >> y[i];
        }
    }


    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    int totalDis = 0;
    int current = 0;


    for (int j = 0; j < size; j++)
    {
        cout << "cities visited: " << j + 1 << " / " << size << '\n';

        int shortest = 99999;
        int shortNode = 999999;
        for (int k = 0; k < size; k++)
        {
            //distance formula for current node to all other nodes

            int dis = 99999;
            bool valid = true;
            if (k != current)
            {
                for (int l = 0; l < size; l++)
                {
                    if (unvisited[k] == visited[l])
                    {
                        valid = false;
                    }
                }

                if (valid == true)
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

        }
        if (shortNode == 999999)
        {
            shortNode = 0;
            shortest = sqrt(pow(x[current] - x[shortNode], 2) + pow(y[current] - y[shortNode], 2));
        }
        current = shortNode;
        visited[j] = shortNode;
        totalDis = totalDis + shortest;

    }

    out << totalDis;
    out << endl;

    for (int m = 0; m < size; m++)
    {
        out << visited[m];
        out << endl;
    }

    cout << "Tour completed \n";

    delete[] unvisited;
    delete[] visited;
    delete[] x;
    delete[] y;
}
