#include <stdio.h>

#define KAPASITAS 100

typedef struct {
    int data[KAPASITAS];
    int atas;      /* indeks puncak, minus satu bila kosong */
} Stack;

void createStack(Stack *s) {
    s->atas = -1;
}

int isEmpty(Stack *s) {
    return s->atas == -1;
}

int isFull(Stack *s) {
    return s->atas == KAPASITAS - 1;
}

int push(Stack *s, int x) {
    if (isFull(s))
        return 0;      /* stack overflow dicegah */

    s->atas++;
    s->data[s->atas] = x;
    return 1;
}

int pop(Stack *s, int *keluar) {
    if (isEmpty(s))
        return 0;      /* stack underflow dicegah */

    *keluar = s->data[s->atas];
    s->atas--;         /* nilai lama tidak dihapus */
    return 1;   
}

int peek(Stack *s, int *nilai) {
    if (isEmpty(s))
        return 0;

    *nilai = s->data[s->atas];
    return 1;
}

int main() {
    Stack s;
    int keluar;

    createStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    while (!isEmpty(&s)) {
        pop(&s, &keluar);
        printf("%d\n", keluar);
    }

    return 0;
}