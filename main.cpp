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
	//先頭のセルの宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;



	while (true){
		switch (scene)
		{
		case 0:
			system("cls");
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			if (0 < Size(&head)) {
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
			}
			printf("\n");
			printf("------------------------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &scene);

			break;
		case 1:
			system("cls");
			printf("[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n");
			printf("9.要素操作に戻る\n");
			printf("\n");
			printf("------------------------------------\n");
			printf("操作を選択してください\n");
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
				printf("[要素の一覧表示]\n");
				Index(&head);
				printf("\n");
				printf("------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
				scanf_s("%d", &select);
				if (select == 1) {
					scene = 1;
				}else if (select == 2) {
					scene = 0;
				}

				break;
			case 2:
				system("cls");
				printf("[順番を指定して要素を表示]\n");
				printf("表示したい要素の順番を指定してください");
				printf("-1を入力で表示");
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
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
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
			printf("[リスト要素の挿入]\n");
			printf("要素を追加する番号を入力してください\n");
			scanf_s("%d", &select);
			selectCell = getInsertCellAddress(&head, select);

			printf("追加する要素の値を入力してください\n");
			scanf_s("%256s", val, 257);
			Create(selectCell, val);

			printf("要素%sが%d番目に挿入されました\n", val, select);

			printf("\n");
			printf("------------------------------------\n");
			printf("1.要素の操作に戻る\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}

			break;
		case 3:
			system("cls");
			printf("[要素の編集]\n");
			printf("編集したい要素の番号を指定してください\n");
			scanf_s("%d", &select);

			if (select >= Size(&head)) {
				selectCell = getSelectCellAddress(&head, select);

				printf("%d番目の要素の変更する値を入力してください\n", select);
				scanf_s("%256s", val, 257);
				Edit(selectCell, val);

				printf("%d番目の要素の値が%sに変更されました\n", select, val);
				printf("\n");
			}else {
				printf("%d番目の要素が見つかりませんでした\n", select);
			}
			printf("------------------------------------\n");
			printf("1.要素の操作に戻る\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}

			break;
		case 4:
			system("cls");
			printf("[要素の削除]\n");
			printf("削除したい要素の番号を指定してください\n");
			scanf_s("%d", &select);
			if (select >= Size(&head)) {
				selectCell = getSelectCellAddress(&head, select);
				Deleta(selectCell);
				printf("%d番目の要素を削除しました\n", select);
			}else {
				printf("%d番目の要素が見つかりませんでした\n", select);
			}

			printf("\n");
			printf("------------------------------------\n");
			printf("1.要素の操作に戻る\n");
			scanf_s("%d", &select);
			if (select == 1) {
				scene = 0;
			}



			break;
		}

		//最後尾にセルを追加
		
		//リストの一覧表示
		printf("\n");
	}

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
	printf("要素一覧:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : %s\n", no, endCell->val);
		no++;
	}
	printf("}\n");
	printf("\n");
	printf("要素数:%d\n", no);
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