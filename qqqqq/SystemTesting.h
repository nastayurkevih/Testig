#pragma once
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <fstream>
#include "User.h"
#include "Quiz.h"
class SystemTesting
{
public:
    int Start();
    void UserStart();
    void UserLog();
    bool PersonInFile(std::string login, std::string password);
    void AdminLogin();
    void RegistrationUsers();
    bool ThereIsLog(std::string login);
    bool ThereIsPass(std::string password);
    void Fillfile();
    void ShowProfile();
    void makeFile();
    void showAdminProfil();
    void DeleteUser(int k = 0);
    void ChangeUser();

private:
    User user;
    Quiz quiz;
  
};

