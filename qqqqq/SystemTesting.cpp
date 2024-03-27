#include "SystemTesting.h"

int SystemTesting::Start()
{
    makeFile();
    system("cls");
    int c = 119;
    int k;
    std::cout << "������ ������������.\n �������� ����� �����������." << std::endl;
    std::cout << "(�������� �� ��������� ��������� ���������)" << std::endl;
    Sleep(4000);
    while (c != 13)
    {
        if (c == 119)
        {
            system("cls");
            std::cout << "-->����� ��� �������������" << std::endl;
            std::cout << "\t����� ��� �����������" << std::endl;
            std::cout << "(����� ��������� ����� ������� ������)" << std::endl;
            k = c;
            c = _getch();
        }
        else if (c == 115)
        {
            system("cls");
            std::cout << "\t����� ��� �������������" << std::endl;
            std::cout << "-->����� ��� �����������" << std::endl;
            std::cout << "(����� ��������� ����� ������� ������)" << std::endl;
            k = c;
            k = c;
            c = _getch();
        }
        else if (c == 32)
        {
            return 0;
            system("cls");
        }
        else
        {
            system("cls");
            std::cout << "-->����� ��� �������������" << std::endl;
            std::cout << "\t����� ��� �����������" << std::endl;
            std::cout << "(����� ��������� ����� ������� ������)" << std::endl;
            k = c;
            k = c;
            c = _getch();
        }
    }
    system("cls");
    if (k == 115)
    {
        UserStart();
    }
    else if (k == 119)
    {
        AdminLogin();
    }
}
void SystemTesting::UserStart()
{
    std::cout << "������ ����� ������������" << std::endl;
    int c = 119;
    int k;
    Sleep(2000);
    while (c != 13)
    {
        if (c == 119)
        {
            system("cls");
            std::cout << "-->����� � �������" << std::endl;
            std::cout << "\t������������������" << std::endl;
            k = c;
            c = _getch();
        }
        else if (c == 115)
        {
            system("cls");
            std::cout << "\t����� � �������" << std::endl;
            std::cout << "-->������������������" << std::endl;
            k = c;
            c = _getch();
        }
        else
        {
            system("cls");
            std::cout << "-->����� � �������" << std::endl;
            std::cout << "\t������������������" << std::endl;
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
    std::cout << "������ �����: ";
    getline(std::cin, login);
    std::cout << "������ ������: ";
    getline(std::cin, password);
    if (!PersonInFile(login, password))
    {
        std::cout << "���� ������� ��������" << std::endl;
        Sleep(2000);
        system("cls");
        user.SetLog(login);
        user.SetPass(password);
        ShowProfile();
    }
    else
    {
        std::cout << "������������ �� ������.\n ���������� ��� ���." << std::endl;
        UserLog();
    }
}
bool SystemTesting::PersonInFile(std::string login, std::string password)
{
    int countlog = 0;
    int countpass = 0;
    bool flaglog = true;
    bool flagpass = true;
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
        std::cout << "���� � �������� �� ��������" << std::endl;
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
        std::cout << "���� � �������� �� ��������" << std::endl;
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
        std::cout << "���� � �������� �� ��������" << std::endl;
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
        std::cout << "���� � �������� �� ��������" << std::endl;
    }
    filepass.close();
    return true;
}

void SystemTesting::RegistrationUsers()
{
    system("cls");
    std::string login;
    std::string password;
    std::cout << "���������� �����: ";
    std::cin.ignore();
    getline(std::cin, login);
    std::cout << "���������� ������: ";
    getline(std::cin, password);
    if (!ThereIsLog(login))
    {
        std::cout << "������������ � ����� ������� ��� ����������.\n���������� ����� �����." << std::endl;
        RegistrationUsers();
    }
    else if (!ThereIsPass(password))
    {
        std::cout << "������������ � ����� ������� ��� ����������.\n���������� ����� ������." << std::endl;
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
        char* phone = new char[250] {};
        std::cout << "������� ���: " << std::endl;
        //std::cin.ignore();
        std::cin >> name;
        user.SetName(name);
        std::cout << "������� ��������: " << std::endl;
        std::cin.ignore();
        std::cin >> middleName;
        user.SetMiddleName(middleName);
        std::cout << "������� �������: " << std::endl;
        std::cin.ignore();
        std::cin >> Surename;
        user.SetSurename(Surename);
        std::cout << "������� ������: " << std::endl;
        std::cin.ignore();
        std::cin >> Adress;
        user.SetAdress(Adress);
        std::cout << "����� ��������: " << std::endl;
        std::cin >> phone;
        user.SetPhonee(phone);
        user.Fillfile();
        std::cout << "����������� ������ �������." << std::endl;
        ShowProfile();
    }
}

void SystemTesting::ShowProfile()
{
    int chois = 0;
    system("cls");
    std::ifstream fileUser;
    fileUser.open("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::app);
    if (fileUser.is_open())
    {
        std::cout << "���������� � ������������." << std::endl;
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
                    std::cout << "��� ������������:" << line << " ";
                    fileUser >> line;
                    std::cout << line << " ";
                    fileUser >> line;
                    std::cout << line << " " << std::endl;
                    fileUser >> line;
                    std::cout << std::endl;
                    std::cout << "������ ������������:" << line << std::endl;
                    fileUser >> line;
                    std::cout << std::endl;
                    std::cout << "������� ������������:" << line << std::endl;
                    break;
                }
                count++;
            }
        }
        else
        {
            std::cout << "������! id �� ������.";
        }
        std::cout << std::endl;
        std::cout << "����� ����������� ���������� ������� s." << std::endl;
        std::cout << std::endl;
        std::cout << "�������� ������������ �����. ������� q." << std::endl;
        std::cout << std::endl;
        std::cout << "������� ������������. ������� Enter." << std::endl;
        std::cout << std::endl;
        std::cout << "����� �� ��������. ������� ������." << std::endl;
        std::cout << std::endl;
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
        std::cout << "���� ��� ������ ������ �� ��������" << std::endl;
    }
    fileUser.close();

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

void SystemTesting::AdminLogin()
{
    system("cls");
    std::string login;
    std::string password;
    std::cout << "������ ����� ��������������." << std::endl;
    Sleep(2000);
    system("cls");
    std::ifstream file("C:\\ProgramData\\Testing Sestem\\adminData.txt");
    if (file.is_open()) {
        if (file.peek() == std::ifstream::traits_type::eof()) {
            std::cout << "������� �����: ";
            std::getline(std::cin, login);
            std::cout << "������� ������: ";
            std::getline(std::cin, password);
            std::ofstream file1("C:\\ProgramData\\Testing Sestem\\adminData.txt", std::ios::app);
            if (file1.is_open()) {
                file1 << login << "\n";
                file1 << password << "\n";
            }
            else
            {
                std::cout << "���� � ������� �������������� �� ��������" << std::endl;
            }
            file1.close();
            showAdminProfil();
        }
        else {
            std::string str;
            std::cout << "������� �����: ";
            std::getline(std::cin, str);
            file >> login;
            file >> password;
            if (login == str)
            {
                std::cout << "������� ������: ";
                std::getline(std::cin, str);
                if (password == str)
                {
                    showAdminProfil();
                }
                else
                {
                    std::cout << "������ �� �����." << std::endl;
                    Sleep(1500);
                    AdminLogin();
                }
            }
            else
            {
                std::cout << "����� �� �����." << std::endl;
                Sleep(1500);
                AdminLogin();
            }
        }
    }
    else
    {
        std::cout << "���� � ������� �������������� �� ��������" << std::endl;
    }
    file.close();

}

void SystemTesting::DeleteUser(int k)
{
    int count = 1;
    std::ifstream file;
    std::vector<std::string> users;
    std::vector<std::string> logins;
    std::vector<std::string> passwords;
    file.open("C:\\ProgramData\\Testing Sestem\\userData.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << count << ". " << line << std::endl;
            users.push_back(line);
            count++;
        }
    }
    else
    {
        std::cout << "���� � ������� ������������ �� ��������" << std::endl;
    }
    file.close();
    if (k == 0)
    {
        std::cout << "������ ������������ �������: " << std::endl;
        std::cin >> count;
    }
    else
    {
        count = k;
    }
    users.erase(users.begin() + count - 1);
    std::ofstream filein;
    filein.open("C:\\ProgramData\\Testing Sestem\\userData.txt", std::ios::trunc);
    if (filein.is_open())
    {
        for (auto str : users)
        {
            filein << str << "\n";
        }
    }
    else
    {
        std::cout << "���� � ���������� ��������" << std::endl;
    }
    filein.close();
    int countlog = 1;
    std::ifstream l;
    l.open("C:\\ProgramData\\Testing Sestem\\login.txt");
    if (l.is_open())
    {
        std::string line;
        while (std::getline(l, line))
        {
            if (countlog != count)
            {
                logins.push_back(line);
            }
        }
    }
    else
    {
        std::cout << "���� � �������� ��������" << std::endl;
    }
    l.close();

    std::ofstream login;
    login.open("C:\\ProgramData\\Testing Sestem\\login.txt", std::ios::trunc);
    if (login.is_open())
    {
        for (auto str : logins)
        {
            login << str << "\n";
        }
    }
    else
    {
        std::cout << "���� � �������� ��������" << std::endl;
    }
    login.close();


    int countpass = 1;
    std::ifstream p;
    p.open("C:\\ProgramData\\Testing Sestem\\password.txt");
    if (p.is_open())
    {
        std::string line;
        while (std::getline(p, line))
        {
            if (countlog != count)
            {
                passwords.push_back(line);
            }
        }
    }
    else
    {
        std::cout << "���� � �������� ��������" << std::endl;
    }
    p.close();

    std::ofstream pass;
    pass.open("C:\\ProgramData\\Testing Sestem\\password.txt", std::ios::trunc);
    if (pass.is_open())
    {
        for (auto str : passwords)
        {
            pass << str << "\n";
        }
    }
    else
    {
        std::cout << "���� � �������� ��������" << std::endl;
    }
    pass.close();

}
void SystemTesting::showAdminProfil()
{
    system("cls");
    int chois;
    std::cout << "�������� �������." << std::endl;
    std::cout << std::endl;
    std::cout << "1. ������� ������������." << std::endl;
    std::cout << std::endl;
    std::cout << "2. �������������� ������������." << std::endl;
    std::cout << std::endl;
    std::cout << "3. ������� ����." << std::endl;
    std::cout << std::endl;
    std::cout << "4. �������� ����������" << std::endl;
    std::cout << std::endl;
    std::cout << "5. �������� �����." << std::endl;
    std::cout << std::endl;
    std::cout << "6. ����� �� ������ ��������������." << std::endl;
    std::cout << std::endl;
    std::cin >> chois;
    switch (chois)
    {
    case 1:
        system("cls");
        DeleteUser();
        showAdminProfil();
        break;
    case 2:
        system("cls");
        ChangeUser();
        showAdminProfil();
        break;
    case 3:
        system("cls");
        quiz.makeQuiz();
        showAdminProfil();
        break;
    case 4:
        system("cls");
        quiz.showStatistic();
        showAdminProfil();
        break;
    case 5:
        system("cls");
        quiz.deleteTest();
        showAdminProfil();
        break;
    case 6:
        system("cls");
        Start();
        break;
    default:
        break;
    }

}

void SystemTesting::ChangeUser()
{
    std::ifstream file;
    std::vector<std::string> dataus;
    int count = 1;
    int countuser = 1;
    file.open("C:\\ProgramData\\Testing Sestem\\userData.txt");
    if (file.is_open())
    {
        std::string line;
        file >> line;
        while (!file.eof())
        {

            std::cout << count << ". " << line << " ";
            file >> line;
            std::cout << line << " ";
            file >> line;
            std::cout << line << std::endl;
            file >> line;
            file >> line;
            file >> line;
            count++;
        }
    }
    else

    {
        std::cout << "���� � ������� ������������ �� ��������" << std::endl;
    }
    file.close();
    std::cout << "������ ������������ ��������: " << std::endl;
    std::cin >> count;
    system("cls");
    file.open("C:\\ProgramData\\Testing Sestem\\userData.txt");
    if (file.is_open())
    {
        std::string line;
        file >> line;
        while (!file.eof())
        {
            if (countuser == count)
            {
                dataus.push_back(line);
                file >> line;
                dataus.push_back(line);
                file >> line;
                dataus.push_back(line);
                file >> line;
                dataus.push_back(line);
                file >> line;
                dataus.push_back(line);
                break;
            }
            else
            {
                file >> line;
                file >> line;
                file >> line;
                file >> line;
            }
            countuser++;
            file >> line;
        }
    }
    else

    {
        std::cout << "���� � ������� ������������ �� ��������" << std::endl;
    }
    file.close();
    std::ifstream file1;
    countuser = 1;
    file1.open("C:\\ProgramData\\Testing Sestem\\login.txt");
    if (file1.is_open())
    {
        std::string line;
        file1 >> line;
        while (!file1.eof())
        {
            if (count == countuser)
            {
                dataus.push_back(line);
            }
            countuser++;
            file1 >> line;
        }
    }
    else
    {
        std::cout << "���� � ��������  �� ��������" << std::endl;
    }
    file1.close();
    countuser = 1;
    file.open("C:\\ProgramData\\Testing Sestem\\password.txt");
    if (file.is_open())
    {
        std::string line;
        file >> line;
        while (!file.eof())
        {

            if (count == countuser)
            {
                dataus.push_back(line);
            }
            countuser++;
            file >> line;
        }
    }
    else
    {
        std::cout << "���� � ��������  �� ��������" << std::endl;
    }
    file.close();
    DeleteUser(count);
    system("cls");
    std::cout << "��� �������� � ����������?" << std::endl;
    std::cout << "1. ���" << std::endl;
    std::cout << "2. ������" << std::endl;
    std::cout << "3. ����� ��������" << std::endl;
    std::cout << "4. ����� " << std::endl;
    std::cout << "5. ������" << std::endl;
    int chois;
    std::cin >> chois;
    std::string name;
    std::string middleName;
    std::string surname;
    std::string address;
    std::string phone;
    std::string log;
    std::string pass;
    switch (chois)
    {
    case 1:
        std::cout << "������ ����� ���" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        dataus[0] = name;
        std::cout << "������ ����� �������" << std::endl;
        std::getline(std::cin, middleName);
        dataus[1] = middleName;
        std::cout << "������ ����� �������" << std::endl;
        std::getline(std::cin, surname);
        dataus[2] = surname;
        break;
    case 2:
        std::cout << "������ ����� ������" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, address);
        dataus[3] = address;
        break;
    case 3:
        std::cout << "������ ����� ����� ��������" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, phone);
        dataus[4] = phone;
        break;
    case 4:
        std::cout << "������ ����� �����" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, log);
        dataus[5] = log;
        break;
    case 5:
        std::cout << "������ ����� ������" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, pass);
        dataus[6] = log;
        break;
    default:
        break;
    }
    user.SetName(const_cast<char*>(dataus[0].data()));
    user.SetMiddleName(const_cast<char*>(dataus[1].data()));
    user.SetSurename(const_cast<char*>(dataus[2].data()));
    user.SetAdress(const_cast<char*>(dataus[3].data()));
    user.SetPhonee(const_cast<char*>(dataus[4].data()));
    user.SetLog(const_cast<char*>(dataus[5].data()));
    user.SetPass(const_cast<char*>(dataus[6].data()));;
    user.Fillfile();
    user.LogFill();
    user.PassFill();
    std::cout << "������ ����������� ��������." << std::endl;
    std::cout << "����� ��������� � ������� ������� ����� ������." << std::endl;
    _getch();
}