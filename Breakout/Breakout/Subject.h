#pragma once
#include <vector>
class Observer;
class Subject
{
public:
	void AddObserver(Observer* observer);
protected:
	void NotifyAll();
private:
	std::vector<Observer*> observers;
};