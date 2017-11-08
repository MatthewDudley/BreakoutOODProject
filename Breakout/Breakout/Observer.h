#pragma once
class Observer
{
public:
	virtual void Notify() = 0;
	virtual ~Observer() {}
};

