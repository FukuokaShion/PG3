#include "stdio.h"
#include <stdlib.h>
#include "windows.h"

typedef void (*PFunc)();

//コールバック関数
void Correct() {
	printf("正解\n");

}

//コールバック関数
void Incorrect() {
	printf("はずれ\n");

}


void setTimeout(PFunc p, int second) {
	//待機
	Sleep(second * 1000);

	//呼び出し
	p();

}


int main()
{
	//入力
	int anser = 0;

	//関数ポインタ
	PFunc p;
	p = Correct;

	//さいころ
	int	dice = rand() % 6 + 1;
	int remainder = dice % 2;


	printf("偶数なら1、奇数なら-1を入力\n");
	scanf_s("%d", &anser);

	//選択が偶数なら
	if (anser == 1) {
		printf("偶数を選択\n");
		//賽の目が偶数なら
		if (remainder == 0) {
			p = Correct;
		}
		else {
			p = Incorrect;
		}
	}
	else if (anser == -1) {
		printf("奇数を選択\n");
		//賽の目が奇数なら
		if (remainder == 1) {
			p = Correct;
		}
		else {
			p = Incorrect;
		}
	}

	//コールバック
	setTimeout(p, 3);
	printf("賽の目は%d\n", dice);


	return 0;
}