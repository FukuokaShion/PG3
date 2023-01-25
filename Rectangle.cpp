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
	printf("‹éŒ`‚Ì–ÊÏ‚ğŒvZ\n");
}

void Rectangle::Draw() {
	printf("‹éŒ`‚Ì–ÊÏ:%f\n", size);
}