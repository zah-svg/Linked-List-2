#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct untuk data mahasiswa
typedef struct{
	char nama[50];
	int nilai;
}infotype;

// struct untuk node linked list
typedef struct tElmList *address;
typedef struct tElmList{
	infotype info;
	address next;
}ElmList;

// struct untuk linked list
typedef struct{
	address first;
}List;

// fungsi-fungsi yang akan dipakai
void createList(List *L);
void printList(List L);
address allocate(infotype data);
void insertAscending(List *L, infotype data);
void insertDescending(List *L, infotype data);
void copyListByValue(List *L1, List *L2, int threshold);
int countElements(List L);
void deleteDuplicate(List *L);
void deleteList(List *L);
void printListDescending(List L);
address searchByName(List L, char *nama);
void updateNilai(List *L, char *nama, int nilaiBaru);

#endif


