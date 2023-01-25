/*
Program name: Machine
Author: Rares-Mihail Neagu
Date(s): current form 01/25/23
Version Control: Git
Program Description: The Machine abstract class provides a 
template for building any of the machines used in the
JunkuLator project
*/
#pragma once
class Machine {
public:
	virtual void on() = 0;//starts the machine
	virtual void help()=0;
	virtual void getInput() = 0;
};
