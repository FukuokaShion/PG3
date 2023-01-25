#pragma once
#include"IShape.h"

class Circle : public IShape{
public:
	Circle();
	~Circle();

	void Size() override;
	void Draw() override;

private:
	const float PI = 3.141592f;
	float rad;
	float size;
};