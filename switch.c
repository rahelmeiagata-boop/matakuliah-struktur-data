#include <stdio.h>

int main() {
    int pilihan = 2;

    switch (pilihan) {
        case 1:
            printf("Menu makanan\n");
            break;
        case 2:
            printf("Menu minuman\n");
            break;
        case 3:
            printf("Menu camilan\n");
            break;
        default:
            printf("Pilihan tidak tersedia\n");
    }

    return 0;
}