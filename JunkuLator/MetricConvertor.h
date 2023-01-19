#pragma once
#include <map>
#include <string>

class MetricConvertor
{
private:
    int value{};
    std::map<std::string, int> myMap{};

public:
    // constructors and the destructor
    MetricConvertor() = default;
    MetricConvertor(int theValue);
    ~MetricConvertor();

    // setters and getters
    int getValue() const;
    void setValue(int theValue);

    // input
    void valueInput();

    // utility
    void printMenu();
    int kmToMiles();
    int milesToKM();
    int celsiusToFahrenheit();
    int fahrenheitToCelsius();
    int kgToPounds();
    int poundsToKG();
    int metersToFeet();
    int feetToMeters();
    int inchesToCM();
    int cmToInches();
    int mphToKPH();
    int kphToMPH();
    void setMap();
    bool isValidChoice(std::string choice);
    void on();
};

