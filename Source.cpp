#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>

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
    int determineScore(int r, int f);

private:
    std::vector<std::string> sections;
    std::vector<std::string> nameQuiz;
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    int countQues;
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
//После сдачи теста гость видит результат тестирования, количество правильно
//отвеченных вопросов, процент правильных ответов и полученную оценку.
//Студент имеет возможность прервать тестирование и продолжить его тогда,
//когда ему это будет удобно.
//Оценивание нужно вести на основании 12 - балльной системы, привязанной
//к количеству вопросов теста.
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
    Quiz quiz;
    quiz.choiceTest();

};

void SystemTesting::Start()
{
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
void Quiz::selectingSection()
{
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

void SystemTesting::AdminLogin()
{
}

void SystemTesting::ShowProfile()
{
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
    }
    else
    {
        std::cout << "Файл для записи данных не открылся" << std::endl;
    }
    fileUser.close();

}

void Quiz::choiceTest()
{
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
                std::cout << count << " " << line.erase(0, 1) << std::endl;
                count++;
            }
        }
    }
    else
    {
        std::cout << "Файл с названиями не открылся" << std::endl;
    }
    NameTest.close();
    std::cout << "Ваш выбор: ";
    char chois2;
    std::cin >> chois2;
    system("cls");
    Test(chois, chois2);
}
void Quiz::Test(char id1, char id2)
{
    int right = 0;
    int fals = 0;
    system("cls");
    std::ifstream Question;
    Question.open("C:\\Users\\Анна\\Desktop\\work\\question.txt");
    std::ifstream Answer;
    Answer.open("C:\\Users\\Анна\\Desktop\\work\\answer.txt");
    int count = 1;
    if (Question.is_open() and Answer.is_open())
    {
        std::string line;
        std::string answer;
        std::string line1;
        while (std::getline(Question, line) and std::getline(Answer, line1))
        {
            if (id1 == line[0] and id2 == line[1] and id1 == line1[0] and id2 == line1[1])
            {
                std::cout << count << " " << line.erase(0, 2) << std::endl;
                count++;
                std::cout << "Ваш ответ: " << std::endl;
                std::cin >> answer;
                if (answer == line1)
                {
                    std::cout << "Верно. " << std::endl;
                    right++;
                }
                else
                {
                    std::cout << "Неправильно.  " << std::endl;
                    fals++;
                }
                system("cls");
            }
        }
    }
    else
    {
        std::cout << "Файл с названиями не открылся" << std::endl;
    }
    Question.close();
    Answer.close();
    int score = determineScore(right, fals);
    std::cout << "Ваша оценка: " << score << std::endl;
}
int Quiz::determineScore(int r, int f)
{
    int all = r + f;
    if (all == r)
    {
        return 12;
    }
    else if (all * 0.95 >= r)
    {
        return 11;
    }
    else if (all * 0.9 >= r)
    {
        return 10;
    }
    else if (all * 0.80 >= r)
    {
        return 9;
    }
    else if (all * 0.75 >= r)
    {
        return 8;
    }
    else if (all * 0.70 >= r)
    {
        return 7;
    }
    else if (all * 0.6 >= r)
    {
        return 6;
    }
    else if (all * 0.55 >= r)
    {
        return 5;
    }
    else if (all * 0.50 >= r)
    {
        return 4;
    }
    else if (all * 0.40 >= r)
    {
        return 3;
    }
    else if (all * 0.30 >= r)
    {
        return 2;
    }
    else if (all * 0.20 >= r)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}