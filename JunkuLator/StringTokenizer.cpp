/*
Program name: StringTokenizer Implementation
Author: Rares-Mihail Neagu
Date(s): current form 01/27/23
Version Control: Git
*/
#include <iostream>
#include <cctype>
#include <vector>
#include <iterator>
#include <limits>
#include "StringTokenizer.h"

StringTokenizer::StringTokenizer()
{
    setMap();
}
StringTokenizer::StringTokenizer(std::string theString)
{
    myString = theString;
    tokenize();
    setMap();
}
StringTokenizer::~StringTokenizer() {
    std::cout << "String Tokenizer Destructor Call\n";
}
std::string StringTokenizer::getString() const
{
    return myString;
}
void StringTokenizer::setString(std::string &theString)
{
    myString = theString;
}
void StringTokenizer::tokenize()
{
    for (auto &ch : myString)
    {
        if (ispunct(ch))
        {
            removeChar(ch);
        }
    }
    int k = 0; // the character position
    char currentChar = ' ';
    for (int i = 0; i < myString.length(); i++)
    {
        currentChar = myString[i];
        if (isblank(currentChar))
        {
            if (i != 0 && !isblank(myString[i - 1])) // check if there are multiple spaces between words
            {
                words.push_back(myString.substr(k, i - k));
                k = i + 1; // the current character after the space character
            }
            else if (i != 0)
                k++;
        }
        else if (i == (myString.length() - 1) && !isblank(myString[i]))
        {
            words.push_back(myString.substr(k, myString.length() - k));
        }
    }
}
void StringTokenizer::removeChar(char character)
{
    std::string result;
    for (auto &ch : myString) // range-based for loop
    {
        if (ch != character)
        {
            result += ch;
        }
    }
    myString = result;
}
int StringTokenizer::numberOfWords()
{
    return words.size();
}
int StringTokenizer::numberOfLetters()
{
    int number{0};
    std::vector<std::string>::iterator i;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        number += (*i).length();
    }
    return number;
}
void StringTokenizer::printReverseLine()
{

    int size = myString.length();
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << myString[i];
    }
    std::cout << std::endl;
}
void StringTokenizer::printCapitalWords()
{
    std::vector<std::string>::iterator i;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        if (isupper((*i).at(0)))
            std::cout << *i << std::endl;
    }
}
void StringTokenizer::findWord(std::string &word)
{
    bool flag = false;
    std::vector<std::string>::iterator i;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        if ((*i) == word)
        {
            flag = true;
        }
    }
    if (flag)
    {
        std::cout << "Found" << std::endl;
    }
    else
        std::cout << "Not Found" << std::endl;
}
bool StringTokenizer::isFound(std::string word)
{
    bool flag = false;
    std::vector<std::string>::iterator i;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        if ((*i) == word)
        {
            flag = true;
        }
    }
    return flag;
}
void StringTokenizer::setMap()
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
    myMap["h"] = 7;
    myMap["H"] = 7;
    myMap["help"] = 7;
    myMap["Help"] = 7;
    myMap["HELP"] = 7;
}
void StringTokenizer::getInput() {
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
void StringTokenizer::inputString() {
    std::cout << "Enter the text: ";
    getline(std::cin, myString);
    tokenize();
    std::cout << "The text has been analyzed!" << std::endl;
}
void StringTokenizer::printMenu()
{
    std::cout << "-------------------String Tokenizer---------------------" << std::endl;
    std::cout << "a. Read a full line of text from the user and analyze it." << std::endl;
    std::cout << "b. Print the total number of letters in the line." << std::endl;
    std::cout << "c. Print the total number of words in the line." << std::endl;
    std::cout << "d. Print the line backwards." << std::endl;
    std::cout << "e. Print all words that starts with capital letter." << std::endl;
    std::cout << "f. Search for a word in the line." << std::endl;
    std::cout << "h.HELP" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}
bool StringTokenizer::isValidChoice(std::string choice)
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
void StringTokenizer::continueAnalysis()
{
    std::cout << "Do you want to perform operations on the analyzed string?(y/n): ";
    std::string continueChoice;
    std::cin >> continueChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (continueChoice == "y" || continueChoice == "yes" || continueChoice == "Y"
        || continueChoice == "YES")
    {
        on();
    }
    else if (continueChoice != "n" && continueChoice != "no" && continueChoice != "N"
        && continueChoice != "NO")
    {
        std::cout << "ERROR! Your choice is invalid!" << std::endl;
    }
}
void StringTokenizer::on()
{
    printMenu();
    getInput();
    switch (myMap[choice])
    {
        case 1:
        {
            inputString();
            continueAnalysis();
        }
        break;
        case 2:
        {
            if (myString == "") inputString();
            std::cout << "The total number of letters in the line is: " << numberOfLetters() << std::endl;
            continueAnalysis();
        }
        break;
        case 3:
        {
            if (myString == "") inputString();
            std::cout << "The total number of words in the line is: " << numberOfWords() << std::endl;
            continueAnalysis();
        }
        break;
        case 4:
        {
            if (myString == "") inputString();
            std::cout << "The line written backwards is: ";
            printReverseLine();
            continueAnalysis();
        }
        break;
        case 5:
        {
            if (myString == "") inputString();
            std::cout << "All the words that start with a capital letter are: ";
            printCapitalWords();
            continueAnalysis();
        }
        break;
        case 6:
        {
            if (myString == "") inputString();
            std::cout << "Enter the word you are looking for: " << std::endl;
            std::string newWord;
            std::cin >> newWord;
            if (isFound(newWord))
                std::cout << "Found" << std::endl;
            else
                std::cout << "Not Found" << std::endl;
            continueAnalysis();
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
            std::cout << "ERROR! Choice not found!" << std::endl;
        }
    }
    
}
void StringTokenizer::help() {
    std::cout << "-------------------------HELP---------------------------" << std::endl;
    std::cout << "The String Tokenizer allows you to analyze a string and" << std::endl;
    std::cout << "see how many words and letters are in the string, you can also" << std::endl;
    std::cout << "print the string in reverse, and a lot more. To use it you just" << std::endl;
    std::cout << "have to enter the string and then choose the what you want to do" << std::endl;
    std::cout << "with it." << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
}