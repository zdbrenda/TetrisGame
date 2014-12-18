#pragma once
#include "Observer.h"

class Observable
{
public:
	Observable();
	~Observable();
	virtual void attach(Observer* obs);
	virtual void notify(Observer* obs);

private:
	Observable* obs;
};