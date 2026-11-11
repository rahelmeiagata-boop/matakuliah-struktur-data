#include <stdio.h>

int main() {
    int x = 4;

    printf("Awal: x = %d\n", x);

    x += 6;
    printf("x += 6: %d\n", x);

    x -= 2;
    printf("x -= 2: %d\n", x);

    x *= 4;
    printf("x *= 4: %d\n", x);

    x /= 2;
    printf("x /= 2: %d\n", x);

    x %= 5;
    printf("x %%= 5: %d\n", x);

    x = 12;
    x &= 4;
    printf("x &= 4: %d\n", x);

    x = 12;
    x |= 4;
    printf("x |= 4: %d\n", x);

    x = 12;
    x ^= 4;
    printf("x ^= 4: %d\n", x);

    x = 32;
    x >>= 2;
    printf("x >>= 2: %d\n", x);

    x = 3;
    x <<= 3;
    printf("x <<= 3: %d\n", x);

    return 0;
}