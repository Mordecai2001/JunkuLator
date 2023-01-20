#pragma once
#include <string>
#include <vector>
#include <map>
#include "Machine.h"

class StringTokenizer : public Machine
{
private:
    std::string myString{};
    std::vector<std::string> words{};
    std::map<std::string, int> myMap{}; // used to store the choices

public:
    // constructors and the destructor
    StringTokenizer();
    StringTokenizer(std::string theString);
    ~StringTokenizer();

    // setters and getters
    std::string getString() const;
    void setString(std::string &theString);
    void setMap();

    // utility functions
    void tokenize();
    void removeChar(char character);
    int numberOfWords();
    int numberOfLetters();
    void printReverseLine();
    void printCapitalWords();
    void findWord(std::string &word);
    bool isFound(std::string word);
    void printMenu();
    bool isValidChoice(std::string choice);
    void continueAnalysis();
    void on();
};

