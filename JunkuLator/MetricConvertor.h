#pragma once
#include <map>
#include <string>
#include "Machine.h"

class MetricConvertor : public Machine
{
private:
    double value{};
    std::map<std::string, int> myMap{};

public:
    // constructors and the destructor
    MetricConvertor() = default;
    MetricConvertor(double theValue);
    ~MetricConvertor();

    // setters and getters
    double getValue() const;
    void setValue(double theValue);

    // input
    void valueInput();

    // utility
    void printMenu();
    double kmToMiles();
    double milesToKM();
    double celsiusToFahrenheit();
    double fahrenheitToCelsius();
    double kgToPounds();
    double poundsToKG();
    double metersToFeet();
    double feetToMeters();
    double inchesToCM();
    double cmToInches();
    double mphToKPH();
    double kphToMPH();
    void setMap();
    bool isValidChoice(std::string choice);
    void on();
};

