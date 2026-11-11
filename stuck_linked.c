#include <stdio.h>
#include <stdlib.h>

typedef struct Simpul {
    int data;
    struct Simpul *next;
} Simpul;

Simpul *atas = NULL;  // puncak stack adalah simpul pertama

int push(int x) {
    Simpul *baru = (Simpul *)malloc(sizeof(Simpul));
    if (baru == NULL) return 0;

    baru->data = x;
    baru->next = atas;  // sambungkan ke tumpukan lama
    atas = baru;        // puncak berpindah ke simpul baru

    return 1;
}

int pop(int *keluar) {
    if (atas == NULL) return 0;

    Simpul *sasaran = atas;
    *keluar = atas->data;
    atas = atas->next;  // pindahkan puncak dahulu
    free(sasaran);      // bebaskan simpul lama

    return 1;
}

int main() {
    int keluar;

    push(10);
    push(20);
    push(30);

    while (pop(&keluar)) {
        printf("pop: %d\n", keluar);
    }

    return 0;
}   