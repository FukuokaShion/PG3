#include"Rectangle.h"
#include <stdio.h>
#include<math.h>

Rectangle::Rectangle() {
	width = 3;
	height = 5;
}

Rectangle::~Rectangle() {
}

void Rectangle::Size() {
	size = width * height;
	printf("��`�̖ʐς��v�Z\n");
}

void Rectangle::Draw() {
	printf("��`�̖ʐ�:%f\n", size);
}