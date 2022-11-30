#include <stdio.h>
#include <stdlib.h>

//単方向リストの構造体
typedef struct cell {
	int val;
	struct cell *next;
}CELL;

void create(CELL* cell, int val);
void index(CELL* cell);


int main(){
	int val;

	//先頭のセルの宣言
	CELL head;
	head.next = nullptr;

	printf("start\n");
	while (true){
		printf("入力した数字を最後尾に追加\n");
		scanf_s("%d", &val);
		printf("LIST\n");

		//最後尾にセルを追加
		create(&head, val);
		
		//リストの一覧表示
		index(&head);
		printf("\n");
	}

	return 0;
}


void create(CELL* cell, int val) {
	//新規セル
	CELL* newCell;
	
	//新規セルのメモリ確保
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->next = nullptr;

	//最後のセルのアドレスの一つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当
	while (cell->next != nullptr) {
		cell = cell->next;
	}

	//追加前の最後尾に新規セルのポインタを代入
	cell->next = newCell;
}


void index(CELL* cell) {
	while (cell->next != nullptr) {
		cell = cell->next;
		printf("%d\n", cell->val);
	}
}