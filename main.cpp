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

	printf("偶数なら0、奇数なら1を入力\n");
	scanf_s("%d", &anser);


	if (anser == remainder) {
		p = Correct;
	}
	else {
		p = Incorrect;
	}

	//コールバック
	setTimeout(p, 3);

	printf("賽の目は%d\n", dice);

	system("pause");

	return 0;
}