#include <stdio.h>
#define KAPASITAS 50

typedef struct {
    int data[KAPASITAS];
    int depan, belakang;
} Queue;
void createQueue(Queue *q) { q->depan = 0; q->belakang = -1; }
int  isEmptyQ(Queue *q)    { return q->belakang < q->depan; }
int  isFullQ(Queue *q)     { return q->belakang == KAPASITAS - 1; }
int enqueue(Queue *q, int x) {
    if (isFullQ(q)) return 0;
    q->belakang++;
    q->data[q->belakang] = x;
    return 1;
}
int dequeue(Queue *q, int *keluar) {
    if (isEmptyQ(q)) return 0;
    *keluar = q->data[q->depan];
    q->depan++;                   
}

typedef struct {
    int data[KAPASITAS];
    int depan, belakang, jumlah;
} CQueue;
void createCQueue(CQueue *q) { q->depan = 0; q->belakang = -1; q->jumlah = 0; }
int  isEmptyC(CQueue *q)     { return q->jumlah == 0; }
int  isFullC(CQueue *q)      { return q->jumlah == KAPASITAS; }
int enqueueC(CQueue *q, int x) {
    if (isFullC(q)) return 0;
    q->belakang = (q->belakang + 1) % KAPASITAS;  
    q->data[q->belakang] = x;
    q->jumlah++;
    return 1;
}
int dequeueC(CQueue *q, int *keluar) {
    if (isEmptyC(q)) return 0;
    *keluar = q->data[q->depan];
    q->depan = (q->depan + 1) % KAPASITAS;        
    q->jumlah--;
    return 1;
}

int main(void) {
    Queue  lq;  createQueue(&lq);
    CQueue cq;  createCQueue(&cq);
    int x;

    for (int i = 1; i <= 5; i++) { enqueue(&lq, i);  enqueueC(&cq, i); }
    for (int i = 0; i < 2; i++)   { dequeue(&lq, &x); dequeueC(&cq, &x); }

    printf("Linear   enqueue(6): %s\n", enqueue(&lq, 6)  ? "diterima" : "DITOLAK");
    printf("Circular enqueue(6): %s\n", enqueueC(&cq, 6) ? "diterima" : "DITOLAK");
    printf("Linear   depan=%d belakang=%d\n", lq.depan, lq.belakang);
    printf("Circular depan=%d belakang=%d jumlah=%d\n",
           cq.depan, cq.belakang, cq.jumlah);
    return 0;
}