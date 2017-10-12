#pragma once

class Vector2
{
public:
	Vector2(float x = 0.0f, float y = 0.0f)
	{
		//If no value is given, X and Y default to 0
		internalArray[0] = x;
		internalArray[1] = y;
	}

	~Vector2()
	{
		delete[] internalArray;
	}

	float GetX() { return internalArray[0]; }
	float GetY() { return internalArray[1]; }

	void SetX(float x) { internalArray[0] = x; }
	void SetY(float y) { internalArray[1] = y; }

	void Add(float x, float y)
	{
		internalArray[0] += x;
		internalArray[1] += y;
	}

	static bool CheckEqual(Vector2& v1, Vector2& v2)
	{
		if (v1.GetX() == v2.GetX() && v1.GetY() == v2.GetY())
		{
			return true;
		}
		return false;
	}

private:
	float* internalArray = new float[2];
};
