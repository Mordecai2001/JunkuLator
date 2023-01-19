#pragma once
#include <string>
class GradeCalculator
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


	//utility
	void printMenu();
	void getInput();
	bool isValidChoice(int choice);
	void calculateGrade();
	void on();
	

};
