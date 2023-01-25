/*
Program name: StringTokenizer
Author: Rares-Mihail Neagu
Date(s): current form 01/25/23
Version Control: Git
Program Description: The StringTokenizer is a multi-purpose
string analyzer that allows you to parse a string and check
the number of words, letters, print the line backwards and so
on.
*/
#pragma once
#include <string>
#include <vector>
#include <map>
#include "Machine.h"

class StringTokenizer : public Machine
{
private:
    std::string myString{""};
    std::string choice{};
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

    //input
    void getInput();
    void inputString();
    

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
    
    //inherited from Machine
    void on();
    void help();
};

