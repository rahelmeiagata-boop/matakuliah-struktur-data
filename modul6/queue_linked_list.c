#include <stdio.h>
#include <stdlib.h>

// Struktur Node
typedef struct Simpul {
    int data;
    struct Simpul *next;
} Simpul;

// Pointer depan dan belakang
Simpul *depan = NULL;
Simpul *belakang = NULL;

// Menambahkan data ke Queue
int enqueue(int x) {
    Simpul *baru = (Simpul *)malloc(sizeof(Simpul));

    if (baru == NULL) {
        return 0;
    }

    baru->data = x;
    baru->next = NULL;

    if (belakang == NULL) {
        depan = baru;
    } else {
        belakang->next = baru;
    }

    belakang = baru;

    return 1;
}

// Menghapus data dari Queue
int dequeue(int *keluar) {
    if (depan == NULL) {
        return 0;
    }

    Simpul *sasaran = depan;

    *keluar = sasaran->data;
    depan = depan->next;

    if (depan == NULL) {
        belakang = NULL;
    }

    free(sasaran);

    return 1;
}

// Menampilkan isi Queue
void tampilQueue() {
    Simpul *bantu = depan;

    if (depan == NULL) {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi Queue: ");

    while (bantu != NULL) {
        printf("%d ", bantu->data);
        bantu = bantu->next;
    }

    printf("\n");
}

// Program utama
int main() {
    int keluar;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    tampilQueue();

    if (dequeue(&keluar)) {
        printf("Data keluar: %d\n", keluar);
    }

    tampilQueue();

    return 0;
}