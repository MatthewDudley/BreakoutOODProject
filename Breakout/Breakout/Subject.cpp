#include "Subject.h"
#include "Observer.h"

void Subject::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}
void Subject::NotifyAll()
{
	for (int i = 0; i < observers.size(); ++i)
	{
		observers.at(i)->Notify();
	}
}