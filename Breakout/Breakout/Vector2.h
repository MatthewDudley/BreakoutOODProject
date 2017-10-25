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

	void MultiplyByScalar(float scalar)
	{
		internalArray[0] *= scalar;
		internalArray[1] *= scalar;
	}

	static float Dot(Vector2& v1, Vector2& v2)
	{
		return (v1.GetX() * v2.GetX()) + (v1.GetY() * v2.GetY());
	}

	static Vector2 GetReflectionAngle(Vector2* direction, Vector2* normal)
	{
		//d-2(dot(d, n))n
		float dotProduct = Vector2::Dot(*direction, *normal);
		normal->MultiplyByScalar(2 * dotProduct);
		return Vector2(direction->GetX() - normal->GetX(), direction->GetY() - normal->GetY());
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
