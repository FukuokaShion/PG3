#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

typedef void (*PFunc)(int);

void callback(int num) {
	//乱数処理
	srand(time(nullptr));
	int	dice = rand() % 6 + 1;

	//判定
	if (dice % 2 == num){
		printf("%dで正解\n", dice);
	}else{
		printf("%dで不正解\n", dice);
	}
}

void	setTimeout(PFunc p, int answer, int second) {
	printf("結果は\n");
	Sleep(second * 1000);

	p(answer);
}

int main(){
	int answer;

	while (true)
	{
		printf("偶数だと思うなら0、奇数なら1を入力\n");

		scanf_s("%d", &answer);
		if (answer == 0 || answer == 1){
			break;

		}else{
			printf("0または1を入力\n");

		}
	}

	PFunc p = callback;

	setTimeout(p, answer, 3);

	system("pause");

	return 0;

}