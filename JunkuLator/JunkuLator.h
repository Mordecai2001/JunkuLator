/*
Program name: JunkuLator
Author: Rares-Mihail Neagu
Date(s): current form 01/25/23
Version Control: Git
Program Description: The JunkuLator is a general-purpose
calculator that has a MathCalculator for arithmetic operations,
the StringTokenizer for analyzing strings, the MetricConvertor
for converting values between unit systems, and the GradeCalulator
for calculating the grade of students
*/
#pragma once
#include <iostream>
#include <string>
#include "MathCalculator.h"
#include "StringTokenizer.h"
#include "MetricConvertor.h"
#include "GradeCalculator.h"
#include "Machine.h"

class JunkuLator : public Machine
{
private:
	//member variables
	std::string choice{};
	std::map<std::string, int> myMap{}; // used to store the choices as int
	std::string username{};
	MathCalculator mathCalculator{};
	MetricConvertor metricConvertor{};
	StringTokenizer stringTokenizer{};
	GradeCalculator gradeCalculator{};
public:
	//constructors and destructors
	JunkuLator();
	~JunkuLator();

	//setters and getters
	void setMap();

	//utility functions
	void getUsername();
	void printWelcomeMessage();
	void printMenu();
	bool isValidChoice(std::string myChoice);
	void getInput();
	void run();

	//inherited from Machine
	void on();
	void help();
};