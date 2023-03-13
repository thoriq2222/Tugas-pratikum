// Thoriq Abdillah 22343077
/*
    Buatlah program sederhana pembalik kata dengan menggunakan stack. Program terdiri dari 3 menu, 
    1) Input Kata
    2) Balik Kata
    3) Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

struct Stack {
    char data[MAXSIZE];
    int top;
};

// Deklarasi fungsi
void initStack(struct Stack *);
void push(struct Stack *, char);
char pop(struct Stack *);
int isEmpty(struct Stack *);
int i;

int main()
{
    struct Stack stack;
    initStack(&stack);
    int choice;

    while(1) {
        printf("\nMenu Pembalik Kata\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char str[MAXSIZE];
                printf("Masukkan kata: ");
                scanf("%s", str);
                int length = strlen(str);

                for(i=0; i<length; i++) {
                    push(&stack, str[i]);
                }
                break;
            }
            case 2: {
                printf("Kata yang dibalik: ");
                while(!isEmpty(&stack)) {
                    printf("%c", pop(&stack));
                }
                printf("\n");
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Pilihan tidak valid!\n");
            }
        }
    }

    return 0;
}

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char data) {
    if(s->top == MAXSIZE-1) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++s->top] = data;
}

char pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->data[s->top--];
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}
