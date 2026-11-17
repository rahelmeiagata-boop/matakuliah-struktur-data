#include <stdio.h>
#include <stdlib.h>

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

void preorder(Simpul *akar) {
    if (akar == NULL) return;

    printf("%d ", akar->data);
    preorder(akar->kiri);
    preorder(akar->kanan);
}

void inorder(Simpul *akar) {
    if (akar == NULL) return;

    inorder(akar->kiri);
    printf("%d ", akar->data);
    inorder(akar->kanan);
}

void postorder(Simpul *akar) {
    if (akar == NULL) return;

    postorder(akar->kiri);
    postorder(akar->kanan);
    printf("%d ", akar->data);
}

void levelOrder(Simpul *akar) {
    if (akar == NULL) return;

    Simpul *antre[200];
    int depan = 0, belakang = 0;

    antre[belakang++] = akar;

    while (depan < belakang) {
        Simpul *s = antre[depan++];

        printf("%d ", s->data);

        if (s->kiri != NULL)
            antre[belakang++] = s->kiri;

        if (s->kanan != NULL)
            antre[belakang++] = s->kanan;
    }
}

int tinggi(Simpul *akar) {
    if (akar == NULL) return -1;

    int kiri = tinggi(akar->kiri);
    int kanan = tinggi(akar->kanan);

    return (kiri > kanan ? kiri : kanan) + 1;
}

void bebaskan(Simpul *akar) {
    if (akar == NULL) return;

    bebaskan(akar->kiri);
    bebaskan(akar->kanan);

    free(akar);
}

// Program utama
int main(void) {
    Simpul *akar = NULL;

    int contoh[7] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++) {
        akar = sisipBST(akar, contoh[i]);
    }

    printf("Pengujian Traversal BST\n");

    printf("Preorder    : ");
    preorder(akar);
    printf("\n");

    printf("Inorder     : ");
    inorder(akar);
    printf("\n");

    printf("Postorder   : ");
    postorder(akar);
    printf("\n");

    printf("Level order : ");
    levelOrder(akar);
    printf("\n");

    printf("Tinggi pohon: %d\n", tinggi(akar));

    bebaskan(akar);

    return 0;
}