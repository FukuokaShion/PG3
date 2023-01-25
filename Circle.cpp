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
	printf("‰~‚Ì–ÊÏ‚ğŒvZ\n");
}

void Circle::Draw() {
	printf("‰~‚Ì–ÊÏ:%f\n", size);
}