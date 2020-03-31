#include <stdio.h>
#include <stdlib.h>

int matrix[10][10] = {0};

int bfs(int n, int visited[], int i) {
    if (visited[i] == 1) {return;}
    visited[i] = 1;
    for (int a = 0; a < n; a++) {
        if (matrix[i][a] == 1 && visited[a] == 0) {
            printf(" ~> %d ", a);
        }
    }
    for (int a = 0; a < n; a++) {
        if (visited[a] == 0 && matrix[i][a] == 1) {
            bfs(n, visited, a);
        }
    }
}

int main() {
    int n, edges, p, q, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int visited[10] = {0};
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p, &q);
        matrix[p][q] = 1;
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    bfs(n, visited, start);
    printf("\n");
    return 0;
}