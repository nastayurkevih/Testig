#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <fstream>
class Quiz
{
public:
    void showStatistic();
    void makeQuiz();
    void selectingSection();
    void AddSect(std::string newSect);
    void AddNameQuiz(std::string newName, char id);
    void AddQuestions(std::string newQues, char id1, int id2);
    void AddAnswers(std::string newAnsweri, char id1, int id2);
    void choiceTest();
    int numTest(char id);
    void Test(char id1, char id2, int k = 0);
    int determineScore(double pr);
    void ShowAnswers();
    void SaveInterTesting(char id1, char id2);
    void Selogin(std::string login);
    void ShowfinishTest();
    void saveStatic(char id1, char id2, int all, int right);
    void showStatic();
    void deleteFinishTest(char id1, char id2);
    void deleteTest();
private:
    std::vector<std::string> sections;
    std::vector<std::string> nameQuiz;
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::vector<std::string> useranswer;
    std::vector<bool> answerRT;
    int countQues;
    std::string login;
};
