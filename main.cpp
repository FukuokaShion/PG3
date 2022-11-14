#include<stdio.h>


template<typename Type>
Type Min(Type a, Type b) {
	if (a <= b) {
		return static_cast<Type>(a);
	}
	return static_cast<Type>(b);
}

//char型のみ受け付けない(オーバーライド)
template<>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません\n");
	return 0;
}

int main() {
	int a = 114;
	int b = 514;
	printf("%d\n",Min(a, b));

	float c = 3.63f;
	float d = 3.64f;
	printf("%f\n", Min(c, d));

	double e = 11.0005;
	double f = 12.3141;
	printf("%lf\n", Min(e, f));
	
	char g = 1;
	char h = 4;
	Min(g, h);

	return 0;
}