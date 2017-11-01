#pragma once
#include "math.h"

class Vector2
{
public:
	//Constructor
	Vector2(float x = 0.0f, float y = 0.0f)
	{
		//If no value is given, X and Y default to 0
		internalArray[0] = x;
		internalArray[1] = y;
	}

	//Copy Constructor
	Vector2(const Vector2& source)
	{
		this->SetX(source.GetX());
		this->SetY(source.GetY());
	}

	//Destructor
	~Vector2()
	{
		delete[] internalArray;
	}

	//Begin Operator Overloading-------------------

	//'=' Assignment Overload
	Vector2& operator=(const Vector2& source)
	{
		if (this == &source)
		{
			return *this;
		}
		this->SetX(source.GetX());
		this->SetY(source.GetY());
		return *this;
	}

	//'==' Equals overload
	bool operator==(const Vector2& source) const
	{
		return Vector2::CheckEqual(*this, source);
	}

	//'*' Multiplication Overload
	Vector2 operator*(float scalar) const
	{
		//If the argument is a scalar, perform multiplication by scalar operation
		return Vector2::MultiplyByScalar(*this, scalar);
	}
	Vector2 operator*(const Vector2& vec) const
	{
		//if the argument is another vector, do component-wise multiplication
		return Vector2::ComponentWiseMultiplication(*this, vec);
	}

	//'+' Addition Overload
	Vector2 operator+(float scalar) const
	{
		//If the argument is a scalar, perform component-wise addition by scalar operation
		return Vector2::AddScalar(*this, scalar);
	}
	Vector2 operator+(const Vector2& vec) const
	{
		//if the argument is another vector, do component-wise addition
		return Vector2::ComponentWiseAddition(*this, vec);
	}

	//'-' Subtraction Overload
	Vector2 operator-(float scalar) const
	{
		//If the argument is a scalar, perform component-wise subtraction by scalar operation
		return Vector2::AddScalar(*this, -scalar);
	}
	Vector2 operator-(const Vector2& vec) const
	{
		//if the argument is another vector, do component-wise subtraction
		return Vector2::ComponentWiseAddition(*this, -vec);
	}

	//'-' unary minus operator
	Vector2 operator-() const
	{
		return Vector2::MultiplyByScalar(*this, -1);
	}

	//'*=' Multiplication-Assignment Overload
	Vector2& operator*=(float scalar)
	{
		//If the argument is a scalar, perform scalar multiplication
		*this = *this * scalar;
		return *this;
	}
	Vector2& operator*=(const Vector2& vec)
	{
		//If the argument is a vector, perform component-wise multiplication
		*this = *this * vec;
		return *this;
	}

	//'+=' Addition-Assignment Overload
	Vector2& operator+=(float scalar)
	{
		//If the argument is a scalar, perform component-wise scalar addition
		*this = *this + scalar;
		return *this;
	}
	Vector2& operator+=(const Vector2& vec)
	{
		//If the argument is a vector, perform component-wise addition
		*this = *this + vec;
		return *this;
	}

	//'-=' Subtraction-Assignment Overload
	Vector2& operator-=(float scalar)
	{
		//If the argument is a scalar, perform component-wise scalar subtraction
		*this = *this - scalar;
		return *this;
	}
	Vector2& operator-=(const Vector2& vec)
	{
		//If the argument is a vector, perform component-wise subtraction
		*this = *this - vec;
		return *this;
	}

	//End Operator Overloading-------------------

	float GetX() const { return internalArray[0]; }
	float GetY() const { return internalArray[1]; }

	void SetX(float x) { internalArray[0] = x; }
	void SetY(float y) { internalArray[1] = y; }

	static float Dot(const Vector2& v1, const Vector2& v2)
	{
		return (v1.GetX() * v2.GetX()) + (v1.GetY() * v2.GetY());
	}

	static Vector2 GetReflectionAngle(const Vector2& direction, const Vector2& normal)
	{
		//d-2(dot(d, n))n
		float dotProduct = Vector2::Dot(direction, normal);
		Vector2 scaledNormal = normal * (2 * dotProduct);
		return direction - scaledNormal;
	}

	static Vector2 ComponentWiseMultiplication(const Vector2& vec1, const Vector2& vec2)
	{
		return Vector2(vec1.GetX() * vec2.GetX(), vec1.GetY() * vec2.GetY());
	}
	static Vector2 MultiplyByScalar(const Vector2& vec, float scalar)
	{
		return Vector2(vec.GetX() * scalar, vec.GetY() * scalar);
	}
	static Vector2 ComponentWiseAddition(const Vector2& vec1, const Vector2& vec2)
	{
		return Vector2(vec1.GetX() + vec2.GetX(), vec1.GetY() + vec2.GetY());
	}
	static Vector2 AddScalar(const Vector2& vec, float scalar)
	{
		return Vector2(vec.GetX() + scalar, vec.GetY() + scalar);
	}

	static bool CheckEqual(const Vector2& v1, const Vector2& v2)
	{
		if (v1.GetX() == v2.GetX() && v1.GetY() == v2.GetY())
		{
			return true;
		}
		return false;
	}

	float GetMagnitude() const
	{
		return sqrt((GetX() * GetX()) + (GetY() * GetY()));
	}

	Vector2 Normalized() const
	{
		float mag = this->GetMagnitude();
		return Vector2(GetX() / mag, GetY() / mag);
	}

private:
	float* internalArray = new float[2];
};
