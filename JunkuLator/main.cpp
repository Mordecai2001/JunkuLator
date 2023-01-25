/*
Program name: main
Author: Rares-Mihail Neagu
Date(s): current form 01/25/23
Version Control: Git
Program Description: the main program that acts as the 
driver code for the JunkuLator
*/
#include <iostream>
#include "JunkuLator.h"
using namespace std;

int main()
{
	JunkuLator jk{};
	jk.on();
	cin.get();
	return 0;
}