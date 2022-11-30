#include <stdio.h>
#include <stdlib.h>

//�P�������X�g�̍\����
typedef struct cell {
	int val;
	struct cell *next;
}CELL;

void create(CELL* cell, int val);
void index(CELL* cell);


int main(){
	int val;

	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;

	printf("start\n");
	while (true){
		printf("���͂����������Ō���ɒǉ�\n");
		scanf_s("%d", &val);
		printf("LIST\n");

		//�Ō���ɃZ����ǉ�
		create(&head, val);
		
		//���X�g�̈ꗗ�\��
		index(&head);
		printf("\n");
	}

	return 0;
}


void create(CELL* cell, int val) {
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
	cell->next = newCell;
}


void index(CELL* cell) {
	while (cell->next != nullptr) {
		cell = cell->next;
		printf("%d\n", cell->val);
	}
}