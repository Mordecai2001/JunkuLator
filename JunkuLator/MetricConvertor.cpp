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
}
void MetricConvertor::valueInput()
{
    try
    {
        std::cout << "Enter the value: ";
        std::cin >> myValue;
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Invalid input. Please enter a floating point number." << std::endl;
        valueInput();
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
    getInput();
    switch (myMap[choice])
    {
        case 1:
        {
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert km to miles " << std::endl;
            std::cout << "b) convert miles to km " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " in miles is: " << kmToMiles() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " in kilometers is: " << milesToKM() << std::endl;
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
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert Celsius to Fahrenheit " << std::endl;
            std::cout << "b) convert Fahrenheit to Celsius " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " in Fahrenheit is: " << celsiusToFahrenheit() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " in Celsius is: " << fahrenheitToCelsius() << std::endl;
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
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert kg to pounds " << std::endl;
            std::cout << "b) convert pounds to kg " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " in pounds is: " << kgToPounds() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " in kilograms is: " << poundsToKG() << std::endl;
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
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert meters to feet " << std::endl;
            std::cout << "b) convert feet to meters " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " in feet is: " << metersToFeet() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " in meters is: " << feetToMeters() << std::endl;
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
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert inches to cm " << std::endl;
            std::cout << "b) convert cm to inches " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
                case 1:
                {
                    std::cout << value << " in cm is: " << inchesToCM() << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << value << " in inches is: " << cmToInches() << std::endl;
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
            valueInput();
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "a) convert mph to kph " << std::endl;
            std::cout << "b) convert kph to mph " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            getInput();
            switch (myMap[choice])
            {
            case 1:
            {
                std::cout << value << " in kph is: " << mphToKPH() << std::endl;
            }
            break;
            case 2:
            {
                std::cout << value << " in mph is: " << kphToMPH() << std::endl;
            }
            break;
            default:
            {
                std::cout << "ERROR! The choice was not found!" << std::endl;
            }
            }

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