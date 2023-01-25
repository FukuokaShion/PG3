#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeout(std::function<void()> func, int second){
	printf("%d秒待機\n", second);
	Sleep(second * 1000);

	func();

}

int main(int argc, const char* argv[]){
	int select;
	printf("偶数だと思うなら0、奇数なら1を入力\n");
	scanf_s("%d", &select);

	int dice = rand() % 6 + 1;

	//関数の作成
	std::function<void()> judgeFunc = [&](){
		if (dice % 2 == select) {
			printf("%dで正解\n", dice);
		}else {
			printf("%dで不正解\n", dice);
		}
	};


	SetTimeout(judgeFunc, 3);


	system("pause");

	return 0;
}