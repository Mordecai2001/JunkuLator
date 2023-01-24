#pragma once
class Machine {
public:
	virtual void on() = 0;//starts the machine
	virtual void help()=0;
	virtual void getInput() = 0;
};
