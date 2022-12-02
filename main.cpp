#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//’P•ûŒüƒŠƒXƒg‚Ì\‘¢‘Ì
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

	//æ“ª‚ÌƒZƒ‹‚ÌéŒ¾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true){
		switch (play)
		{
		case 0:
			printf("[—v‘f‚Ì‘€ì]\n");
			printf("1.—v‘f‚Ìˆê——•\Ž¦\n");
			printf("2.”CˆÓ‚ÌˆÊ’u‚É‚É—v‘f‚Ì‘}“ü\n");
			printf("\n");
			printf("---------------------------\n");
			printf("‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢\n");
			scanf_s("%d", &play);

			break;
		case 1:
			printf("[—v‘f‚Ìˆê——•\Ž¦]\n");
			printf("—v‘fˆê——:{\n");
			Index(&head);
			printf("}\n");
			printf("\n");
			printf("—v‘f”:%d\n",0);
			printf("\n");
			printf("--------------------------\n");
			printf("0.‰Šú‰æ–Ê‚É–ß‚é\n");
			scanf_s("%d", &play);

			break;
		case 2:
			printf("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©\n");
			scanf_s("%d", &iterator);

			printf("‘}“ü‚·‚é’l‚ð“ü—Í\n");
			char ko[256];

			scanf_s("%256s", ko,257);

			insertCell = getInsertCellAddress(&head, iterator);


			Create(insertCell, ko);
			

			printf("\n");
			printf("--------------------------\n");

			printf("0.‰Šú‰æ–Ê‚É–ß‚é\n");
			scanf_s("%d", &play); 

			break;
		}
		
		printf("\n");
	}

	return 0;
}


void Create(CELL* cell,char *val) {
	//V‹KƒZƒ‹
	CELL* newCell;
	
	//V‹KƒZƒ‹‚Ìƒƒ‚ƒŠŠm•Û
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