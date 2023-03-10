/*
Program name: MetricConvertor Implementation
Author: Rares-Mihail Neagu
Date(s): current form 01/27/23
Version Control: Git
*/
#include <iostream>
#include "MetricConvertor.h"
#include "constants.h"

MetricConvertor::MetricConvertor() {
    setMap();
}
MetricConvertor::MetricConvertor(double theValue)
{
    setMap();
    if (theValue >= 0) {
        value = theValue;
    }
}
MetricConvertor::~MetricConvertor() {
    std::cout << "Metric Converter Destructor Call\n";
}
double MetricConvertor::getValue() const
{
    return value;
}
void MetricConvertor::setValue(double theValue)
{
    value = theValue;
}
void MetricConvertor::setMap() {
    myMap["a"] = 1;
    myMap["A"] = 1;
    myMap["b"] = 2;
    myMap["B"] = 2;
    myMap["c"] = 3;
    myMap["C"] = 3;
    myMap["d"] = 4;
    myMap["D"] = 4;
    myMap["e"] = 5;
    myMap["E"] = 5;
    myMap["f"] = 6;
    myMap["F"] = 6;
    myMap["h"] = 7;
    myMap["H"] = 7;
    myMap["help"] = 7;
    myMap["Help"] = 7;
    myMap["HELP"] = 7;
}
void MetricConvertor::valueInput()
{
    
    std::cout << "Enter the value: ";
    std::cin >> value;
    //ERROR HANDLING
    while (std::cin.fail())
    {
        std::cout << "Please enter an integer!" << std::endl;
        // clear error state
        std::cin.clear();
        // discard 'bad' character(s)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
}
void MetricConvertor::getInput() {
    std::cout << "Enter your choice: " << std::endl;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!isValidChoice(choice))
    {
        std::cout << "ERROR! Your choice is invalid!" << std::endl;
        std::cout << "------------------------------" << std::endl;
        getInput();
    }
}
void MetricConvertor::printMenu()
{
    std::cout << "--------------------Metric Converter-----------------------" << std::endl;
    std::cout << "a) km to miles and miles to kilometers" << std::endl;
    std::cout << "b) Celsius to Fahrenheit and Fahrenheit to Celsius" << std::endl;
    std::cout << "c) kg to pounds and pounds to kg" << std::endl;
    std::cout << "d) meters to feet and feet to meters" << std::endl;
    std::cout << "e) inches to cm and cm to inches" << std::endl;
    std::cout << "f) mph to kph and kph to mph" << std::endl;
    std::cout << "h) HELP" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
}
double MetricConvertor::kmToMiles()
{
    return value * mileInKM;
}
double MetricConvertor::milesToKM()
{
    return value / mileInKM;
}
double MetricConvertor::celsiusToFahrenheit()
{
    return (32 + 1.8 * value);
}
double MetricConvertor::fahrenheitToCelsius()
{
    return ((value - 32) / 1.8);
}
double MetricConvertor::kgToPounds()
{
    return value * poundInKG;
}
double MetricConvertor::poundsToKG()
{
    return value / poundInKG;
}
double MetricConvertor::metersToFeet()
{
    return value * footInMeters;
}
double MetricConvertor::feetToMeters()
{
    return value / footInMeters;
}
double MetricConvertor::inchesToCM()
{
    return value / inchInCM;
}
double MetricConvertor::cmToInches()
{
    return value * inchInCM;
}
double MetricConvertor::mphToKPH()
{
    return value * mphInKPH;
}
double MetricConvertor::kphToMPH()
{
    return value / mphInKPH;
}
bool MetricConvertor::isValidChoice(std::string choice)
{
    if (choice == "a" || choice == "A" || choice == "b" || choice == "B" || choice == "c" ||
        choice == "C" || choice == "d" || choice == "D" || choice == "e" || choice == "E" ||
        choice == "f" || choice == "F" || choice == "h" || choice == "H" || choice == "help"
        || choice == "Help" || choice == "HELP")
    {
        return true;
    }
    else {
        return false;
    }
}
void MetricConvertor::on()
{
    printMenu();
    getInput();
    switch (myMap[choice])
    {
        case 1:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert km to miles " << std::endl;
            std::cout << "b) convert miles to km " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " km in miles is: " <<  milesToKM() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " miles in kilometers is: " << kmToMiles() << std::endl;
                }
                break;
                default:
                {
                    std::cout << "ERROR! The choice was not found!" << std::endl;
                }
            }

        }
        break;
        case 2:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert Celsius to Fahrenheit " << std::endl;
            std::cout << "b) convert Fahrenheit to Celsius " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " Celsius in Fahrenheit is: " << celsiusToFahrenheit() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " Fahrenheit in Celsius is: " << fahrenheitToCelsius() << std::endl;
                }
                break;
                default:
                {
                    std::cout << "ERROR! The choice was not found!" << std::endl;
                }
            }

        }
        break;
        case 3:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert kg to pounds " << std::endl;
            std::cout << "b) convert pounds to kg " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " kg in pounds is: " << poundsToKG() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " pounds in kilograms is: " <<  kgToPounds() << std::endl;
                }
                break;
                default:
                {
                    std::cout << "ERROR! The choice was not found!" << std::endl;
                }
            }

        }
        break;
        case 4:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert meters to feet " << std::endl;
            std::cout << "b) convert feet to meters " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " meters in feet is: " <<  feetToMeters() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " feet in meters is: " << metersToFeet() << std::endl;
                }
                break;
                default:
                {
                    std::cout << "ERROR! The choice was not found!" << std::endl;
                }
            }

        }
        break;
        case 5:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert inches to cm " << std::endl;
            std::cout << "b) convert cm to inches " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " inches in cm is: " <<  cmToInches() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " cm in inches is: " << inchesToCM() << std::endl;
                }
                break;
                default:
                {
                    std::cout << "ERROR! The choice was not found!" << std::endl;
                }
            }

        }
        break;
        case 6:
        {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert mph to kph " << std::endl;
            std::cout << "b) convert kph to mph " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            valueInput();
            switch (myMap[choice])
            {
            case 1:
            {
                std::cout << value << " mph in kph is: " << mphToKPH() << std::endl;
            }
            break;
            case 2:
            {
                std::cout << value << " kph in mph is: " << kphToMPH() << std::endl;
            }
            break;
            default:
            {
                std::cout << "ERROR! The choice was not found!" << std::endl;
            }
            }

        }
        break;
        case 7:
        {
            help();
            on();
        }
        break;
        default:
        {
            std::cout << "ERROR! The choice was not found!" << std::endl;
        }
    }
    
}
void MetricConvertor::help() {
    std::cout << "-------------------------HELP---------------------------" << std::endl;
    std::cout << "The Metric Converter allows you to convert values from the" << std::endl;
    std::cout << "Imperial to the metric system. You just have to choose what" << std::endl;
    std::cout << "unit you want and then you will be prompted to enter the value." << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
}