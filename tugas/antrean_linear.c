#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue penuh\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
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
        front++;
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
    int i;
    if (isEmpty())
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Isi antrean: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int pilihan, data;

    do
    {
        printf("\n Menu Antrean Linear\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Tampilkan antrean\n");
        printf("5. Keluar\n");
        printf("Pilihan Menu: \n");
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

        case 3:
            peek();
            break;

        case 4:
            tampil();
            break;

        case 5:
            printf("Program selesai\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
        }
    } while (pilihan != 5);

    return 0;

}