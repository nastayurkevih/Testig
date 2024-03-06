#include "User.h"
void User::SetName(char* name)
{
    this->name = name;
}
void User::SetMiddleName(char* middleName)
{
    this->middleName = middleName;
}
void User::SetSurename(char* Surename)
{
    this->Surename = Surename;
}
void User::SetAdress(char* Adress)
{
    this->Adress = Adress;
}
void User::SetPhonee(char* phone)
{
    this->phone = phone;
}
char* User::GetName()
{
    return name;
}
char* User::GetmiddleName()
{
    return middleName;
}
char* User::GetSurename()
{
    return Surename;
}
char* User::GetAdress()
{
    return Adress;
}
char* User::GetPhone()
{
    return phone;
}
void User::Fillfile()
{
    std::ofstream fileUser;
    fileUser.open("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::app);
    if (fileUser.is_open())
    {
        fileUser << name << " " << middleName << " " << Surename << " " << Adress << " " << phone << "\n";
    }
    else
    {
        std::cout << "Файл длоя записи данных не открылся" << std::endl;
    }
    fileUser.close();
}
void User::LogFill()
{
    std::ofstream filelogin;
    filelogin.open("C:\\ProgramData\\Testing Sestem\\login.txt", std::ios::app);
    if (filelogin.is_open())
    {
        filelogin << login << "\n";
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filelogin.close();
}
void User::PassFill()
{
    std::ofstream filepass;
    filepass.open("C:\\ProgramData\\Testing Sestem\\password.txt", std::ios::app);
    if (filepass.is_open())
    {
        filepass << password << "\n";
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filepass.close();
}
void User::SetLog(std::string login)
{
    this->login = login;
}
void User::SetPass(std::string password)
{
    this->password = password;
}
int User::GetId()
{
    std::ifstream filelogin;
    filelogin.open("C:\\ProgramData\\Testing Sestem\\login.txt");
    int id = 0;
    if (filelogin.is_open())
    {
        std::string line;
        while (!filelogin.eof())
        {
            filelogin >> line;
            if (login == line)
            {
                return id;
            }
            id++;
        }
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filelogin.close();
    return -1;
}
std::string User::Getlogin()
{
    return login;
}