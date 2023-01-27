/*
Program name: GradeCalculator
Author: Rares-Mihail Neagu
Date(s): current form 01/25/23
Version Control: Git
Program Description: The GradeCalculator class allows you 
to calculate the grades of a student either by prompting the
user to input the values or by reading from a file
*/
#pragma once
#include <string>
#include "Machine.h"
class GradeCalculator : public Machine
{
private:
	//member variables
	char grade{};
	std::string studentName{};
	int labsGrade{};
	int quizesGrade{};
	int projectGrade{};
	int midtermGrade{};
	int finalGrade{};
	int choice{};
public:
	//constructors and the destructor
	GradeCalculator() = default;
	GradeCalculator(std::string name,int labs, int quizes, int project, int midterm, int finals);
	~GradeCalculator();

	//setters and getters
	char getGrade() const;
	std::string getName() const;
	int getLabsGrade() const;
	int getQuizesGrade() const;
	int getProjectGrade() const;
	int getMidtermGrade() const;
	int getFinalGrade() const;
	void setLabsGrade(int myLabs);
	void setQuizesGrade(int myQuizes);
	void setProjectGrade(int myProject);
	void setMidtermGrade(int myMidterm);
	void setFinalGrade(int myFinal);

	//input 
	void inputChoice();
	void getInput();


	//utility
	void printMenu();
	bool isValidChoice(int choice);
	void calculateGrade();
	bool isFileExist(std::string fileName);
	
	//inherited from Machine
	void on();
	void help();
};