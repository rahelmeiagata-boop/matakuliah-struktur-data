#include <stdio.h>

#define V 7

char nama[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int matriks[V][V] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0}
};

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

int main(void) {
    printf("PERCOBAAN 1: MENAMBAHKAN SIMPUL G\n");

    printf("Jumlah sel matrix = %d x %d = %d\n",
           V, V, V * V);

    printf("Jumlah entri adjacency list = 18\n");

    printf("BFS dari A: ");
    bfs(0);
    printf("\n\n");

    printf("PERCOBAAN 2: MENGHAPUS SELURUH SISI SIMPUL E\n");

    // Menghapus hubungan C-E dan E-F.
    matriks[2][4] = 0;
    matriks[4][2] = 0;
    matriks[4][5] = 0;
    matriks[5][4] = 0;

    printf("BFS dari A setelah sisi E dihapus: ");
    bfs(0);
    printf("\n");

    printf("Simpul E tidak dikunjungi karena terpisah.\n");

    return 0;
}