#pragma once
#include"IShape.h"

class Rectangle : public IShape {
public:
	Rectangle();
	~Rectangle();

	void Size() override;
	void Draw() override;

private:
	float width;
	float height;
	float size;
};