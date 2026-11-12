#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struktur Stack
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Membuat Stack
void createStack(Stack *s) {
    s->top = -1;
}

// Mengecek Stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Memasukkan data ke Stack
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    }
}

// Mengeluarkan data dari Stack
int pop(Stack *s, int *value) {
    if (!isEmpty(s)) {
        *value = s->data[s->top--];
        return 1;
    }
    return 0;
}

// Melihat data paling atas
int peek(Stack *s, int *value) {
    if (!isEmpty(s)) {
        *value = s->data[s->top];
        return 1;
    }
    return 0;
}

// Menentukan prioritas operator
int derajat(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Mengubah Infix menjadi Postfix
void infixKePostfix(const char *in, char *out) {
    Stack s;
    createStack(&s);

    int k = 0, puncak;

    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];

        if (c >= '0' && c <= '9') {
            out[k++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s)) {
                peek(&s, &puncak);

                if (puncak == '(') break;

                pop(&s, &puncak);
                out[k++] = (char)puncak;
            }

            pop(&s, &puncak);
        }
        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/') {

            while (!isEmpty(&s)) {
                peek(&s, &puncak);

                if (puncak == '(' ||
                    derajat((char)puncak) < derajat(c)) {
                    break;
                }

                pop(&s, &puncak);
                out[k++] = (char)puncak;
            }

            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        pop(&s, &puncak);
        out[k++] = (char)puncak;
    }

    out[k] = '\0';
}

// Evaluasi Postfix
int evalPostfix(const char *pf) {
    Stack s;
    createStack(&s);

    for (int i = 0; pf[i] != '\0'; i++) {
        char c = pf[i];

        if (c >= '0' && c <= '9') {
            push(&s, c - '0');
        }
        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/') {

            int a, b;

            if (!pop(&s, &b) || !pop(&s, &a)) {
                return 0;
            }

            if (c == '+') push(&s, a + b);
            else if (c == '-') push(&s, a - b);
            else if (c == '*') push(&s, a * b);
            else {
                if (b == 0) return 0;
                push(&s, a / b);
            }
        }
    }

    int hasil;

    if (!pop(&s, &hasil) || !isEmpty(&s)) {
        return 0;
    }

    return hasil;
}

// Program utama
int main() {
    char infix[MAX], postfix[MAX];

    printf("Masukkan ekspresi infix: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixKePostfix(infix, postfix);

    printf("Hasil Postfix : %s\n", postfix);
    printf("Hasil Evaluasi: %d\n", evalPostfix(postfix));

    return 0;
}