#include <iostream>
#include "GradeCalculator.h"

GradeCalculator::GradeCalculator(std::string name, int labs, int quizes, int project, int midterm, int finals) 
	:studentName{name} {
	if (labs >= 0) {
		labsGrade = labs;
	}
	if (quizes >= 0) {
		quizesGrade = quizes;
	}
	if (project >= 0) {
		projectGrade = project;
	}
	if (midterm >= 0) {
		midtermGrade = midterm;
	}
	if (finals >= 0) {
		finalGrade = finals;
	}

}
GradeCalculator::~GradeCalculator() {
	std::cout << "Grade Calculator Destructor Call\n";
}
char GradeCalculator::getGrade() const {
	return grade;
}
std::string GradeCalculator::getName() const {
	return studentName;
}
int GradeCalculator::getLabsGrade() const {
	return labsGrade;
}
int GradeCalculator::getQuizesGrade() const {
	return quizesGrade;
}
int GradeCalculator::getProjectGrade() const {
	return projectGrade;
}
int GradeCalculator::getMidtermGrade() const {
	return midtermGrade;
}
int GradeCalculator::getFinalGrade() const {
	return finalGrade;
}
void GradeCalculator::setLabsGrade(int myLabs) {
	labsGrade = myLabs;
}
void GradeCalculator::setQuizesGrade(int myQuizes) {
	quizesGrade = myQuizes;
}
void GradeCalculator::setProjectGrade(int myProject) {
	projectGrade = myProject;
}
void GradeCalculator::setMidtermGrade(int myMidterm) {
	midtermGrade = myMidterm;
}
void GradeCalculator::setFinalGrade(int myFinal) {
	finalGrade = myFinal;
}
void GradeCalculator::inputChoice() {
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	while (!isValidChoice(choice))
	{
		std::cout << "ERROR! Your choice is invalid!" << std::endl;
		inputChoice();
	}
}
void GradeCalculator::printMenu() {
	std::cout << "-------------------Grade Calculator---------------------" << std::endl;
	std::cout << "Do you want to enter the grades or to read from a file?" << std::endl;
	std::cout << "1. Enter the grades manually" << std::endl;
	std::cout << "2. Read from a file" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
}
void GradeCalculator::getInput() {
	std::cout << "Enter your name: ";
	std::cin >> studentName;
	std::cout << "Enter your labs' grade: ";
	std::cin >> labsGrade;
	std::cout << "Enter your quizes' grade: ";
	std::cin >> quizesGrade;
	std::cout << "Enter your project grade: ";
	std::cin >> projectGrade;
	std::cout << "Enter your midterm grade: ";
	std::cin >> midtermGrade;
	std::cout << "Enter your final grade: ";
	std::cin >> finalGrade;
}
bool GradeCalculator::isValidChoice(int choice) {
	if (choice == 1 || choice == 2) return true;
	else return false;
}
void GradeCalculator::calculateGrade() {
	int total = 20 + 1 / 4 * finalGrade + 1 / 5 * midtermGrade + 1 / 20 * quizesGrade + 15 / 100 * projectGrade + 1 / 10 * labsGrade;
	if (total >= 90) {
		grade = 'A';
	}
	else if (total >= 80) {
		grade = 'B';
	}
	else if (total >= 67) {
		grade = 'C';
	}
	else if (total >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F';
	} 
}
void GradeCalculator::on() {
	printMenu();
	inputChoice();
	if (choice == 1) {
		getInput();
		calculateGrade();
		std::cout << studentName << "'s grade is: " << grade << std::endl;
	}
	else {
			//implement reading from a file
	}
}

