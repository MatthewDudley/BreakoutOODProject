#include "Vector2.h"


Vector2::Vector2(float x, float y)
{
	//If no value is given, X and Y default to 0
	internalArray[0] = x;
	internalArray[1] = y;
}

Vector2::~Vector2()
{
	delete [] internalArray;
}

float Vector2::GetX()
{
	return internalArray[0];
}

float Vector2::GetY()
{
	return internalArray[1];
}

void Vector2::SetX(float x)
{
	internalArray[0] = x;
}

void Vector2::SetY(float y)
{
	internalArray[1] = y;
}

void Vector2::Add(float x, float y)
{
	internalArray[0] += x;
	internalArray[1] += y;
}

bool Vector2::CheckEqual(Vector2& v1, Vector2& v2)
{
	if (v1.GetX() == v2.GetX() && v1.GetY() == v2.GetY())
	{
		return true;
	}
	return false;
}

