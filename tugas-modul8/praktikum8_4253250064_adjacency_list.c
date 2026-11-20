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

int daftar[V][V];
int derajat[V];

void bangunDaftar(void) {
    for (int i = 0; i < V; i++) {
        derajat[i] = 0;

        for (int j = 0; j < V; j++) {
            if (matriks[i][j] == 1) {
                daftar[i][derajat[i]++] = j;
            }
        }
    }
}

void tampilkanDaftar(void) {
    printf("ADJACENCY LIST GRAPH\n\n");

    for (int i = 0; i < V; i++) {
        printf("%c (derajat %d): ", nama[i], derajat[i]);

        for (int k = 0; k < derajat[i]; k++) {
            printf("%c ", nama[daftar[i][k]]);
        }

        printf("\n");
    }
}

void bfsDaftar(int awal) {
    int dikunjungi[V] = {0};
    int antre[V], depan = 0, belakang = 0;

    dikunjungi[awal] = 1;
    antre[belakang++] = awal;

    while (depan < belakang) {
        int v = antre[depan++];
        printf("%c ", nama[v]);

        for (int k = 0; k < derajat[v]; k++) {
            int u = daftar[v][k];

            if (!dikunjungi[u]) {
                dikunjungi[u] = 1;
                antre[belakang++] = u;
            }
        }
    }
}

int main(void) {
    bangunDaftar();
    tampilkanDaftar();

    printf("\nBFS menggunakan adjacency list dari A: ");
    bfsDaftar(0);
    printf("\n");

    return 0;
}