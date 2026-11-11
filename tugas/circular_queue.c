#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;
int jumlah = 0; // untuk menghitung banyak data di antrean

int isFull()
{
    return jumlah == MAX;
}

int isEmpty()
{
    return jumlah == 0;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue penuh\n");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        jumlah++;
        printf("Data %d berhasil ditambahkan\n", data);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Data %d dihapus dari antrean\n", queue[front]);
        front = (front + 1) % MAX;
        jumlah++;
        if (isEmpty())
        {
            front = -1;
            rear = -1;
        }
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Data paling depan: %d\n", queue[front]);
    }
}

void tampil()
{
    int i, idx;
    if (isEmpty())
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Isi antrean: ");
        idx = front;
        for (i = 0; i < jumlah; i++)
        {
            printf("%d", queue[idx]);
            idx = (idx + 1) % MAX;
        }
        printf("\n");
    }
}

int main()
{
    int pilihan, data;

    do
    {
        printf("Menu Circular Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Tampilkan antrean: \n");
        printf("5. Keluar\n");
        printf("Pilihan Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case3:
            peek();
            break;

        case 4:
            tampil();
            break;

        case5:
            printf("Program selesai\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
        }
    } while (pilihan != 5);
    
    return 0;
}