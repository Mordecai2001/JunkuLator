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
	std::cout << "GradeCalculator Destructor Call\n";
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
	
}
