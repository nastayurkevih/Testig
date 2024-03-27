#include "Quiz.h"

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
    if (id1 == 0)
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
            std::cout << "Верный ответ." << answers[count] << std::endl;
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
        filelogin << login << " " << id1 << " " << id2 << " ";
        for (auto ans : useranswer)
        {
            filelogin << ans << " ";
        }
        filelogin << "0all0" << "\n";
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
            if (line == login)
            {
                count++;
                Sections >> line;
                id1.push_back(line);
                Sections >> line;
                id2.push_back(line);
                Sections >> line;
                while (line != "0all0")
                {
                    useranswer.push_back(line);
                    Sections >> line;
                    k++;

                }
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

    if (count == 0)
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
        Test(id1[chois2 - 1][0], id2[chois2 - 1][0], k);
        deleteFinishTest(id1[chois2 - 1][0], id2[chois2 - 1][0]);
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
    InterTesting.open("C:\\ProgramData\\Testing Sestem\\InterTesting.txt", std::ios::trunc);
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
    //////////////////
    if (k != 0)
    {
        for (auto ans : useranswer) {
            if (ans == answers[count])
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

    }
    //////////////////
    while (count < questions.size())
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
    if (x != 32)
    {
        int all = 1;
        double pr;
        try
        {
            if (all == 0)
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
            if (error == 0)
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
        std::cout << count << "Раздел: " << sect << std::endl;
        for (auto name : nameQuiz)
        {
            if ((static_cast<int>(name[0]) - 48) == count)
            {
                std::cout << countname << ". " << name.erase(0, 1) << std::endl;
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
            if ((static_cast<int>(line[0]) - 48) == count)
            {
                if (x == countname)
                {
                    continue;
                }
                else
                {
                    nameQuiz.push_back(line);
                }
                x++;
            }
            else
            {
                nameQuiz.push_back(line);
            }
        }
    }
    else
    {
        std::cout << "Файл с названиями тестов открылся" << std::endl;
    }
    Namet.close();
    std::ofstream name;
    name.open("C:\\ProgramData\\Testing Sestem\\nameTest.txt", std::ios::trunc);
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
    questions.clear();
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
    q.open("C:\\ProgramData\\Testing Sestem\\questions.txt", std::ios::trunc);
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
    answers.clear();
    answer.open("C:\\ProgramData\\Testing Sestem\\answer.txt");
    if (answer.is_open())
    {
        std::string line;
        while (std::getline(answer, line))
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
    a.open("C:\\ProgramData\\Testing Sestem\\answer.txt", std::ios::trunc);
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
void Quiz::showStatistic()
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
            std::cout << count << ". Раздел: " << sections[stoi(id1.back()) - 1] << std::endl;
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