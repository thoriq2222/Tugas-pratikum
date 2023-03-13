// Thoriq Abdillah 22343077


/*
Buatlah sebuah program dengan menggunakan stack yang berfungsi untuk menyimpan data nilai 
mahasiswa yang terdiri dari NIM, nama, dan nilai mahasiswa. Tambahkan beberapa fasilitas 
seperti sorting (pengurutan data), push (menambahkan data), pop (mengambil data), display 
(untuk menampilkan data stack). Tampilan dan menu sesuaikan dengan kreativitas masing-masing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Mahasiswa {
    int nim;
    char nama[50];
    float nilai;
} Mahasiswa;

Mahasiswa stack[MAX_SIZE];
int top = -1;
int i,j;

void push() {
    if (top == MAX_SIZE - 1) {
        printf("Stack penuh.\n");
        return;
    }
    
    Mahasiswa mhs;
    printf("Masukkan NIM: ");
    scanf("%d", &mhs.nim);
    printf("Masukkan Nama: ");
    scanf("%s", mhs.nama);
    printf("Masukkan Nilai: ");
    scanf("%f", &mhs.nilai);
    stack[++top] = mhs;
    printf("Data berhasil ditambahkan ke stack.\n");
}

void pop() {
    if (top == -1) {
        printf("Stack kosong.\n");
        return;
    }
    
    Mahasiswa mhs = stack[top--];
    printf("Data mahasiswa yang dihapus: NIM = %d, Nama = %s, Nilai = %f.\n", mhs.nim, mhs.nama, mhs.nilai);
}

void display() {
    if (top == -1) {
        printf("Stack kosong.\n");
        return;
    }
    
    printf("Data Mahasiswa pada Stack: \n");
    for (i = top; i >= 0; i--) {
        Mahasiswa mhs = stack[i];
        printf("NIM = %d, Nama = %s, Nilai = %f.\n", mhs.nim, mhs.nama, mhs.nilai);
    }
}

void sort() {
    if (top == -1) {
        printf("Stack kosong.\n");
        return;
    }
    
    for (i = 0; i <= top; i++) {
        for (j = i + 1; j <= top; j++) {
            if (stack[i].nilai < stack[j].nilai) {
                Mahasiswa temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
    
    printf("Data Mahasiswa pada Stack setelah diurutkan: \n");
    for (i = top; i >= 0; i--) {
        Mahasiswa mhs = stack[i];
        printf("NIM = %d, Nama = %s, Nilai = %f.\n", mhs.nim, mhs.nama, mhs.nilai);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu: \n");
        printf("1. Tambah Data Mahasiswa ke Stack\n");
        printf("2. Hapus Data Mahasiswa dari Stack\n");
        printf("3. Tampilkan Data Mahasiswa pada Stack\n");
        printf("4. Urutkan Data Mahasiswa pada Stack berdasarkan Nilai\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                sort();
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan salah.\n");
        }
    }
return 0;
}


