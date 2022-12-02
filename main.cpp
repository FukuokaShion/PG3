#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//�P�������X�g�̍\����
typedef struct cell {
	char val[256];
	struct cell* prev;
	struct cell* next;
}CELL;

void Create(CELL* cell, char* val);
void Deleta(CELL* cell);
void Index(CELL* cell);
void Print(CELL* cell,int *turn);
void Edit(CELL* cell, char* val);
int Size(CELL* cell);
CELL* getInsertCellAddress(CELL* endCell, int iterator);
CELL* getSelectCellAddress(CELL* endCell, int iterator);

int main(){
	int scene = 0;
	int select = 0;
	int display = 0;
	char val[256];
	CELL* selectCell;
	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;



	while (true){
		switch (scene)
		{
		case 0:
			system("cls");
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			if (0 < Size(&head)) {
				printf("3.�v�f�̕ҏW\n");
				printf("4.�v�f�̍폜\n");
			}
			printf("\n");
			printf("------------------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &scene);

			break;
		case 1:
			system("cls");
			printf("[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n");
			printf("\n");
			printf("------------------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &select);
			if (select == 1) {
				display = 1;
			}else if (select == 2) {
				display = 2;
			}else if (select == 9) {
				scene = 0;
			}

			switch (display)
			{
			case 1:
				system("cls");
				printf("[�v�f�̈ꗗ�\��]\n");
				Index(&head);
				printf("\n");
				printf("------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				scanf_s("%d", &select);
				if (select == 1) {
					scene = 1;
				}else if (select == 2) {
					scene = 0;
				}

				break;
			case 2:
				system("cls");
				printf("[���Ԃ��w�肵�ėv�f��\��]\n");
				printf("�\���������v�f�̏��Ԃ��w�肵�Ă�������");
				printf("-1����͂ŕ\��");
				printf("\n");
				int turn[256];
				int turnMax;
				for (int i = 0; i < 256;i++) {
					scanf_s("%d:", &turn[i]);
					if (turn[i] == -1) {
						turnMax = i;
						break;
					}
				}
				Print(&head, turn);


				printf("\n");
				printf("------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				scanf_s("%d", &select);
				if (select == 1) {
					scene = 1;
				}else if (select == 2) {
					scene = 0;
				}

				break;
			}

			break;
		case 2:
			system("cls");
			printf("[���X�g�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ԍ�����͂��Ă�������\n");
			scanf_s("%d", &select);
			selectCell = getInsertCellAddress(&head, select);

			printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%256s", val, 257);
			Create(selectCell, val);

			printf("�v�f%s��%d�Ԗڂɑ}������܂���\n", val, select);

			printf("\n");
			printf("------------------------------------\n");
			printf("1.�v�f�̑���ɖ߂�\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}

			break;
		case 3:
			system("cls");
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &select);

			if (select >= Size(&head)) {
				selectCell = getSelectCellAddress(&head, select);

				printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", select);
				scanf_s("%256s", val, 257);
				Edit(selectCell, val);

				printf("%d�Ԗڂ̗v�f�̒l��%s�ɕύX����܂���\n", select, val);
				printf("\n");
			}else {
				printf("%d�Ԗڂ̗v�f��������܂���ł���\n", select);
			}
			printf("------------------------------------\n");
			printf("1.�v�f�̑���ɖ߂�\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}

			break;
		case 4:
			system("cls");
			printf("[�v�f�̍폜]\n");
			printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &select);
			if (select >= Size(&head)) {
				selectCell = getSelectCellAddress(&head, select);
				Deleta(selectCell);
				printf("%d�Ԗڂ̗v�f���폜���܂���\n", select);
			}else {
				printf("%d�Ԗڂ̗v�f��������܂���ł���\n", select);
			}

			printf("\n");
			printf("------------------------------------\n");
			printf("1.�v�f�̑���ɖ߂�\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}



			break;
		}

		//�Ō���ɃZ����ǉ�
		
		//���X�g�̈ꗗ�\��
		printf("\n");
	}

	return 0;
}

void Create(CELL* cell, char* val) {
	//�V�K�Z��
	CELL* newCell;

	//�V�K�Z���̃������m��
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
	if (cell->next == nullptr) {
		cell = cell->prev;
		cell->next = nullptr;
	}else if(cell->next != nullptr) {
		CELL* nextCell = cell->next;
		CELL* prevCell = cell->prev;
		cell = nextCell;
		prevCell->next = cell;
		cell->prev = prevCell;
	}
}

void Print(CELL* cell, int* trun) {
	for (int i = 0; i < 256; i++) {
		if (trun[i] != -1) {
			CELL* selectCell;
			selectCell = getSelectCellAddress(cell, trun[i]);
			printf("%d : %s\n", trun[i], selectCell->val);
		}else{
			break;
		}
	}
}

void Index(CELL* endCell) {
	int no = 0;
	printf("�v�f�ꗗ:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : %s\n", no, endCell->val);
		no++;
	}
	printf("}\n");
	printf("\n");
	printf("�v�f��:%d\n", no);
}

void Edit(CELL* cell, char* val) {
	strcpy_s(cell->val, 256, val);
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


CELL* getSelectCellAddress(CELL* endCell, int iterator) {
	for (int i = 0; i < iterator + 1; i++) {
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

int Size(CELL* cell) {
	int no = 0;
	while (cell->next != nullptr) {
		cell = cell->next;
		no++;
	}
	return no;
}