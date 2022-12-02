#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//単方向リストの構造体
typedef struct cell {
	char val[256];
	struct cell* prev;
	struct cell *next;
}CELL;

void Create(CELL* cell,char *val);
void Deleta(CELL* cell);
void Index(CELL* cell);
CELL* getInsertCellAddress(CELL* endCell, int iterator);



int main(){
	int play = 0;
	int val;


	int iterator;
	int inputValue;
	CELL* insertCell;

	//先頭のセルの宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true){
		switch (play)
		{
		case 0:
			printf("[要素の操作]\n");
			printf("1.要素の一覧表示\n");
			printf("2.任意の位置にに要素の挿入\n");
			printf("\n");
			printf("---------------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &play);

			break;
		case 1:
			printf("[要素の一覧表示]\n");
			printf("要素一覧:{\n");
			Index(&head);
			printf("}\n");
			printf("\n");
			printf("要素数:%d\n",0);
			printf("\n");
			printf("--------------------------\n");
			printf("0.初期画面に戻る\n");
			scanf_s("%d", &play);

			break;
		case 2:
			printf("何番目のセルの後ろに挿入しますか\n");
			scanf_s("%d", &iterator);

			printf("挿入する値を入力\n");
			char ko[256];

			scanf_s("%256s", ko,257);

			insertCell = getInsertCellAddress(&head, iterator);


			Create(insertCell, ko);
			

			printf("\n");
			printf("--------------------------\n");

			printf("0.初期画面に戻る\n");
			scanf_s("%d", &play); 

			break;
		}
		
		printf("\n");
	}

	return 0;
}


void Create(CELL* cell,char *val) {
	//新規セル
	CELL* newCell;
	
	//新規セルのメモリ確保
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val,256, val);
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
		printf("%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%s\n", endCell->val);
		printf("(%p\n)", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}


CELL* getInsertCellAddress(CELL *endCell,int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCell->next) {
			endCell = endCell->next;
		}else
		{
			break;
		}
	}
	return endCell;
}