#include <stdio.h>

int main() {
    int umur = 19;
    int punyaKTM = 1;

    printf("AND: %d\n", umur >= 18 && punyaKTM == 1);
    printf("OR: %d\n", umur < 18 || punyaKTM == 1);
    printf("NOT: %d\n", !(punyaKTM == 1));

    return 0;
}