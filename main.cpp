#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

typedef void (*PFunc)(int);

void callback(int num) {
	//��������
	srand(time(nullptr));
	int	dice = rand() % 6 + 1;

	//����
	if (dice % 2 == num){
		printf("%d�Ő���\n", dice);
	}else{
		printf("%d�ŕs����\n", dice);
	}
}

void	setTimeout(PFunc p, int answer, int second) {
	printf("���ʂ�\n");
	Sleep(second * 1000);

	p(answer);
}

int main(){
	int answer;

	while (true)
	{
		printf("�������Ǝv���Ȃ�0�A��Ȃ�1�����\n");

		scanf_s("%d", &answer);
		if (answer == 0 || answer == 1){
			break;

		}else{
			printf("0�܂���1�����\n");

		}
	}

	PFunc p = callback;

	setTimeout(p, answer, 3);

	system("pause");

	return 0;

}