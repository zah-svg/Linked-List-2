#include "linked.h"

void createList(List *L){
	L -> first = NULL;
}

void printList(List L){
	address curr = L.first;
	while (curr != NULL){
		printf("%s - %d\n", curr -> info.nama, curr -> info.nilai);
		curr = curr->next;
	}
}

address allocate(infotype data){
	address newNode = (address)malloc(sizeof(ElmList));
	if (newNode == NULL){
		printf("Alokasi gagal!\n");
		return NULL;
	}
	newNode -> info = data;
	newNode -> next = NULL;
	return newNode;
}

void insertAscending(List *L, infotype data){
	address newNode = allocate(data);
	if (newNode == NULL){
		return;
	}
	address prev = NULL, curr = L->first;
	while (curr != NULL && strcmp(curr->info.nama, data.nama) < 0){
		prev = curr;
		curr = curr->next;
	}
	if(prev == NULL){
		newNode->next = L->first;
		L->first = newNode;
	} else{
		prev->next = newNode;
		newNode->next = curr;
	}
}

void insertDescending(List *L, infotype data){
	address newNode = allocate(data);
	if (newNode == NULL){
		return;
	}
	address prev = NULL, curr = L->first;
	while (curr != NULL && curr->info.nilai > data.nilai){
		prev = curr;
		curr = curr->next;
	}
	if(prev == NULL){
		newNode->next = L->first;
		L->first = newNode;
	}else{
		prev->next = newNode;
		newNode->next = curr;
	}
}

void copyListByValue(List *L1, List *L2, int threshold){
	address curr = L1->first;
	while (curr !=NULL){
		if (curr->info.nilai > threshold){
			insertAscending(L2,curr->info);
		}
		curr = curr->next;
	}
}

int countElements(List L){
	int count = 0;
	address curr = L.first;
	while (curr != NULL){
		count++;
		curr = curr->next;
	}
	return count;
}

void deleteDuplicate(List *L){
	address curr = L->first;
	while(curr != NULL && curr->next != NULL){
		address prev = curr;
		address temp = curr->next;
		while(temp != NULL){
			if(strcmp(curr->info.nama, temp->info.nama) == 0){
				prev->next = temp->next;
				free(temp);
				temp = prev->next;
			}else{
				prev = temp;
				temp = temp->next;
			}
		}
		curr = curr->next;
	}
}

void deleteList(List *L){
	address curr = L->first, temp;
	while(curr != NULL){
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	L->first = NULL;
}

void printListDescending(List L){
	List tempList;
	createList(&tempList);
	address curr = L.first;
	while(curr != NULL){
		insertDescending(&tempList, curr->info);
		curr = curr->next;
	}
	printList(tempList);
	deleteList(&tempList);
}

address searchByName(List L, char *nama){
	address curr = L.first;
	while(curr != NULL){
		if(strcmp(curr->info.nama, nama) == 0){
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

void updateNilai(List *L, char *nama, int nilaiBaru){
	address mahasiswa = searchByName(*L, nama);
	if(mahasiswa != NULL){
		mahasiswa->info.nilai = nilaiBaru;
	} else{
		printf("Mahasiswa dengan nama %s tidak ditemukan!\n", nama);
	}
}
