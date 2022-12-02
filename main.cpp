#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//�P�������X�g�̍\����
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

	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true){
		switch (play)
		{
		case 0:
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.�C�ӂ̈ʒu�ɂɗv�f�̑}��\n");
			printf("\n");
			printf("---------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &play);

			break;
		case 1:
			printf("[�v�f�̈ꗗ�\��]\n");
			printf("�v�f�ꗗ:{\n");
			Index(&head);
			printf("}\n");
			printf("\n");
			printf("�v�f��:%d\n",0);
			printf("\n");
			printf("--------------------------\n");
			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &play);

			break;
		case 2:
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂���\n");
			scanf_s("%d", &iterator);

			printf("�}������l�����\n");
			char ko[256];

			scanf_s("%256s", ko,257);

			insertCell = getInsertCellAddress(&head, iterator);


			Create(insertCell, ko);
			

			printf("\n");
			printf("--------------------------\n");

			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &play); 

			break;
		}
		
		printf("\n");
	}

	return 0;
}


void Create(CELL* cell,char *val) {
	//�V�K�Z��
	CELL* newCell;
	
	//�V�K�Z���̃������m��
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