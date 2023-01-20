#pragma once
class Machine {
protected:
	int id{};
public:
	virtual void on() = 0;//starts the machine
	virtual void off()=0;//implements the quit
	virtual void help()=0;
	virtual void getInput() = 0;
};
