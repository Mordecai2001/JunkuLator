/*
Program name: GradeCalculator Implementation
Author: Rares-Mihail Neagu
Date(s): current form 01/27/23
Version Control: Git
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
	std::cout << "3. Get help" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
}
void GradeCalculator::getInput() {
	std::cout << "Enter your name: ";
	std::cin >> studentName;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter a string!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your name: ";
		std::cin >> studentName;
	}
	
	std::cout << "Enter your labs' grade: ";
	std::cin >> labsGrade;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter an integer!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your labs' grade: ";
		std::cin >> labsGrade;
	}
	
	std::cout << "Enter your quizes' grade: ";
	std::cin >> quizesGrade;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter an integer!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your quizes' grade: ";
		std::cin >> quizesGrade;
	}
	
	std::cout << "Enter your project grade: ";
	std::cin >> projectGrade;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter an integer!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your project grade: ";
		std::cin >> projectGrade;
	}
	
	std::cout << "Enter your midterm grade: ";
	std::cin >> midtermGrade;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter an integer!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your midterm grade: ";
		std::cin >> midtermGrade;
	}
	
	std::cout << "Enter your final grade: ";
	std::cin >> finalGrade;
	//ERROR HANDLING
	while (std::cin.fail())
	{
		std::cout << "Please enter an integer!" << std::endl;
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your final grade: ";
		std::cin >> finalGrade;
	}
}
bool GradeCalculator::isValidChoice(int choice) {
	if (choice == 1 || choice == 2 || choice == 3) return true;
	else return false;
}
void GradeCalculator::calculateGrade() {
	double total = 20.0 + labsGrade / static_cast<double>(10) 
		+ quizesGrade/ static_cast<double>(20) 
		+ projectGrade/ static_cast<double>(6.66) 
		+ midtermGrade / static_cast<double>(5)
		+ finalGrade / static_cast<double>(4);
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
bool GradeCalculator::isFileExist(std::string fileName) {
	std::ifstream file(fileName);
	return file.good();
}
void GradeCalculator::on() {
	printMenu();
	inputChoice();
	if (choice == 1) {
		getInput();
		calculateGrade();
		std::cout << studentName << "'s grade is: " << grade << std::endl;
	}
	else if(choice == 2) {
		//implement reading from a file
		std::string fileName{};
		std::cout << "Enter the name of the file: ";
		std::cin >> fileName;
		while (!isFileExist(fileName)) {
			std::cout << "ERROR! No file named "<<fileName;
			std::cout << "-----------------------------------";
			std::cout << "Enter the name of the file: ";
			std::cin >> fileName;
		}
		std::ifstream file(fileName);
		if (file.is_open()) {
			std::string line{};
			while (getline(file, line)) {
				std::stringstream ss(line);
				std::string temp{};
				getline(ss, studentName, ',');
				getline(ss, temp, ',');
				labsGrade = stoi(temp);
				getline(ss, temp, ',');
				quizesGrade = stoi(temp);
				getline(ss, temp, ',');
				projectGrade = stoi(temp);
				getline(ss, temp, ',');
				midtermGrade = stoi(temp);
				getline(ss, temp, ',');
				finalGrade = stoi(temp);
				calculateGrade();
				std::cout << studentName << "'s grade is: " << grade << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "Failed to open the file!" << std::endl;
		}
	}
	else {
		help();
		on();
	}
}
void GradeCalculator::help() {
	std::cout << "-------------------------HELP---------------------------" << std::endl;
	std::cout << "The Grade Calculator allows you to calculate the grades of" << std::endl;
	std::cout << "a student by either typing the grades yourself or by reading" << std::endl;
	std::cout << "from a file. " << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
}
