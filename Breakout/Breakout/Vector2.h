#pragma once

class Vector2
{
public:
	Vector2(float x = 0.0f, float y = 0.0f);
	~Vector2();
	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
	void Add(float x, float y);
	static bool CheckEqual(Vector2& v1, Vector2& v2);
private:
	float* internalArray = new float[2];
};
