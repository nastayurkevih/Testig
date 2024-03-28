#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <fstream>

class User
{
public:
    User(char* name, char* middleName, char* Surename, char* Adress) :
        name{ name }, middleName{ middleName }, Surename{ Surename }, Adress{ Adress } {}
    User() : phone{ 0 } {}
    void SetName(char* name);
    void SetMiddleName(char* middleName);
    void SetSurename(char* Surename);
    void SetAdress(char* Adress);
    void SetPhonee(char* phone);
    char* GetName();
    char* GetmiddleName();
    char* GetSurename();
    char* GetAdress();
    char* GetPhone();
    void SetLog(std::string login);
    void SetPass(std::string password);
    void LogFill();
    void PassFill();
    int GetId();
    void Fillfile();
    std::string Getlogin();

private:
    char* name;
    char* middleName;
    char* Surename;
    char* Adress;
    char* phone;
    std::string login;
    std::string password;
};
