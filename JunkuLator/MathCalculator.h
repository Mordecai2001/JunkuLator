#pragma once
#include <string>
#include <map>
#include "Machine.h"

class MathCalculator : public Machine
{
private:
    // member variables
    std::string operation{};
    int firstOperand{};
    int secondOperand{};
    int n{};                            // used for the log2(n)
    std::map<std::string, int> myMap{}; // used to store the choices as int

public:
    // constructors and the destructor
    MathCalculator();
    MathCalculator(std::string &myOperation, int theFirstOperand, int theSecondOperand);
    ~MathCalculator();

    // setters and getters
    std::string getOperation() const;
    int getFirstOperand() const;
    int getSecondOperand() const;
    void setOperation(std::string myOperation);
    void setFirstOperand(int myFirstOperand);
    void setSecondOperand(int mySecondOperand);
    void setMap();

    // input
    void inputOperation();
    void inputFirstOperand();
    void inputSecondOperand();
    void inputN();
    void getInput();

    // utility
    void calculate();
    bool isValidOperation();

    //inherited from Machine
    void on();
    void help();
};

