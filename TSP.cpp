#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

#include <iostream>

using namespace std;

int main()
{
    int testOpt;
    cout << "Which test do you want to run? \n(1) Test 1\n(2) Test 2\n(1) Test 1\n(3) Test 3\n(4) Test 4\n(5) Test 5\n(6) Test 6\n(7) Test 7\n";
    cin >> testOpt;

ifstream in;
ofstream out;

    if (testOpt == 1)
    {
        out.open("test-input-1.txt.tour");
        in.open("test-input-1.txt");
    }
    if (testOpt == 2)
    {
        out.open("test-input-2.txt.tour");
        in.open("test-input-2.txt");
    }
    if (testOpt == 3)
    {
        out.open("test-input-3.txt.tour");
        in.open("test-input-3.txt");
    }
    if (testOpt == 4)
    {
        out.open("test-input-4.txt.tour");
        in.open("test-input-4.txt");
    }
    if (testOpt == 5)
    {
        out.open("test-input-5.txt.tour");
        in.open("test-input-5.txt");
    }
    if (testOpt == 6)
    {
        out.open("test-input-6.txt.tour");
        in.open("test-input-6.txt");
    }
    if (testOpt == 7)
    {
        out.open("test-input-7.txt.tour");
        in.open("test-input-7.txt");
    }

    int trash;
    int size;

    while (!in.eof()) {

        in >> size;
        in >> trash >> trash;
    }

    in.close();

    //**********************
    if (testOpt == 1)
    {
       
        in.open("test-input-1.txt");
    }
    if (testOpt == 2)
    {
        in.open("test-input-2.txt");
    }
    if (testOpt == 3)
    {
        in.open("test-input-3.txt");
    }
    if (testOpt == 4)
    {
        in.open("test-input-4.txt");
    }
    if (testOpt == 5)
    {
        in.open("test-input-5.txt");
    }
    if (testOpt == 6)
    {
        in.open("test-input-6.txt");
    }
    if (testOpt == 7)
    {
        in.open("test-input-7.txt");
    }
    //**********************

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

    cout << "tester: " << unvisited[5] << " \n";

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

        cout << "path so far:\n";
        for (int n = 0; n < size; n++)
        {
            cout <<  visited[n] << " \n";
        }
       

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

