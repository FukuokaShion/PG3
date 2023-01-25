#include"IShape.h"
#include"Circle.h"
#include"Rectangle.h"

#include<stdlib.h>

int main() {
	IShape* iShape[2];

	iShape[0] = new Circle;
	iShape[1] = new Rectangle;

	while (true)
	{
		for (int i = 0; i < 2; i++) {
			iShape[i]->Size();
			iShape[i]->Draw();
		}

		system("pause");
	}

	return 0;
}