// Thoriq Abdillah 22343077


#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 8

int stack[MAXSIZE];
int top = -1;

bool isempty() {
    return top == -1;
}

bool isfull() {
    return top == MAXSIZE - 1;
}

int peek() {
    return stack[top];
}

void push(int data) {
    if (!isfull()) {
        top++;
        stack[top] = data;
    } else {
        printf("Tidak dapat menambahkan data, Stack penuh.\n");
    }
}

int pop() {
    int data;
    if (!isempty()) {
        data = stack[top];
        top--;
        return data;
    } else {
        printf("Tidak dapat mengambil data, Stack kosong.\n");
        return -1; // kembalikan nilai yang tidak valid sebagai penanda error
    }
}

int main() {
    // Menambahkan item ke stack 
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    
    printf("Elemen teratas pada Stack adalah: %d\n", peek());
    
    printf("Semua elemennya adalah: \n");
    // print stack data 
    while (!isempty()) {
        int data = pop();
        printf("%d\n", data);
    }
    
    printf("Stack full: %s\n", isfull() ? "true" : "false");
    printf("Stack empty: %s\n", isempty() ? "true" : "false");
    
    return 0;
}
