#include <stdio.h>

#define MAX 10

struct Pelanggan
{
    int data;
    int priority;
};

struct Pelanggan queue[MAX];
int jumlah = 0;

int isFull()
{
    return jumlah == MAX;
}

int isEmpty()
{
    return jumlah == 0;
}

int cariPrioritas()
{
    int i, idx = 0;
    for (i = 1; i < jumlah; i++)
    {
        if (queue[i].priority < queue[idx].priority)
        {
            idx = i;
        }
    }
    return idx;
}

void tambah(int data, int priority)
{
    if (isFull())
    {
        printf("Antrean Penuh\n");
    }
    else if (priority < 1 || priority > 3)
    {
        printf("Priotitas harus 1, 2, atau 3\n");
    }
    else
    {
        queue[jumlah].data = data;
        queue[jumlah].priority = priority;
        jumlah++;
        printf("Data %d (priotitas %d) berhasil ditambahkan\n", data, priority);
    }
}

void layani()
{
    int i, idx;
    if (isEmpty())
    {
        printf("Antrean kosong\n");
    }
    else
    {
        idx = cariPrioritas();
        printf("Melayani data %d (priotitas %d)\n", queue[idx].data, queue[idx].priority);

        for (i = idx; i < jumlah - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        jumlah--;
    }
}

void tampil()
{
    int i;
    if (isEmpty())
    {
        printf("Antrean ksong\n");
    }
    else
    {
        printf("Isis antrean (urutan masuk):\n");
        for (i = 0; i < jumlah; i++)
        {
            printf("%d. Data: %d, Prioritas: %d\n", i + 1, queue[i].data, queue[i].priority);
        }
    }
}

void berikutnya()
{
    int idx;
    if (isEmpty())
    {
        printf("Antrean kosong\n");
    }
    else
    {
        idx = cariPrioritas();
        printf(" Data berikutnya: %d (priotitas %d)\n", queue[idx]. data, queue[idx].priority);
    }
}

int main() 
{
    int pilihan, data, priority;

    do
    {
        printf("\n Menu Priority Queue\n");
        printf("1. Tambah data antrean\n");
        printf("2. Layani data berdasarkan prioritas\n");
        printf("3. Tampilkan seluruh antrean\n");
        printf("4. Lihat data berikutnya\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &data);
            printf("Masukkan prioritas (1-3): ");
            scanf("%d", &priority);
            tambah(data, priority);
            break;
        case 2:
            layani();
            break;
        case 3:
            tampil();
            break;
        case 4:
            berikutnya();
            break;
        case 5:
            printf("Program selesai.\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);

    return 0;
}