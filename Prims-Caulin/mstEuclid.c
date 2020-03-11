#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
//This function calculates the Euclidian distance between two inputs
int getWeight(int vertx[], int verty[]){
	int xsq, ysq, total;
//Squares difference between inputs x and y values
	xsq = pow(vertx[0] - verty[0],2);
	ysq = pow(vertx[1] - verty[1],2);
//Finds square root of sum
	total = sqrt(xsq+ysq);	
	return total;
}

//This function finds the minimum weight of a key for every vertex in Q
int extractMin(int Q[], int key[], int size){
	int i, ind;
	bool found;
	found = false;
	int min = 101;
//Loops through every vertex in Q
	for (i = 0; i < size; i++){
//Checks if current index is minimum and within Q
		if(key[i] < min && Q[i] != -1){
			min = key[i];
			ind = i;	
		}
	}
//Marks minimum as no longer in Q by making it -1
	Q[ind] = -1;
//Returns index of minimum
	return ind;	
}
//This function checks to see if the list Q is empty
bool notempty(int Q[], int size){
	int i;
//Loops through size of list
	for(i = 0; i < size; i++){
//Checks if each value of Q is not -1, meaning it is not empty
		if(Q[i] != -1){
			return true;			
		}
	}
	return false;
}
//This function checks if a vertex in within Q
bool inQ(int Q[], int v, int size){
	int i;
	for(i = 0; i < size; i++){
		if(Q[i] == v){
			return true;
		}
	}
	return false;
}
//This function uses Prims algorithm to find the minimum spanning tree of a given graph
void mstPrim(int vert[][2], int nvert){
	int Q[nvert], i, j, u, sum, key[nvert], p[nvert], w[nvert][nvert];
	sum = 0;
//Creates list of all weights in graph
	for(i = 0; i < nvert; i++){
		for(j = 0; j < nvert; j++){
			w[i][j] = getWeight(vert[i], vert[j]);
		}
	}	
//Stores all vertexs in Q and gives each key related to a vertex a maximum number
	for(i = 0; i < nvert; i++){
		Q[i] = i;
		key[i] = 101;	
	}
//Sets chosen original vertex to 0
	key[0] = 0;
//Sets parent to "null"
	p[0] = -1;
//Prints message
	printf("Edges in MST\n");
	printf("Point (x,y)	    Distance\n");
//Loops until Q is only filled with -1, meaning it is empty
	while (notempty(Q, nvert) == true){
//Finds minimum value in Q and sets it to -1 in the list
		u = extractMin(Q, key, nvert);
//Checks if the parent exists
		if (p[u] != -1){
//Prints vertex of parent and new vertex
			printf("(%d,%d) - (%d,%d)", vert[p[u]][0], vert[p[u]][1], vert[u][0], vert[u][1]);
//Prints weight of vertex between parent and new
			printf("	  	  %d", key[u]);
			printf("\n");
//Sums all weights of mst to single value
			sum += key[u];
			
		}
//Loops for number of adjacencies
		for(i = 0; i<nvert; i++){
//If u is in Q and is a minimum the graph moves
			if(inQ(Q, i, nvert) == true && w[u][i] < key[i]){
//The parent becomes u
				p[i] = u;
//The key becomes the weight from u to the current edge
				key[i] = w[u][i];
			}
		}
	}
	printf("	  Total Distance %d\n", sum);
}

int main(int argc, char* argv []){
	int nvert, inp, i,j;
//Opens file from command line
	FILE *fp = fopen(argv[1], "r");
//Stores number of vertexes in variable
	fscanf(fp, "%d", &inp);
	nvert = inp;
	int vert[nvert][2];
//Stores every x and y value into a 2d array
	for(i = 0; i < nvert; i++){
		fscanf(fp, "%d", &inp);
		vert[i][0] = inp;
		fscanf(fp, "%d", &inp);
		vert[i][1] = inp;
		
	}
//Runs Prim algorithm
	mstPrim(vert, nvert);		
	fclose(fp);
	return 0;
}
