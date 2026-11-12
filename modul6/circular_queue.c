#include <stdio.h>

#define KAPASITAS 5

// Struktur Circular Queue
typedef struct {
    int data[KAPASITAS];
    int depan;
    int belakang;
    int jumlah;
} Queue;

// Membuat Queue kosong
void createQueue(Queue *q) {
    q->depan = 0;
    q->belakang = -1;
    q->jumlah = 0;
}

// Mengecek apakah Queue kosong
int isEmpty(const Queue *q) {
    return q->jumlah == 0;
}

// Mengecek apakah Queue penuh
int isFull(const Queue *q) {
    return q->jumlah == KAPASITAS;
}

// Menambahkan data ke Queue
int enqueue(Queue *q, int x) {
    if (isFull(q)) {
        return 0;
    }

    q->belakang = (q->belakang + 1) % KAPASITAS;
    q->data[q->belakang] = x;
    q->jumlah++;

    return 1;
}

// Mengambil data dari Queue
int dequeue(Queue *q, int *keluar) {
    if (isEmpty(q)) {
        return 0;
    }

    *keluar = q->data[q->depan];
    q->depan = (q->depan + 1) % KAPASITAS;
    q->jumlah--;

    return 1;
}

// Menampilkan isi Queue
void tampilQueue(const Queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi Queue: ");

    for (int i = 0; i < q->jumlah; i++) {
        int posisi = (q->depan + i) % KAPASITAS;
        printf("%d ", q->data[posisi]);
    }

    printf("\n");
}

// Program utama
int main() {
    Queue q;
    int keluar;

    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    tampilQueue(&q);

    if (dequeue(&q, &keluar)) {
        printf("Data keluar: %d\n", keluar);
    }

    tampilQueue(&q);

    return 0;
}