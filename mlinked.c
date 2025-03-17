#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

int main() {
    List L1, L2;
    createList(&L1);
    createList(&L2);

    int n, i = 0;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    getchar();

    while (i < n) {
        infotype data;
        printf("Masukkan nama mahasiswa %d: ", i + 1);
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strcspn(data.nama, "\n")] = 0;

        printf("Masukkan nilai UTS: ");
        scanf("%d", &data.nilai);
        getchar();

        insertAscending(&L1, data);
        i++;
    }

    printf("\nIsi List L1 (Ascending berdasarkan Nama):\n");
    printList(L1);

    printf("\nIsi List L1 (Descending berdasarkan Nilai):\n");
    printListDescending(L1);

    printf("\nJumlah mahasiswa dalam L1: %d\n", countElements(L1));

    copyListByValue(&L1, &L2, 70); // karena nilai ambang batas adalah 70, maka nilai threshold adalah 70

    printf("\nIsi List L2 (Mahasiswa dengan nilai > 70):\n");
    printList(L2);

    deleteDuplicate(&L2);
    
    printf("\nIsi List L2 setelah menghapus duplikat:\n");
    printList(L2);

    deleteList(&L1);
    deleteList(&L2);

    printf("\nList L1 dan L2 telah dihapus.\n");

    return 0;
}

