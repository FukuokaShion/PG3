#include"Circle.h"
#include <stdio.h>
#include<math.h>

Circle::Circle() {
	rad = 3;
}

Circle::~Circle() {
}

void Circle::Size() {
	size = pow(rad, 2) * PI;
	printf("�~�̖ʐς��v�Z\n");
}

void Circle::Draw() {
	printf("�~�̖ʐ�:%f\n", size);
}