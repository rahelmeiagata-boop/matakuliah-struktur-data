#include <stdio.h>

#define V 6

char nama[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

int matriks[V][V] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

int sudah[V];

void bfs(int awal) {
    int dikunjungi[V] = {0};
    int antre[V], depan = 0, belakang = 0;

    dikunjungi[awal] = 1;
    antre[belakang++] = awal;

    while (depan < belakang) {
        int v = antre[depan++];
        printf("%c ", nama[v]);

        for (int u = 0; u < V; u++) {
            if (matriks[v][u] == 1 && !dikunjungi[u]) {
                dikunjungi[u] = 1;
                antre[belakang++] = u;
            }
        }
    }
}

void dfs(int v) {
    sudah[v] = 1;
    printf("%c ", nama[v]);

    for (int u = 0; u < V; u++) {
        if (matriks[v][u] == 1 && !sudah[u]) {
            dfs(u);
        }
    }
}

void resetDFS(void) {
    for (int i = 0; i < V; i++) {
        sudah[i] = 0;
    }
}

int main(void) {
    printf("PENELUSURAN GRAPH BFS DAN DFS\n\n");

    printf("BFS dari A: ");
    bfs(0);
    printf("\n");

    printf("BFS dari C: ");
    bfs(2);
    printf("\n");

    resetDFS();
    printf("DFS dari A: ");
    dfs(0);
    printf("\n");

    resetDFS();
    printf("DFS dari C: ");
    dfs(2);
    printf("\n");

    return 0;
}