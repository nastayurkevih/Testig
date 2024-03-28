#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <fstream>
#include "SystemTesting.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SystemTesting test;
    test.Start();

};
