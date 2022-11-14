#include<stdio.h>

//比較して小さいほうを返す
template<typename Type>
Type Min(Type a, Type b) {
	if (a <= b) {
		return static_cast<Type>(a);
	}
	return static_cast<Type>(b);
}

//再帰的な給料の計算
int Wage(int wage, int time) {
	if (time <= 1) {
		return wage;
	}
	return (wage + Wage(wage * 2 - 50, time - 1));
}

int main() {
	int time = 8;

	//再帰的な給料
	int reflexiveResult;
	reflexiveResult = Wage(100, time);

	//一般的な給料
	int generalWage = 1072;
	int generalResult = generalWage * time;

	//安いほうを書き出す
	printf("%d\n", Min(reflexiveResult, generalResult));


	return 0;
}