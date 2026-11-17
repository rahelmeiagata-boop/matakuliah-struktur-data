#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long langkahCari = 0;

typedef struct Simpul {
    int data;
    struct Simpul *kiri, *kanan;
} Simpul;

Simpul *buatSimpul(int nilai) {
    Simpul *baru = (Simpul *) malloc(sizeof(Simpul));

    if (baru == NULL) return NULL;

    baru->data = nilai;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

Simpul *sisipBST(Simpul *akar, int nilai) {
    if (akar == NULL)
        return buatSimpul(nilai);

    if (nilai < akar->data)
        akar->kiri = sisipBST(akar->kiri, nilai);
    else if (nilai > akar->data)
        akar->kanan = sisipBST(akar->kanan, nilai);

    return akar;
}

int tinggi(Simpul *akar) {
    if (akar == NULL) return -1;

    int kiri = tinggi(akar->kiri);
    int kanan = tinggi(akar->kanan);

    return (kiri > kanan ? kiri : kanan) + 1;
}

Simpul *cariHitung(Simpul *akar, int nilai) {
    langkahCari = 0;

    while (akar != NULL) {
        langkahCari++;

        if (akar->data == nilai)
            return akar;

        akar = (nilai < akar->data)
               ? akar->kiri : akar->kanan;
    }

    return NULL;
}

void bebaskan(Simpul *akar) {
    if (akar == NULL) return;

    bebaskan(akar->kiri);
    bebaskan(akar->kanan);

    free(akar);
}

// Program utama
int main(void) {
    srand(12345);

    int ukuran[3] = {15, 100, 1000};

    printf("Percobaan Pengaruh Urutan Penyisipan\n");

    printf("%-8s %-12s %-10s %-16s\n",
           "n", "Pola sisip", "Tinggi", "Langkah cari");

    for (int u = 0; u < 3; u++) {
        int n = ukuran[u];

        Simpul *acak = NULL;
        Simpul *urut = NULL;

        for (int i = 0; i < n; i++) {
            acak = sisipBST(acak, rand() % (n * 10));
        }

        for (int i = 1; i <= n; i++) {
            urut = sisipBST(urut, i);
        }

        cariHitung(acak, -1);

        printf("%-8d %-12s %-10d %-16ld\n",
               n, "Acak", tinggi(acak), langkahCari);

        cariHitung(urut, n);

        printf("%-8d %-12s %-10d %-16ld\n",
               n, "Terurut", tinggi(urut), langkahCari);

        bebaskan(acak);
        bebaskan(urut);
    }

    return 0;
}
