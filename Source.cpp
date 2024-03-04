#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <fstream>
//не слитывает решеннынеот веты,  шифровка
class User
{
public:
    User(char* name, char* middleName, char* Surename, char* Adress, long long phone) :
        name{ name }, middleName{ middleName }, Surename{ Surename }, Adress{ Adress }, phone{ phone } {}
    User() : phone{ 0 } {}
    void SetName(char* name);
    void SetMiddleName(char* middleName);
    void SetSurename(char* Surename);
    void SetAdress(char* Adress);
    void SetPhonee(long long phone);
    char* GetName();
    char* GetmiddleName();
    char* GetSurename();
    char* GetAdress();
    long long GetPhone();
    void SetLog(std::string login);
    void SetPass(std::string password);
    void LogFill();
    void PassFill();
    int GetId();
    std::string Getlogin();
    void Fillfile();
private:
    char* name;
    char* middleName;
    char* Surename;
    char* Adress;
    long long phone;
    std::string login;
    std::string password;
};
class Quiz
{
public:
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
    void deleteFinishTest(char id1, char id2 );
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
class SystemTesting
{
public:
    SystemTesting() : r{ 0 } {}
    void Start();
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
private:
    User user;
    Quiz quiz;
    int r;
};

//• Просмотр статистики – просмотр результатов тестирования в общем
//по категориям, по конкретным тестам, по конкретным пользователям.
//Результаты просмотра статистики можно вывести в файл.




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SystemTesting test;
    test.Start();
    Quiz quiz;
    //quiz.ShowfinishTest();
   /* int x;
    x = _getch();
    std::cout << x;*/


};

void SystemTesting::Start()
{
    makeFile();
    system("cls");
    int c = 119;
    int k;
    std::cout << "Начало тестирования.\n Выберите режим пользования." << std::endl;
    std::cout << "(включите на кавиатуре английкую раскладку)" << std::endl;
    Sleep(4000);
    while (c != 13)
    {
        if (c == 119)
        {
            system("cls");
            std::cout << "-->Войти как администратор" << std::endl;
            std::cout << "\tВойти как ползователь" << std::endl;
            k = c;
            c = _getch();
        }
        else if (c == 115)
        {
            system("cls");
            std::cout << "\tВойти как администратор" << std::endl;
            std::cout << "-->Войти как ползователь" << std::endl;
            k = c;
            c = _getch();
        }
        else
        {
            system("cls");
            std::cout << "-->Войти как администратор" << std::endl;
            std::cout << "\tВойти как ползователь" << std::endl;
            k = c;
            c = _getch();
        }
    }
    system("cls");
    if (k == 115)
    {
        UserStart();
    }
    else if(k==119)
    {
        AdminLogin();
    }  
}
void SystemTesting::UserStart()
{
    std::cout << "Выбран режим пользователя" << std::endl;
    int c = 119;
    int k;
    Sleep(2000);
    while (c != 13)
    {
        if (c == 119)
        {
            system("cls");
            std::cout << "-->Войти в систему" << std::endl;
            std::cout << "\tЗарегистрироваться" << std::endl;
            k = c;
            c = _getch();
        }
        else if (c == 115)
        {
            system("cls");
            std::cout << "\tВойти в систему" << std::endl;
            std::cout << "-->Зарегистрироваться" << std::endl;
            k = c;
            c = _getch();
        }
        else
        {
            system("cls");
            std::cout << "-->Войти в систему" << std::endl;
            std::cout << "\tЗарегистрироваться" << std::endl;
            k = c;
            c = _getch();
        }
    }
    system("cls");
    if (k == 119)
    {
        UserLog();
    }

    else
    {
        RegistrationUsers();
    }
}
void SystemTesting::UserLog()
{
    std::string login;
    std::string password;
    std::cout << "Ведите логин: ";
    getline(std::cin, login);
    std::cout << "Ведите пароль: ";
    getline(std::cin, password);
    if (!PersonInFile(login, password))
    {
        std::cout << "Вход успешно выполнен" << std::endl;
        Sleep(2000);
        system("cls");
        user.SetLog(login);
        user.SetPass(password);
        ShowProfile();
    }
    else
    {
        std::cout << "Пользователь не найден.\n Попробуйте ещё раз." << std::endl;
        UserLog();
    }
}
bool SystemTesting::PersonInFile(std::string login, std::string password)
{
    int countlog = 0;
    int countpass = 0;
    bool flaglog = true;
    bool flagpass= true;
    std::ifstream filelogin;
    filelogin.open("C:\\ProgramData\\Testing Sestem\\login.txt");
    if (filelogin.is_open())
    {
        std::string line;
        while (!filelogin.eof())
        {
            filelogin >> line;
            countlog++;
            if (login == line)
            {
                flaglog = false;
                break;
            }
        }
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filelogin.close();
    std::ifstream filepass;
    filepass.open("C:\\ProgramData\\Testing Sestem\\password.txt");
    if (filepass.is_open())
    {
        std::string line;
        while (!filepass.eof())
        {
            filepass >> line;
            countpass++;
            if (password == line)
            {
                flagpass = false;
                break;
            }
        }
    }
    else
    {
        std::cout << "Файл с паролями не открылся" << std::endl;
    }
    if (countlog == countpass and countlog > 0 and !flagpass and !flaglog)
    {
        return false;
    }
    filepass.close();
    return true;
}
bool SystemTesting::ThereIsLog(std::string login)
{
    std::ifstream filelogin;
    filelogin.open("C:\\ProgramData\\Testing Sestem\\login.txt");
    if (filelogin.is_open())
    {
        std::string line;
        while (!filelogin.eof())
        {
            filelogin >> line;
            if (login == line)
            {
                return false;
            }
        }
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filelogin.close();
    return true;
}
bool SystemTesting::ThereIsPass(std::string password)
{
    std::ifstream filepass;
    filepass.open("C:\\ProgramData\\Testing Sestem\\password.txt");
    if (filepass.is_open())
    {
        std::string line;
        while (!filepass.eof())
        {
            filepass >> line;
            if (password == line)
            {
                return false;
            }
        }
    }
    else
    {
        std::cout << "Файл с паролями не открылся" << std::endl;
    }
    filepass.close();
    return true;
}
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
void User::SetPhonee(long long phone)
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
long long User::GetPhone()
{
    return phone;
}
void SystemTesting::Fillfile()
{
    std::ofstream fileUser;
    fileUser.open("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::app);
    if (fileUser.is_open())
    {
        fileUser << user.GetName() << " " << user.GetmiddleName() << " " << user.GetSurename() << " " << user.GetAdress() << " " << user.GetPhone() << "\n";
    }
    else
    {
        std::cout << "Файл длоя записи данных не открылся" << std::endl;
    }
    fileUser.close();
}
void SystemTesting::RegistrationUsers()
{
    system("cls");
    std::string login;
    std::string password;
    std::cout << "Придумайте логин: ";
    getline(std::cin, login);
    std::cout << "Придумайте пароль: ";
    getline(std::cin, password);
    if (!ThereIsLog(login))
    {
        std::cout << "Пользователь с таким логином уже сужествует.\nПридумайте новый логин." << std::endl;
        RegistrationUsers();
    }
    else if (!ThereIsPass(password))
    {
        std::cout << "Пользователь с таким паролем уже сужествует.\nПридумайте новый пароль." << std::endl;
        RegistrationUsers();
    }
    else
    {
        user.SetLog(login);
        user.SetPass(password);
        user.LogFill();
        user.PassFill();
        char* name = new char[250] {};
        char* middleName = new char[250] {};
        char* Surename = new char[250] {};
        char* Adress = new char[250] {};
        long long phone;
        std::cout << "Введите имя: " << std::endl;
        //std::cin.ignore();
        std::cin >> name;
        user.SetName(name);
        std::cout << "Введите отчество: " << std::endl;
        std::cin.ignore();
        std::cin >> middleName;
        user.SetMiddleName(middleName);
        std::cout << "Введите фамилию: " << std::endl;
        std::cin.ignore();
        std::cin >> Surename;
        user.SetSurename(Surename);
        std::cout << "Введите адресс: " << std::endl;
        std::cin.ignore();
        std::cin >> Adress;
        user.SetAdress(Adress);
        std::cout << "Номер телофона: " << std::endl;
        std::cin >> phone;
        user.SetPhonee(phone);
        Fillfile();
        std::cout << "Регистрация прошла успешна." << std::endl;
        ShowProfile();
    }
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
void Quiz::selectingSection()
{
    sections.clear();
    std::ifstream Sections;
    Sections.open("C:\\ProgramData\\Testing Sestem\\setcions.txt", std::ios::app);
    if (Sections.is_open())
    {
        std::string line;
        Sections >> line;

        while (!Sections.eof())
        {
            sections.push_back(line);
            Sections >> line;
        }
        //sections.push_back(line);
    }
    else
    {
        std::cout << "Файл с разделами не открылся" << std::endl;
    }
}
void Quiz::AddSect(std::string newSect)
{
    std::ofstream Sections;
    Sections.open("C:\\ProgramData\\Testing Sestem\\setcions.txt", std::ios::app);
    if (Sections.is_open())
    {
        Sections << newSect << "\n";
    }
    else
    {
        std::cout << "Файл для записи отделов не открылся" << std::endl;
    }
    Sections.close();
}
void Quiz::AddNameQuiz(std::string newName, char id)
{
    std::ofstream Name;
    Name.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt", std::ios::app);
    if (Name.is_open())
    {
        Name << id << newName << "\n";
    }
    else
    {
        std::cout << "Файл для записи названий викторин не открылся" << std::endl;
    }
    Name.close();
}
void Quiz::AddQuestions(std::string newQues, char id1, int id2)
{
    std::ofstream Questions;
    Questions.open("C:\\ProgramData\\Testing Sestem\\questions.txt", std::ios::app);
    if (Questions.is_open())
    {
        Questions << id1 << id2 << newQues << "\n";
    }
    else
    {
        std::cout << "Файл для записи вопросов не открылся" << std::endl;
    }
    Questions.close();
}
void Quiz::AddAnswers(std::string newAnswer, char id1, int id2)
{
    std::ofstream Questions;
    Questions.open("C:\\ProgramData\\Testing Sestem\\answer.txt", std::ios::app);
    if (Questions.is_open())
    {
        Questions << id1 << id2 << newAnswer << "\n";
    }
    else
    {
        std::cout << "Файл для записи ответов не открылся" << std::endl;
    }
    Questions.close();
}
void Quiz::makeQuiz() {
    system("cls");
    countQues = 0;
    char choise = ' ';
    std::string nameQuiz;
    std::string questions;
    std::string answers;
    int count = 0;//номер раздела
    selectingSection();
    std::cout << "Выберите раздел: " << std::endl;
    std::cout << std::endl;
    for (auto line : sections)
    {
        count++;
        std::cout << count << " " << line << std::endl;
    }
    count++;
    std::cout << count << " Добавить новый раздел" << std::endl;
    std::cout << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choise;
    std::cout << std::endl;
    count = static_cast<int>(choise) - 48;
    if (sections.size() + 1 == count)
    {
        std::string newSect;
        std::cout << "Введите название нового раздела: ";
        std::cin.ignore();
        getline(std::cin, newSect);
        AddSect(newSect);
    }
    std::cout << std::endl;
    std::cout << "Введите название теста: ";
    std::cin.ignore();
    getline(std::cin, nameQuiz);
    AddNameQuiz(nameQuiz, choise);
    count = 0;
    int id1 = numTest(choise);
    if (id1==0)
    {
        id1 = 1;
    }
    system("cls");
    count = 0;
    while (count != 32)
    {
        std::cout << std::endl;
        countQues++;
        std::cout << "Введите вопрос: ";
        getline(std::cin, questions);
        AddQuestions(questions, choise, id1);
        std::cout << std::endl;
        std::cout << "Введите ответ: ";
        getline(std::cin, answers);
        AddAnswers(answers, choise, id1);
        std::cout << std::endl;
        system("cls");
        std::cout << "Чтобы завершить ввод вопросов нажмите пробел." << std::endl;
        std::cout << std::endl;
        count = _getch();

    }
    std::cout << "Тест успешно создан." << std::endl;
    Sleep(2000);
    system("cls");
}
int Quiz::numTest(char id)
{
    std::ifstream NameTest;
    NameTest.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
    int Id = 0;
    if (NameTest.is_open())
    {
        std::string line;
        while (std::getline(NameTest, line))
        {

            _getch();
            if (id == line[0])
            {

                Id++;
            }
        }
    }
    else
    {
        std::cout << "Файл с названиями не открылся" << std::endl;
    }
    NameTest.close();
    return Id;
}
void Quiz::choiceTest()
{
    nameQuiz.clear();
    sections.clear();
    system("cls");
    selectingSection();
    std::cout << "Выберите раздел: " << std::endl;
    std::cout << std::endl;
    int count = 1;
    for (auto line : sections)
    {
        std::cout << count << " " << line << std::endl;
        count++;
    }
    std::cout << "Ваш выбор: ";
    char chois;
    std::cin >> chois;
    std::cout << std::endl;
    system("cls");
    std::ifstream NameTest;
    NameTest.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
    count = 1;
    int id = 0;
    if (NameTest.is_open())
    {
        std::string line;
        while (std::getline(NameTest, line))
        {
            if (chois == line[0])
            {
                nameQuiz.push_back(line.erase(0, 1));
            }
        }
    }
    else
    {
        std::cout << "Файл с названиями не открылся" << std::endl;
    }
    NameTest.close();
    for (auto line : nameQuiz)
    {
        std::cout << count << " " << line << std::endl;
        count++;
    }
    std::cout << "Ваш выбор: ";
    char chois2;
    std::cin >> chois2;
    system("cls");
    Test(chois, chois2);
}
int Quiz::determineScore(double pr)
{

    if (pr == 100)
    {
        return 12;
    }
    else if (pr >= 95)
    {
        return 11;
    }
    else if (pr >= 90)
    {
        return 10;
    }
    else if (pr >= 85)
    {
        return 9;
    }
    else if (pr >= 80)
    {
        return 8;
    }
    else if (pr >= 70)
    {
        return 7;
    }
    else if (pr >= 60)
    {
        return 6;
    }
    else if (pr >= 50)
    {
        return 5;
    }
    else if (pr >= 40)
    {
        return 4;
    }
    else if (pr >= 30)
    {
        return 3;
    }
    else if (pr >= 20)
    {
        return 2;
    }
    else if (pr >= 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
void Quiz::ShowAnswers()
{
    int count = 0;
    system("cls");
    for (auto ques : questions)
    {
        std::cout << count + 1 << ". " << ques << std::endl;
        std::cout << "Ваш ответ: " << useranswer[count] << std::endl;
        if (answerRT[count])
        {

            std::cout << "Верный ответ." << std::endl;
        }
        else
        {
            std::cout << "Неправильный ответ." << std::endl;
            std::cout << "Верный ответ." <<answers[count]<< std::endl;
        }
        count++;
        std::cout << std::endl;
    }
    std::cout << "Нажмиет любую клавишу, чтобы вернуться в аккаунт." << std::endl;
    count = _getch();
}
void Quiz::SaveInterTesting(char id1, char id2)
{
    std::ofstream filelogin;
    filelogin.open("C:\\ProgramData\\Testing Sestem\\InterTesting.txt", std::ios::app);
    if (filelogin.is_open())
    {
        filelogin <<login<< " "<<id1<< " " << id2<<" ";
        for (auto ans: useranswer)
        {
            filelogin <<ans<< " ";
        }
        filelogin<<"0all0" << "\n";
    }
    else
    {
        std::cout << "Файл с логинами не открылся" << std::endl;
    }
    filelogin.close();
}
void Quiz::Selogin(std::string login)
{
    this->login = login;
}
void Quiz::ShowfinishTest()
{
    int count = 0;
    int k = 0;
    std::vector<std::string> id1;
    std::vector<std::string> id2;
    std::ifstream Sections;
    std::ifstream NameTest;
   
    Sections.open("C:\\ProgramData\\Testing Sestem\\InterTesting.txt");
    if (Sections.is_open())
    {
        std::string line;
        Sections >> line;
        while (!Sections.eof())
        {
            if (line==login)
            {
                count++;
                Sections >> line;
                id1.push_back(line);
                Sections >> line;
                id2.push_back(line);
                Sections >> line;
                while (line!="0all0")
                {
                    useranswer.push_back(line);
                    Sections >> line;
                    k++;

                }
                selectingSection();
                std::cout<<count << ". Раздел: " << sections[stoi(id1.back())-1];
                int countname = 0;
                NameTest.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
                if (NameTest.is_open())
                {
                    std::string name;
                    while (std::getline(NameTest, name))
                    {
                      
                        if ((stoi(id1.back()) == (static_cast<int>(name[0])) - 48))
                        {
                            countname++;
                            if ((stoi(id2.back()) == countname))
                            {
                               std::cout <<" тест: " << name.erase(0, 1) << std::endl;
                                break;
                            }
                            
                        }
                    }
                }
                else
                {
                    std::cout << "Файл с названиями не открылся" << std::endl;
                }
                NameTest.close();
            }
            Sections >> line;
        }
    }
    else
    {
        std::cout << "Файл с разделами не открылся" << std::endl;
    }
    Sections.close();

    if (count==0)
    {
        std::cout << "У вас нет незавершённых тестов." << std::endl; 
        Sleep(2000);
    }
    else
    {
        std::cout << "Какой тест продолжить решать? ";
        int chois2;
        std::cin >> chois2;
        system("cls");
        Test(id1[chois2 - 1][0], id2[chois2 - 1][0],k );
        deleteFinishTest(id1[chois2 - 1][0], id2[chois2 - 1][0] );
    }
}
void Quiz::deleteFinishTest(char id1, char id2)
{

    int count = 0;
    int k = 0;
    std::vector<std::string> data;
    std::ifstream Sections;
    Sections.open("C:\\ProgramData\\Testing Sestem\\InterTesting.txt");
    if (Sections.is_open())
    {
        std::string line;
        Sections >> line;
        while (!Sections.eof())
        {
            if (line == login)
            {

                Sections >> line;
                if (stoi(line) == (static_cast<int>(id1) - 48))
                {
                    std::string str = line;
                    Sections >> line;
                    if (stoi(line) == (static_cast<int>(id2) - 48))
                    {
                        while (line != "0all0")
                        {
                            Sections >> line;
                        }
                        data.push_back("0all0");
                    }
                    else
                    {
                        data.push_back(login);
                        data.push_back(str);
                        data.push_back(line);
                    }
                }
                else
                {
                    data.push_back(login);
                    data.push_back(line);
                }

            }
            else
            {
                data.push_back(line);
            }
            Sections >> line;
        }
    }
    else
    {
        std::cout << "Файл с незаверщшенными тестамине открылся" << std::endl;
    }
    Sections.close();
    std::ofstream InterTesting;
    InterTesting.open("C:\\ProgramData\\Testing Sestem\\InterTesting.txt");
    if (InterTesting.is_open())
    {
        for (auto str : data)
        {
            if (str == "0all0")
            {
                InterTesting << str << " ";
                InterTesting << "\n";
            }
            InterTesting << str << " ";
        }
    }
    else
    {
        std::cout << "Файл с незаверщшенными тестамине открылся" << std::endl;
    }
    InterTesting.close();

}
void SystemTesting::ShowProfile()
{
    int chois = 0;
    system("cls");
    std::ifstream fileUser;
    fileUser.open("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::app);
    if (fileUser.is_open())
    {
        std::cout << "Информация о пользователи." << std::endl;
        int id = user.GetId();
        id = id * 5;
        if (id > -1)
        {
            std::string line = "";
            int count = 0;
            while (!fileUser.eof())
            {
                fileUser >> line;
                if (count == id)
                {
                    std::cout << std::endl;
                    std::cout << "ФИО пользователя:" << line << " ";
                    fileUser >> line;
                    std::cout << line << " ";
                    fileUser >> line;
                    std::cout << line << " " << std::endl;
                    fileUser >> line;
                    std::cout << std::endl;
                    std::cout << "Адресс пользователя:" << line << std::endl;
                    fileUser >> line;
                    std::cout << std::endl;
                    std::cout << "Телефон пользователя:" << line << std::endl;
                    break;
                }
                count++;
            }
        }
        else
        {
            std::cout << "Ошибка! id не найден.";
        }
        std::cout << std::endl;
        std::cout << "Статистика пользователя." << std::endl;
        std::cout << "Чтобы просмотреть статистику нажмите s." << std::endl;
        std::cout << std::endl;
        std::cout << "Выбрать тестирование. Нажмите Enter." << std::endl;
        std::cout << "Выйти из аккаунта. Нажмите пробел." << std::endl;
        std::cout << "Дорешать неаконченные тесты. нажмите q." << std::endl;
        quiz.Selogin(user.Getlogin());
        chois = _getch();
        if (chois == 13)
        {

            quiz.choiceTest();
            system("cls");
            ShowProfile();
        }
        else if (chois == 32)
        {
            Start();
        }
        else if (chois == 115)
        {
            system("cls");
            quiz.showStatic();
            system("cls");
            ShowProfile();
        }
        else if (chois == 113)
        {
            system("cls");
            quiz.ShowfinishTest();
            system("cls");
            ShowProfile();
        }
        else
        {
            system("cls");
            ShowProfile();
        }
    }
    else
    {
        std::cout << "Файл для записи данных не открылся" << std::endl;
    }
    fileUser.close();

}
void Quiz::saveStatic(char id1, char id2, int all, int right)
{
    std::ofstream statistics;
    statistics.open("C:\\ProgramData\\Testing Sestem\\static.txt", std::ios::app);
    if (statistics.is_open())
    {
        statistics << login << " " << id1 << " " << id2 << " " << all << " " << right << "\n";
    }
    else
    {
        std::cout << "Файл с статистикой не открылся" << std::endl;
    }
    statistics.close();
}
void Quiz::showStatic()
{
    int count = 0;
    int k = 0;
    int allq = 0;
    int allr = 0;
    int all;
    int right = 0;
    std::vector<std::string> id1;
    std::vector<std::string> id2;
    std::ifstream statistics;
    std::ifstream NameTest;
    statistics.open("C:\\ProgramData\\Testing Sestem\\static.txt");
    if (statistics.is_open())
    {
        std::string line;
        statistics >> line;
        while (!statistics.eof())
        {
            if (line == login)
            {
                count++;
                statistics >> line;
                id1.push_back(line);
                statistics >> line;
                id2.push_back(line);
                statistics >> line;
                all = stoi(line);
                allq += all;
                statistics >> line;
                right = stoi(line);
                allr += right;
                selectingSection();
                std::cout << count << ". Раздел: " << sections[stoi(id1.back()) - 1];
                int countname = 0;
                NameTest.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
                if (NameTest.is_open())
                {
                    std::string name;
                    while (std::getline(NameTest, name))
                    {

                        if ((stoi(id1.back()) == (static_cast<int>(name[0])) - 48))
                        {
                            countname++;
                            if ((stoi(id2.back()) == countname))
                            {
                                std::cout << " тест: " << name.erase(0, 1) << std::endl;
                                std::cout << "Всего вопросов: " << all << ". Правильно решенных: " << right << std::endl;
                                break;
                            }

                        }
                    }
                }
                else
                {
                    std::cout << "Файл с названиями не открылся" << std::endl;
                }
                NameTest.close();
            }
            statistics >> line;
        }
    }
    else
    {
        std::cout << "Файл с разделами не открылся" << std::endl;
    }
    statistics.close();
    std::cout << "Процент правильно решённых заданий: " << (allr * 100) / allq << "%. " << std::endl;
    std::cout << "Чтобы вепнуться в профиль нажмиет любую кнопку." << std::endl;
    _getch();
}
void SystemTesting::makeFile()
{

    _mkdir("C:\\ProgramData\\Testing Sestem");
    std::ofstream file("C:\\ProgramData\\Testing Sestem\\answer.txt", std::ios::app);
    std::ofstream file1("C:\\ProgramData\\Testing Sestem\\InterTesting.txt", std::ios::app);
    std::ofstream file2("C:\\ProgramData\\Testing Sestem\\login.txt", std::ios::app);
    std::ofstream file3("C:\\ProgramData\\Testing Sestem\\nameTest.txt", std::ios::app);
    std::ofstream file4("C:\\ProgramData\\Testing Sestem\\password.txt", std::ios::app);
    std::ofstream file5("C:\\ProgramData\\Testing Sestem\\questions.txt", std::ios::app);
    std::ofstream file6("C:\\ProgramData\\Testing Sestem\\setcions.txt", std::ios::app);
    std::ofstream file7("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::app);
    std::ofstream file8("C:\\ProgramData\\Testing Sestem\\static.txt", std::ios::app);
    std::ofstream file9("C:\\ProgramData\\Testing Sestem\\adminData.txt", std::ios::app);
    file.close();
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
}
void Quiz::Test(char id1, char id2, int k)
{
    int right = 0;
    int fals = 0;

    int x = 0;
    system("cls");
    std::ifstream Question;
    Question.open("C:\\ProgramData\\Testing Sestem\\questions.txt");
    std::ifstream Answer;
    Answer.open("C:\\ProgramData\\Testing Sestem\\answer.txt");
    if (Question.is_open())
    {
        std::string line;
        while (std::getline(Question, line))
        {
            if (id1 == line[0] and id2 == line[1])
            {
                questions.push_back(line.erase(0, 2));
            }
        }
    }
    else
    {
        std::cout << "Файл с вопросами  не открылся" << std::endl;
    }
    Question.close();
    if (Answer.is_open())
    {
        std::string line;
        while (std::getline(Answer, line))
        {
            if (id1 == line[0] and id2 == line[1])
            {
                answers.push_back(line.erase(0, 2));
            }
        }
    }
    else
    {
        std::cout << "Файл с ответами  не открылся" << std::endl;
    }
    Answer.close();

    system("cls");
    std::string answ = "";
    std::cin.ignore();
    int count = 0;
   /* if (k!=0)    не работает!!!!!!!
    {
        for (auto ans: useranswer) {
            if (ans== answers[count])
            {
                right++;
                answerRT.push_back(true);
            }
            else
            {
                fals++;
                answerRT.push_back(false);
            }
            count++;
        }      
            
    }*/
    while (count<questions.size())
    {
        std::cout << "Если хотите прервать тестирование нажмите пробел." << std::endl;
        std::cout << "Чтобы продолжить нажмите любую клавишу." << std::endl;
        x = _getch();
        if (x == 32)
        {
            SaveInterTesting(id1, id2);
            break;
        }
        system("cls");
        std::cout << count + 1 << ". " << questions[count] << std::endl;
        std::cout << "Ведите ваш ответ: ";
        std::getline(std::cin, answ);
        if (answ == answers[count])
        {
            std::cout << "Верно." << std::endl;
            Sleep(2000);
            right++;

            answerRT.push_back(true);
            system("cls");
        }
        else
        {
            std::cout << "Неправильно." << std::endl;
            Sleep(2000);
            fals++;
            answerRT.push_back(false);
            system("cls");
        }
        count++;
        useranswer.push_back(answ);
        

    }
    if (x!=32)
    {
        int all = 1;
        double pr;
        try
        {
            if (all==0)
            {
                throw 0;
            }
            else
            {
                 pr = (right * 100) / all;
            }
        }
        catch (int error)
        {
            if (error ==0)
            {
                std::cout << "Деление на ноль.ответы не посчитались." << std::endl;
            }         
        }
        all = right + fals;
        pr = pr / all;
        int score = determineScore(pr);
        system("cls");
        std::cout << "Правильно отвеченно " << right << " из " << all << std::endl;
        std::cout << "Процент правильно решённых вопросов: " << pr << "%" << std::endl;
        std::cout << "Ваша оценка: " << score << std::endl;
        std::cout << "Чтобы сранить ответы нажмите Enter." << std::endl;
        std::cout << "Нажмиет любую клавишу, чтобы вернуться в аккаунт." << std::endl;
        count = _getch();
        saveStatic(id1, id2, all, right);
        if (count == 13)
        {
            ShowAnswers();
        }
    }
    useranswer.clear();
    answerRT.clear();
    answers.clear();
    questions.clear();
}
void SystemTesting::AdminLogin()
{
    system("cls");
    std::string login;
    std::string password;
    std::cout << "Выбран режим администратора." << std::endl;
    Sleep(2000);
    system("cls");
    std::ifstream file("C:\\ProgramData\\Testing Sestem\\adminData.txt");
    if (file.is_open()) {
        if (file.peek() == std::ifstream::traits_type::eof()) {
            std::cout << "Задайте логин: ";
            std::getline(std::cin, login);
            std::cout << "Задайте пароль: ";
            std::getline(std::cin, password);
            std::ofstream file1("C:\\ProgramData\\Testing Sestem\\adminData.txt", std::ios::app);
            if (file1.is_open()) {
                file1 << login << "\n";
                file1 << password << "\n";
            }
            else
            {
                std::cout << "Файл с данными администратора не открылся" << std::endl;
            }
            file1.close();
            showAdminProfil();
        }
        else {
            std::string str;
            std::cout<<"Введите логин: ";
            std::getline(std::cin, str);
            file >> login;
            file >> password;
            if (login==str)
            {
                std::cout << "Введите пароль: ";
                std::getline(std::cin, str);
                if (password==str)
                {
                    showAdminProfil();
                }
                else
                {
                    std::cout << "Пароль не верен." << std::endl;
                    Sleep(1500);
                    AdminLogin();
                }
            }
            else
            {
                std::cout << "Логин не верен." << std::endl;
                Sleep(1500);
                AdminLogin();
            }
        }
    }
    else
    {
        std::cout << "Файл с данными администратора не открылся" << std::endl;
    }
    file.close();
    
}
void SystemTesting::showAdminProfil()
{
    system("cls");
    int chois;
    std::cout << "Выберите функцию." << std::endl;
    std::cout<< std::endl;
    std::cout << "1. Удалить пользователя." << std::endl;
    std::cout << std::endl;
    std::cout << "2. Создать пользователя." << std::endl;
    std::cout << std::endl;
    std::cout << "3. Модифицировать пользователя." << std::endl;
    std::cout << std::endl;
    std::cout << "4. Изменить логин//пароль." << std::endl;
    std::cout << std::endl;
    std::cout << "5. Создать тест." << std::endl;
    std::cout << std::endl;
    std::cout << "6. Просмотр статистики" << std::endl;
    std::cout << std::endl;
    std::cout << "7. Удаление теста." << std::endl;
    std::cout  << std::endl;
    std::cout << "8. Выйти из режима администратора." << std::endl;
    std::cout << std::endl;
    std::cin >> chois;
    switch (chois)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        system("cls");
        quiz.makeQuiz();
        showAdminProfil();
        break;
    case 6:
        
        break;
    case 7:
        system("cls");
        quiz.deleteTest();
        showAdminProfil();
        break;
    case 8:
        system("cls");
        Start();
        break;
    default:
        break;
    }

}
void Quiz::deleteTest()
{
    int count = 1;
    int countname = 1;
    selectingSection();
    std::ifstream Name;
    Name.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
    if (Name.is_open())
    {
        std::string line;
        while (std::getline(Name, line))
        {
            nameQuiz.push_back(line);
        }
    }
    else
    {
        std::cout << "Файл с названиями тестов открылся" << std::endl;
    }
    Name.close();
    for (auto sect : sections)
    {
        std::cout <<count<< "Раздел: "<<sect<<std::endl;
        for (auto name : nameQuiz)
        {
            if ((static_cast<int>(name[0]) - 48) == count)
            {
                std::cout<<countname <<". " << name.erase(0, 1)<<std::endl;
                countname++;
            }          
        }
        countname = 1;
        count++;
    }
    std::cout << "Из какого раздела удалить: " << std::endl;
    std::cin >> count;
    std::cout << "Нормер удаляемого теста: " << std::endl;
    std::cin >> countname;
    nameQuiz.clear();
    int x = 1;
    std::ifstream Namet;
    Namet.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
    if (Namet.is_open())
    {
        std::string line;
        while (std::getline(Namet, line))
        {
            if ((static_cast<int>(line[0]) - 48) == count )
            {
                if (x == countname)
                {
                    continue;
                }
                x++;
            }
            nameQuiz.push_back(line);
        }
    }
    else
    {
        std::cout << "Файл с названиями тестов открылся" << std::endl;
    }
    Namet.close();
    std::ofstream name;
    name.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt");
    if (name.is_open())
    {
        for (auto str : nameQuiz)
        {
            name << str << "\n";
        }
    }
    else
    {
        std::cout << "Файл с названиями открылся" << std::endl;
    }
    name.close();
    std::ifstream ques;
    ques.open("C:\\ProgramData\\Testing Sestem\\questions.txt");
    if (ques.is_open())
    {
        std::string line;
        while (std::getline(ques, line))
        {
            if ((static_cast<int>(line[0]) - 48) == count)
            {
                if ((static_cast<int>(line[1]) - 48) == countname)
                {
                    continue;
                }
            }
            questions.push_back(line);
        }
    }
    else
    {
        std::cout << "Файл с вопросами открылся" << std::endl;
    }
    ques.close();
    std::ofstream q;
    q.open("C:\\ProgramData\\Testing Sestem\\questions.txt");
    if (q.is_open())
    {
        for (auto str : questions)
        {
            q << str << "\n";
        }
    }
    else
    {
        std::cout << "Файл с вопросами открылся" << std::endl;
    }
    q.close();
    std::ifstream answer;
    answer.open("C:\\ProgramData\\Testing Sestem\\answer.txt");
    if (answer.is_open())
    {
        std::string line;
        while (std::getline(answer,line))
        {
            if ((static_cast<int>(line[0]) - 48) == count)
            {
                if ((static_cast<int>(line[1]) - 48) == countname)
                {
                    continue;
                }
            }
            answers.push_back(line);
        }
    }
    else
    {
        std::cout << "Файл с вопросами открылся" << std::endl;
    }
    answer.close();
    std::ofstream a;
    a.open("C:\\ProgramData\\Testing Sestem\\answer.txt");
    if (a.is_open())
    {
        for (auto str : answers)
        {
            a << str << "\n";
        }
    }
    else
    {
        std::cout << "Файл с ответами открылся" << std::endl;
    }
    a.close();
}