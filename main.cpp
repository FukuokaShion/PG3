#include <stdio.h>
#include <stdlib.h>

//�P�������X�g�̍\����
typedef struct cell {
	int val;
	struct cell* prev;
	struct cell *next;
}CELL;

void Create(CELL* cell, int val);
void Deleta(CELL* cell);
void Index(CELL* cell);


int main(){
	int play = 0;
	int val;

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
			printf("2.�Ō���ɗv�f�̑}��\n");
			printf("3.�Ō���̗v�f�̍폜\n");
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
			printf("[���X�g�v�f�̑}��]\n");
			printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%d", &val);
			Create(&head, val);
			printf("�v�f<%d>�����X�g�̍Ō���ɑ}������܂���\n", val);
			printf("\n");
			printf("--------------------------\n");
			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &play);

			break;
		case 3:
			printf("[�v�f�̍폜]\n");
			printf("�Ō���̗v�f���폜���܂���\n");
			Deleta(&head);
			printf("\n\n");
			printf("--------------------------\n");
			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &play);

			break;
		}

		//�Ō���ɃZ����ǉ�
		
		//���X�g�̈ꗗ�\��
		printf("\n");
	}

	return 0;
}


void Create(CELL* cell, int val) {
	//�V�K�Z��
	CELL* newCell;
	
	//�V�K�Z���̃������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->next = nullptr;

	//�Ō�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y��
	while (cell->next != nullptr) {
		cell = cell->next;
	}
	//�ǉ��O�̍Ō���ɐV�K�Z���̃|�C���^����
	newCell->prev = cell;
	cell->next = newCell;
}

void Deleta(CELL* cell) {
	while (cell->next != nullptr) {
		cell = cell->next;
	}
	cell = cell->prev;
	cell->next = nullptr;
}

void Index(CELL* cell) {
	while (cell->next != nullptr) {
		cell = cell->next;
		printf("%d\n", cell->val);
	}
}