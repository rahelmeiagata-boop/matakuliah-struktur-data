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

int main(void) {
    printf("ADJACENCY MATRIX GRAPH\n\n");

    printf("  ");
    for (int i = 0; i < V; i++) {
        printf("%c ", nama[i]);
    }
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%c ", nama[i]);

        for (int j = 0; j < V; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

    return 0;
}