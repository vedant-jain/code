/*
Source: Atlassian HackerRank test

QUESTION: Return sum of weights of graphs where weight is defined by ceiling of the root of the number of nodes in the graph.
Sample input:
1 2
1 3
2 4
3 5
7 8
8 9

Weight of graph (1, 2, 3, 4, 5) = 3
Weight of graph (6) = 1
Weight of graph (7, 8, 9) = 2
Weight of graph (9) = 1

Total = 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g[101][101];

int V, E;

int visited[101];

int dfsv (int v) {
    visited[v] = 1;
    int count = 1;
    for (int i = 1; i <= V; i++) {
        if ((visited[i] != 1) && (g[v][i] == 1) && (i != v)) {
            count += 1 + dfsv(i);
        }
    }
    return count;
}

int dfs() {
    int i;
    int n = 0;
    int value = 0;
    for (int i = 1; i <= V; i++) {
        if (visited[i] != 1) {
            n = dfsv(i);
            value += ceil(sqrt(n));
        }
    }
    return value;
}

int main () {
	printf("Enter no of vertices: ");
	scanf("%d", &V);
	int i, j, a, b;
	printf("Enter number of edges: ");
	scanf("%d",&E);
	printf("Enter the edges: \n");
	for(i=0; i<E; i++) {
		scanf("%d%d",&a,&b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	printf("Answer: %d\n", dfs());
	return 0;
}
