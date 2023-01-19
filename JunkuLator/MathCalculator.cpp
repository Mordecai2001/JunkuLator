#include <iostream>
#include <string>
#include <cmath>
#include "MathCalculator.h"

void MathCalculator::setMap()
{
    myMap["+"] = 1;
    myMap["-"] = 2;
    myMap["*"] = 3;
    myMap["/"] = 4;
    myMap["%"] = 5;
    myMap["Log2(n)"] = 6;
    myMap["log2(n)"] = 6;
    myMap["LOG2(N)"] = 6;
    myMap["LOG2(n)"] = 6;
    myMap["log2(N)"] = 6;
    myMap["Help"] = 7;
    myMap["help"] = 7;
    myMap["HELP"] = 7;
}
MathCalculator::MathCalculator()
{
    setMap();
}
MathCalculator::MathCalculator(std::string &myOperation, int theFirstOperand, int theSecondOperand)
{
    operation = myOperation;
    firstOperand = theFirstOperand;
    secondOperand = theSecondOperand;
    setMap();
}
MathCalculator::~MathCalculator() {
    std::cout << "MathCalculator Destructor Call\n";
}
std::string MathCalculator::getOperation() const
{
    return operation;
}
int MathCalculator::getFirstOperand() const
{
    return firstOperand;
}
int MathCalculator::getSecondOperand() const
{
    return secondOperand;
}
void MathCalculator::setOperation(std::string myOperation)
{
    operation = myOperation;
}
void MathCalculator::setFirstOperand(int myFirstOperand)
{
    firstOperand = myFirstOperand;
}
void MathCalculator::setSecondOperand(int mySecondOperand)
{
    secondOperand = mySecondOperand;
}
void MathCalculator::inputOperation()
{
    std::cout << "Please enter the operation(+,-,*,/,%,Log2(n),Help): ";
    std::cin >> operation;
}
void MathCalculator::inputFirstOperand()
{
    std::cout << "Enter the first operand: ";
    std::cin >> firstOperand;
}
void MathCalculator::inputSecondOperand()
{
    std::cout << "Enter the second operand: ";
    std::cin >> secondOperand;
}
void MathCalculator ::inputN()
{
    std::cout << "Enter n: ";
    std::cin >> n;
}
void MathCalculator::calculate()
{
    switch (myMap[operation])
    {
    case 1: // addition
    {
        inputFirstOperand();
        inputSecondOperand();
        std::cout << firstOperand << " + " << secondOperand << " = " << firstOperand + secondOperand << std::endl;
    }
    break;
    case 2: // subtraction
    {
        inputFirstOperand();
        inputSecondOperand();
        std::cout << firstOperand << " - " << secondOperand << " = " << firstOperand - secondOperand << std::endl;
    }
    break;
    case 3: // multiplication
    {
        inputFirstOperand();
        inputSecondOperand();
        std::cout << firstOperand << " * " << secondOperand << " = " << firstOperand * secondOperand << std::endl;
    }
    break;
    case 4: // div
    {
        inputFirstOperand();
        inputSecondOperand();
        std::cout << firstOperand << " / " << secondOperand << " = " << firstOperand / secondOperand << std::endl;
    }
    break;
    case 5: // mod
    {
        inputFirstOperand();
        inputSecondOperand();
        std::cout << firstOperand << " % " << secondOperand << " = " << firstOperand % secondOperand << std::endl;
    }
    break;
    case 6: // log2(n)
    {
        inputN();
        std::cout << "log2(" << n << ")"
             << " = " << log2(n) << std::endl;
    }
    break;
    case 7: // help
    {
        // to implement help
    }
    break;
    default:
    {
        std::cout << "ERROR! Can't match any operation!" << std::endl;
    }
    }
}
bool MathCalculator::isValidOperation()
{
    if (operation == "+" || operation == "-" || operation == "*" || operation == "/" ||
        operation == "%" || operation == "Log2(n)" || operation == "log2(n)" ||
        operation == "LOG2(N)" || operation == "LOG2(n)" || operation == "log2(N)" ||
        operation == "Help" || operation == "help" || operation == "HELP")
    {
        return true;
    }
    else
        return false;
}
void MathCalculator::on()
{
    inputOperation();
    if (isValidOperation())
    {
        calculate();
    }
    else
        std::cout << "ERROR! Can't match any operation!" << std::endl;
}
