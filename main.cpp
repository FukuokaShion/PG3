#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeout(std::function<void()> func, int second){
	printf("%d�b�ҋ@\n", second);
	Sleep(second * 1000);

	func();

}

int main(int argc, const char* argv[]){
	int select;
	printf("�������Ǝv���Ȃ�0�A��Ȃ�1�����\n");
	scanf_s("%d", &select);

	int dice = rand() % 6 + 1;

	//�֐��̍쐬
	std::function<void()> judgeFunc = [&](){
		if (dice % 2 == select) {
			printf("%d�Ő���\n", dice);
		}else {
			printf("%d�ŕs����\n", dice);
		}
	};


	SetTimeout(judgeFunc, 3);


	system("pause");

	return 0;
}