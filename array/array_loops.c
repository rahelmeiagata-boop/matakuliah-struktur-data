#include <stdio.h>

int main() {
    int angka[] = {11, 23, 35, 49, 67, 82, 94};

    int ukuran = sizeof(angka) / sizeof(angka[0]);

    for (int i = 0; i < ukuran; i++) {
        printf("%d\n", angka[i]);
    }

    return 0;
}