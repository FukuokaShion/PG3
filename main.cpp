#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//単方向リストの構造体
typedef struct cell {
	char val[256];
	struct cell* prev;
	struct cell* next;
}CELL;

void Create(CELL* cell, char* val);
void Deleta(CELL* cell);
void Index(CELL* cell);
CELL* getInsertCellAddress(CELL* endCell, int iterator);



int main() {
	int iterator;
	CELL* insertCell;

	//先頭のセルの宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	char name[29][256] = {
	"Tokyo",
	"Kanda",
	"Akihabara",
	"Okachimachi",
	"Ueno",
	"Uguisudani",
	"Nippori",
	"NishiNippori",
	"Tabata",
	"Komagome",
	"Sugamo",
	"Otsuka",
	"Ikebukuro",
	"Mejiro",
	"Takadanobaba",
	"ShinOkubo",
	"Shinjuku",
	"Yoyogi",
	"Harajuku",
	"Shibuya",
	"Ebisu",
	"Meguro",
	"Gotanda",
	"Osaki",
	"Shinagawa",
	"Tamachi",
	"Hamamatsucho",
	"Shimbashi",
	"Yurakucho"
	};
	for (int i = 0; i < 29; i++) {
		insertCell = getInsertCellAddress(&head, i);
		Create(insertCell, name[i]);
	}
	Index(&head);

	printf("----------------------------------");

	insertCell = getInsertCellAddress(&head, 25);
	char iterater[256] = "TakanawaG";
	Create(insertCell, iterater);
	Index(&head);

	system("pause");
	return 0;
}


void Create(CELL* cell, char* val) {
	//新規セル
	CELL* newCell;

	//新規セルのメモリ確保
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val, 256, val);
	newCell->next = cell->next;
	newCell->prev = cell;

	if (cell->next) {
		CELL* nextCell = cell->next;
		nextCell->prev = newCell;
	}

	cell->next = newCell;

}

void Deleta(CELL* cell) {
	while (cell->next != nullptr) {
		cell = cell->next;
	}
	cell = cell->prev;
	cell->next = nullptr;
}

void Index(CELL* endCell) {
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : ", no);
		printf("%s\n", endCell->val);
		no++;
	}
}


CELL* getInsertCellAddress(CELL* endCell, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCell->next) {
			endCell = endCell->next;
		}
		else
		{
			break;
		}
	}
	return endCell;
}