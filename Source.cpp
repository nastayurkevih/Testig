#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
//заедает при выборе, выход из программы
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
    void Test(char id1, char id2);
    int determineScore(double pr);
    void ShowAnswers();
    void SaveInterTesting(char id1, char id2);
    void Selogin(std::string login);
    void ShowfinishTest();
    void  finishTest();
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
    void Start();//начала прокраммы и выбор режима администратора или тестируемого
    void UserStart();//
    void UserLog();//
    bool PersonInFile(std::string login, std::string password);//
    void AdminLogin();
    void RegistrationUsers();
    bool ThereIsLog(std::string login);
    bool ThereIsPass(std::string password);
    void Fillfile();
    void ShowProfile();
private:
    User user;
    Quiz quiz;
    int r;
};



//После входа гость имеет возможность просмотреть свои предыдущие результаты тестирования, сдать новое тестирование.
//Студент имеет возможность прервать тестирование и продолжить его тогда,
//когда ему это будет удобно.
//Пароли и логины гостей хранятся в зашифрованном виде.



//Описание режима работа для Администратора(в дальнейшем админ)
//В системе может быть только один админ, логин и пароль админа задается
//при первом входе в программу.
//В дальнейшем пароль и логин можно изменить(но данную возможность имеет
//	только админ).
//	Пароль и логин необходимо хранить только в зашифрованном виде.
//	При работе с системой админ имеет следующие возможности :
//• Управление пользователями – создание, удаление, модификация пользователей.
//• Просмотр статистики – просмотр результатов тестирования в общем
//по категориям, по конкретным тестам, по конкретным пользователям.
//Результаты просмотра статистики можно вывести в файл.
//• Управление тестированием – админ имеет возможность добавлять категории, тесты, вопросы к тестам, задавать правильные и неправильные ответы, импортировать и экспортировать категории и тесты с
//вопросами из файла(и в файл).



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SystemTesting test;
    test.Start();
    Quiz quiz;
   /* int x;
    x = _getch();
    std::cout << x;*/


};

void SystemTesting::Start()
{
    system("cls");
    int c = 119;//вверх 119 ввниз 115
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
    }
    system("cls");
    if (k == 115)
    {
        UserStart();
    }
    AdminLogin();
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
    std::ifstream filelogin;
    filelogin.open("C:\\Users\\Анна\\Desktop\\work\\login.txt");
    if (filelogin.is_open())
    {
        std::string line;
        while (!filelogin.eof())
        {
            filelogin >> line;
            countlog++;
            if (login == line)
            {
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
    filepass.open("C:\\Users\\Анна\\Desktop\\work\\password.txt");
    if (filepass.is_open())
    {
        std::string line;
        while (!filepass.eof())
        {
            filepass >> line;
            countpass++;
            if (password == line)
            {
                break;
            }
        }
    }
    else
    {
        std::cout << "Файл с паролями не открылся" << std::endl;
    }
    if (countlog == countpass and countlog > 0)
    {
        return false;
    }
    filepass.close();
    return true;
}
bool SystemTesting::ThereIsLog(std::string login)
{
    std::ifstream filelogin;
    filelogin.open("C:\\Users\\Анна\\Desktop\\work\\login.txt");
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
    filepass.open("C:\\Users\\Анна\\Desktop\\work\\password.txt");
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
    fileUser.open("C:\\Users\\Анна\\Desktop\\work\\userData.txt", std::ios::app);
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
    filelogin.open("C:\\Users\\Анна\\Desktop\\work\\login.txt", std::ios::app);
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
    filepass.open("C:\\Users\\Анна\\Desktop\\work\\password.txt", std::ios::app);
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
    filelogin.open("C:\\Users\\Анна\\Desktop\\work\\login.txt");
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
    Sections.open("C:\\Users\\Анна\\Desktop\\work\\sections.txt", std::ios::app);
    if (Sections.is_open())
    {
        std::string line;
        Sections >> line;

        while (!Sections.eof())
        {
            sections.push_back(line);
            Sections >> line;
        }
    }
    else
    {
        std::cout << "Файл с разделами не открылся" << std::endl;
    }
}
void Quiz::AddSect(std::string newSect)
{
    std::ofstream Sections;
    Sections.open("C:\\Users\\Анна\\Desktop\\work\\sections.txt", std::ios::app);
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
    Name.open("C:\\Users\\Анна\\Desktop\\work\\nameQuiz.txt", std::ios::app);
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
    Questions.open("C:\\Users\\Анна\\Desktop\\work\\questions.txt", std::ios::app);
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
    Questions.open("C:\\Users\\Анна\\Desktop\\work\\answer.txt", std::ios::app);
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
    char choise;
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
    NameTest.open("C:\\Users\\Анна\\Desktop\\work\\nameQuiz.txt");
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
    NameTest.open("C:\\Users\\Анна\\Desktop\\work\\nameQuiz.txt");
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
        std::cout << std::endl;
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
    }
    std::cout << "Нажмиет любую клавишу, чтобы вернуться в аккаунт." << std::endl;
    count = _getch();
}
void Quiz::SaveInterTesting(char id1, char id2)
{
    std::ofstream filelogin;
    filelogin.open("C:\\Users\\Анна\\Desktop\\work\\InterTesting.txt", std::ios::app);
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
    std::vector<std::string> id1;
    std::vector<std::string> id2;
    std::ifstream Sections;
    std::ifstream NameTest;
    NameTest.open("C:\\Users\\Анна\\Desktop\\work\\nameQuiz.txt");
    Sections.open("C:\\Users\\Анна\\Desktop\\work\\InterTesting.txt");
    if (Sections.is_open())
    {
        std::string line;
        Sections >> line;
        std::cout << line << std::endl;
        while (!Sections.eof())
        {
            if (line==login)
            {
                count++;
                Sections >> line;
                std::cout << line << std::endl;
                id1.push_back(line);
                Sections >> line;
                std::cout << line << std::endl;
                id2.push_back(line);
                Sections >> line;
                std::cout << line << std::endl;
                while (line!="0all0")
                {
                    useranswer.push_back(line);
                    Sections >> line;
                    std::cout << line << std::endl;

                }
                selectingSection();
                std::cout<<count << ". Раздел: " << sections[stoi(id1.back())]<<std::endl;
                int countname = 0;
                if (NameTest.is_open())
                {
                    std::string name;
                    while (std::getline(NameTest, name))
                    {
                        
                        if ((stoi(id1.back()) == static_cast<int>(name[0])) )
                        {
                            countname++;
                            if ((stoi(id2.back()) == countname))
                            {
                                std::cout << name << std::endl;
                                break;
                            }
                            
                        }
                    }
                }
                else
                {
                    std::cout << "Файл с названиями не открылся" << std::endl;
                }
            }
            Sections >> line;
        }
    }
    else
    {
        std::cout << "Файл с разделами не открылся" << std::endl;
    }
    Sections.close();
    NameTest.close();
    if (count==0)
    {
        std::cout << "У вас нет незавершённых тестов." << std::endl;
    }
    else
    {
        std::cout << "Какой тест продолжить решать? ";
        int chois2;
        std::cin >> chois2;
        system("cls");
        Test(id1[chois2 - 1][0], id2[chois2 - 1][0]);
    }
}


void SystemTesting::AdminLogin()
{
}

void SystemTesting::ShowProfile()
{
    int chois;
    system("cls");
    std::ifstream fileUser;
    fileUser.open("C:\\Users\\Анна\\Desktop\\work\\userData.txt", std::ios::app);
    if (fileUser.is_open())
    {
        std::cout << "Информация о пользователи." << std::endl;
        int id = user.GetId();
        id = id * 5;
        if (id > -1)
        {
            std::string line;
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
        std::cout << std::endl;
        std::cout << "Выбрать тестирование. Нажмите Enter." << std::endl;
        std::cout << "Выйти из аккаунта. Нажмите пробел." << std::endl;
        std::cout << "Дорешать неаконченные тесты. нажмите q." << std::endl;
        quiz.Selogin(user.Getlogin());
        chois = _getch();
        if (chois==13)
        {
          
            quiz.choiceTest();
            system("cls");
            ShowProfile();
        }
        else if (chois==32)
        {
            Start();
        }
        else if(chois == 113)
        {
            system("cls");
            quiz.ShowfinishTest();
            system("cls");
            ShowProfile();
        }
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

void Quiz::Test(char id1, char id2)
{
    
    int right = 0;
    int fals = 0;
    int count = 0;
    int x = 0;
    system("cls");
    std::ifstream Question;
    Question.open("C:\\Users\\Анна\\Desktop\\work\\questions.txt");
    std::ifstream Answer;
    Answer.open("C:\\Users\\Анна\\Desktop\\work\\answer.txt");
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
    std::string answ;
    std::cin.ignore();
    for (auto ques: questions)
    {
        system("cls");
        std::cout << count + 1 <<". " << ques << std::endl;
        std::cout << "Ведите ваш ответ: ";
        std::getline(std::cin, answ);
        if (answ==answers[count])
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
        std::cout << "Если хотите прервать тестирование нажмите пробел." << std::endl;
        std::cout << "Чтобы продолжить нажмите любую клавишу." << std::endl;
        x = _getch();
     
        if (x==32)
        {
            SaveInterTesting(id1,id2);
            break;
        }
        else
        {
            continue;
        }
      
    }
    if (x!=13)
    {
        int all = right + fals;
        double pr = (right * 100) / all;
        int score = determineScore(pr);
        std::cout << "Правильно отвеченно " << right << " из " << all << std::endl;
        std::cout << "Процент правильно решённых вопросов: " << pr << "%" << std::endl;
        std::cout << "Ваша оценка: " << score << std::endl;
        std::cout << "Чтобы сранить ответы нажмите Enter." << std::endl;
        std::cout << "Нажмиет любую клавишу, чтобы вернуться в аккаунт." << std::endl;
        count = _getch();
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
