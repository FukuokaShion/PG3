#include <stdio.h>
#include <stdlib.h>

//単方向リストの構造体
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
			printf("2.最後尾に要素の挿入\n");
			printf("3.最後尾の要素の削除\n");
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
			printf("[リスト要素の挿入]\n");
			printf("追加する要素の値を入力してください\n");
			scanf_s("%d", &val);
			Create(&head, val);
			printf("要素<%d>がリストの最後尾に挿入されました\n", val);
			printf("\n");
			printf("--------------------------\n");
			printf("0.初期画面に戻る\n");
			scanf_s("%d", &play);

			break;
		case 3:
			printf("[要素の削除]\n");
			printf("最後尾の要素を削除しました\n");
			Deleta(&head);
			printf("\n\n");
			printf("--------------------------\n");
			printf("0.初期画面に戻る\n");
			scanf_s("%d", &play);

			break;
		}

		//最後尾にセルを追加
		
		//リストの一覧表示
		printf("\n");
	}

	return 0;
}


void Create(CELL* cell, int val) {
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