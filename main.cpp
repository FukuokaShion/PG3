#include "stdio.h"
#include <stdlib.h>
#include "windows.h"

typedef void (*PFunc)();

//�R�[���o�b�N�֐�
void Correct() {
	printf("����\n");

}

//�R�[���o�b�N�֐�
void Incorrect() {
	printf("�͂���\n");

}


void setTimeout(int anser,int remainder,PFunc p, int second) {
	//�ҋ@
	Sleep(second * 1000);

	if (anser != remainder) {
		p = Incorrect;
	}

	//�Ăяo��
	p();

}


int main()
{
	//����
	int anser = 0;

	//�֐��|�C���^
	PFunc p;
	p = Correct;

	//��������
	int	dice = rand() % 6 + 1;
	int remainder = dice % 2;

	printf("�����Ȃ�0�A��Ȃ�1�����\n");
	scanf_s("%d", &anser);

	//�R�[���o�b�N
	setTimeout(anser, remainder, p, 3);

	printf("�΂̖ڂ�%d\n", dice);

	system("pause");

	return 0;
}