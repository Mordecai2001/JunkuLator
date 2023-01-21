#include <iostream>
#include "JunkuLator.h"

void JunkuLator::setMap() {
	myMap["1"] = 1;
	myMap["2"] = 2;
	myMap["3"] = 3;
	myMap["4"] = 4;
	myMap["5"] = 5;
	myMap["6"] = 6;
	myMap["h"] = 5;
	myMap["H"] = 5;
	myMap["help"] = 5;
	myMap["HELP"] = 5;
	myMap["Help"] = 5;
	myMap["q"] = 6;
	myMap["Q"] = 6;
	myMap["QUIT"] = 6;
	myMap["quit"] = 6;
	myMap["Quit"] = 6;
}
JunkuLator::JunkuLator() {
	setMap();
}
JunkuLator::~JunkuLator() {
	std::cout << "JunkuLator Destructor Call\n";
}
void JunkuLator::getUsername() {
	try {
		std::cout << "Please enter your full name: ";
		getline(std::cin, username);
	}
	catch (std::ios_base::failure& e) {
		std::cerr << "Invalid input. Please enter a string." << std::endl;
		getUsername();
	}
}
void JunkuLator::printWelcomeMessage() {
	int space = username.find(" ");
	std::string firstName = username.substr(0, space);
	std::cout << "Thank you " << firstName << ", Welcome to our JunkuLator Adventures!!!" << std::endl;
}
void JunkuLator::printMenu() {
	std::cout << "-----------------------JunkuLator------------------------" << std::endl;
	std::cout << "Please select from the following menu:" << std::endl;
	std::cout << "1. Math Calculator" << std::endl;
	std::cout << "2. Metric Conversion Calculator" << std::endl;
	std::cout << "3. Grades Calculator" << std::endl;
	std::cout << "4. String Tokenizer" << std::endl;
	std::cout << "5. Help" << std::endl;
	std::cout << "6. Quit" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}
bool JunkuLator::isValidChoice(std::string myChoice) {
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4" 
		|| choice == "5" || choice == "6" || choice == "Q" || choice == "q"
		|| choice == "quit" || choice == "QUIT" || choice == "Quit" || choice == "H"
		|| choice == "h" || choice == "help" || choice == "HELP" || choice == "Help")
		return true;
	else return false;
}
void JunkuLator::getInput() {
	
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	while (!isValidChoice(choice))
	{
			std::cout << "ERROR! Your choice is invalid!" << std::endl;
			getInput();
	}
}
void JunkuLator::run() {
	printMenu();
	getInput();
	switch (myMap[choice]) {
	case 1:
	{
		mathCalculator.on();
		run();
	}
	break;
	case 2:
	{
		metricConvertor.on();
		run();
	}
	break;
	case 3:
	{
		gradeCalculator.on();
		run();
	}
	break;
	case 4:
	{
		stringTokenizer.on();
		run();
	}
	break;
	case 5:
	{
		help();
		run();
	}
	break;
	case 6:
	{
		std::cout << "You successfully terminated the program." << std::endl;
		std::cout << "Thank you for using the JunkuLator!" << std::endl;
	}
	break;
	}

}
void JunkuLator::on() {
	getUsername();
	printWelcomeMessage();
	run();
}
void JunkuLator::help() {
	std::cout << "-------------------------HELP---------------------------" << std::endl;
	std::cout << "The JunkuLator is general-purpose calculator that solves" << std::endl;
	std::cout << "different types of problems. You can perform arithmetic operations" << std::endl;
	std::cout << "using the Math Calculator or convert units with the Metric Converter." << std::endl;
	std::cout << "On top of that you can calculate your grade using the Grades Calculator" << std::endl;
	std::cout << "or analyze a string of your own choice with the String Tokenizer." << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
}