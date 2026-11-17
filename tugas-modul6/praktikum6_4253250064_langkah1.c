#include <stdio.h>
#define KAPASITAS 20

typedef struct
{
    int data[KAPASITAS];
    int depan, belakang;
} Queue;
void createQueue(Queue *q)
{
    q->depan = 0;
    q->belakang = -1;
}
int isEmptyQ(Queue *q) { return q->belakang < q->depan; }
int isFullQ(Queue *q) { return q->belakang == KAPASITAS - 1; }
int enqueue(Queue *q, int x)
{
    if (isFullQ(q))
        return 0;
    q->belakang++;
    q->data[q->belakang] = x;
    return 1;
}
int dequeue(Queue *q, int *keluar)
{
    if (isEmptyQ(q))
        return 0;
    *keluar = q->data[q->depan];
    q->depan++;
    return 1;
}

typedef struct
{
    int data[KAPASITAS];
    int depan, belakang, jumlah;
} CQueue;
void createCQueue(CQueue *q)
{
    q->depan = 0;
    q->belakang = -1;
    q->jumlah = 0;
}
int isEmptyC(CQueue *q) { return q->jumlah == 0; }
int isFullC(CQueue *q) { return q->jumlah == KAPASITAS; }
int enqueueC(CQueue *q, int x)
{
    if (isFullC(q))
        return 0;
    q->belakang = (q->belakang + 1) % KAPASITAS;
    q->data[q->belakang] = x;
    q->jumlah++;
    return 1;
}
int dequeueC(CQueue *q, int *keluar)
{
    if (isEmptyC(q))
        return 0;
    *keluar = q->data[q->depan];
    q->depan = (q->depan + 1) % KAPASITAS;
    q->jumlah--;
    return 1;
}

void simulasi(int menit, int kedatangan, int layanan)
{
    CQueue q;
    createCQueue(&q);
    int maks = 0, tertolak = 0, terlayani = 0, x;

    for (int t = 1; t <= menit; t++)
    {
        if (t % kedatangan == 0)
        {
            if (!enqueueC(&q, t))
                tertolak++;
        }
        if (t % layanan == 0)
        {
            if (dequeueC(&q, &x))
                terlayani++;
        }
        if (q.jumlah > maks)
            maks = q.jumlah;
    }

    printf("%-12d %-12d %-14d %-12d %-12d %d\n",
           kedatangan, layanan, maks, terlayani, tertolak, q.jumlah);
}

int main(void)
{
    printf("%-12s %-12s %-14s %-12s %-12s %s\n", "Kedatangan",
           "Layanan", "AntreanMaks", "Terlayani", "Tertolak", "Sisa");

    simulasi(120, 3, 2); /* datang lebih lambat daripada dilayani */
    simulasi(120, 2, 2); /* laju datang sama dengan laju layanan  */
    simulasi(120, 2, 3); /* datang lebih cepat daripada dilayani  */
    return 0;
}