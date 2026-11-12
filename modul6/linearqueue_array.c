#include <stdio.h>

#define KAPASITAS 5

typedef struct {
    int data[KAPASITAS];
    int depan, belakang;
} Queue;

void createQueue(Queue *q) {
    q->depan = 0;
    q->belakang = -1;
}

int isEmpty(Queue *q) {
    return q->belakang < q->depan;
}

int isFull(Queue *q) {
    return q->belakang == KAPASITAS - 1;
}

int enqueue(Queue *q, int x) {
    if (isFull(q)) return 0;

    q->belakang++;
    q->data[q->belakang] = x;

    return 1;
}

int dequeue(Queue *q, int *keluar) {
    if (isEmpty(q)) return 0;

    *keluar = q->data[q->depan];
    q->depan++;  // sel di kirinya menjadi sia-sia

    return 1;
}

int main() {
    Queue q;
    int keluar;

    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    while (!isEmpty(&q)) {
        dequeue(&q, &keluar);
        printf("%d\n", keluar);
    }

    return 0;
}