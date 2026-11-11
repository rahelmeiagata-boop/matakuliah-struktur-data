#include <stdio.h>

int main() {
    int angka[] = {14, 27, 39, 45, 62, 78};

    int ukuran = sizeof(angka) / sizeof(angka[0]);

    printf("Jumlah elemen array: %d\n", ukuran);

    return 0;
}