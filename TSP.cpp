#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

#include <iostream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out("test-input-7.txt.tour");
    in.open("test-input-7.txt");

    int trash;
    int size;

    while (!in.eof()) {

        in >> size;
        in >> trash >> trash;
    }

    size = size + 1;

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

    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    int totalDis = 0;
    int current = 0;
    //visited[0] = 0;

    for (int j = 0; j < size; j++)
    {
        cout << "cities visited: " << j + 1 << " / " << size << '\n';

        int shortest = 99999;
        int shortNode;
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

        current = shortNode;
        visited[j] = shortNode;
        totalDis = totalDis + shortNode;

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

