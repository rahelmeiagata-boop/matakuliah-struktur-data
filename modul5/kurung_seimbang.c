#include <stdio.h>
#include <stdlib.h>

#define KAPASITAS 100

typedef struct {
    int data[KAPASITAS];
    int atas;
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
    if (isFull(s)) return 0;
    s->data[++s->atas] = x;
    return 1;
}

int pop(Stack *s, int *keluar) {
    if (isEmpty(s)) return 0;
    *keluar = s->data[s->atas--];
    return 1;
}

int seimbang(const char *ekspresi) {
    Stack s;
    createStack(&s);

    for (int i = 0; ekspresi[i] != '\0'; i++) {
        char c = ekspresi[i];

        if (c == '(' || c == '[' || c == '{') {
            if (!push(&s, c)) return 0;
        }
        else if (c == ')' || c == ']' || c == '}') {
            int puncak;

            if (!pop(&s, &puncak)) return 0;

            if (c == ')' && puncak != '(') return 0;
            if (c == ']' && puncak != '[') return 0;
            if (c == '}' && puncak != '{') return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char ekspresi[100];

    printf("Masukkan ekspresi: ");
    fgets(ekspresi, sizeof(ekspresi), stdin);

    if (seimbang(ekspresi))
        printf("Tanda kurung seimbang\n");
    else
        printf("Tanda kurung tidak seimbang\n");

    return 0;
}