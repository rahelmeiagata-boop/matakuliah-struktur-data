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
long periksa = 0;

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

void bfsMatrix(int awal) {
    int dikunjungi[V] = {0};
    int antre[V], depan = 0, belakang = 0;

    dikunjungi[awal] = 1;
    antre[belakang++] = awal;

    while (depan < belakang) {
        int v = antre[depan++];
        printf("%c ", nama[v]);

        for (int u = 0; u < V; u++) {
            periksa++;

            if (matriks[v][u] == 1 && !dikunjungi[u]) {
                dikunjungi[u] = 1;
                antre[belakang++] = u;
            }
        }
    }
}

void bfsList(int awal) {
    int dikunjungi[V] = {0};
    int antre[V], depan = 0, belakang = 0;

    dikunjungi[awal] = 1;
    antre[belakang++] = awal;

    while (depan < belakang) {
        int v = antre[depan++];
        printf("%c ", nama[v]);

        for (int k = 0; k < derajat[v]; k++) {
            periksa++;

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

    printf("PERBANDINGAN ADJACENCY MATRIX DAN LIST\n\n");

    periksa = 0;
    printf("BFS Matrix: ");
    bfsMatrix(0);
    printf("| pemeriksaan = %ld\n", periksa);

    periksa = 0;
    printf("BFS List  : ");
    bfsList(0);
    printf("| pemeriksaan = %ld\n", periksa);

    int total = 0;

    for (int i = 0; i < V; i++) {
        total += derajat[i];
    }

    printf("\nJumlah sel matrix = %d\n", V * V);
    printf("Jumlah entri list = %d\n", total);

    printf("Rasio Matrix : List = %.2f : 1\n",
           (float)(V * V) / total);

    return 0;
}