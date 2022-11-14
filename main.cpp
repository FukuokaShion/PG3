#include<stdio.h>

//��r���ď������ق���Ԃ�
template<typename Type>
Type Min(Type a, Type b) {
	if (a <= b) {
		return static_cast<Type>(a);
	}
	return static_cast<Type>(b);
}

//�ċA�I�ȋ����̌v�Z
int Wage(int wage, int time) {
	if (time <= 1) {
		return wage;
	}
	return (wage + Wage(wage * 2 - 50, time - 1));
}

int main() {
	int time = 8;

	//�ċA�I�ȋ���
	int reflexiveResult;
	reflexiveResult = Wage(100, time);

	//��ʓI�ȋ���
	int generalWage = 1072;
	int generalResult = generalWage * time;

	//�����ق��������o��
	printf("%d\n", Min(reflexiveResult, generalResult));


	return 0;
}