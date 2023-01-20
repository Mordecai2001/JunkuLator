#pragma once
class Machine {
protected:
	int id{};
public:
	virtual void on() = 0;//starts the machine
	virtual void off();//implements the quit
	virtual void help()=0;
};
