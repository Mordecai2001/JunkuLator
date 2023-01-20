#include <iostream>
#include "MetricConvertor.h"
#include "constants.h"

MetricConvertor::MetricConvertor(double theValue)
{
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
void MetricConvertor::valueInput()
{
    std::cout << "Enter the value: ";
    double theValue;
    std::cin >> theValue;
    setValue(theValue);
}
void MetricConvertor::printMenu()
{
    std::cout << "--------------------Metric Converter-----------------------" << std::endl;
    std::cout << "a) km to miles and Miles to Kilometers" << std::endl;
    std::cout << "b) Celsius to Fahrenheit and Fahrenheit to Celsius" << std::endl;
    std::cout << "c) kg to pounds and pounds to kg" << std::endl;
    std::cout << "d) Meters to Feet and Feet to Meters" << std::endl;
    std::cout << "e) inches to cm and cm to inches" << std::endl;
    std::cout << "f) mph to kph and kph to mph" << std::endl;
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
    return (value / 1.8 - 32);
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
void MetricConvertor::setMap()
{
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
}
bool MetricConvertor::isValidChoice(std::string choice)
{
    if (choice == "a" || choice == "A" || choice == "b" || choice == "B" || choice == "c" ||
        choice == "C" || choice == "d" || choice == "D" || choice == "e" || choice == "E" ||
        choice == "f" || choice == "F")
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
    std::cout << "Enter your choice: " << std::endl;
    std::string choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!isValidChoice(choice))
    {
        std::cout << "ERROR! Your choice is invalid!" << std::endl;
    }
    else
    {
        switch (myMap[choice])
        {
        case 1:
        {
            valueInput();
        }
        break;
        case 2:
        {
            std::cout << " ";
        }
        break;
        case 3:
        {
            std::cout << " ";
        }
        break;
        case 4:
        {
            std::cout << " ";
        }
        break;
        case 5:
        {
            std::cout << " ";
        }
        break;
        case 6:
        {
            std::cout << " ";
        }
        break;
        default:
        {
            std::cout << "ERROR! The choice was not found!" << std::endl;
        }
        }
    }
}