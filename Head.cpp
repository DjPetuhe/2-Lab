#include <iostream>
#include <string>
#include <fstream>
#include "Head.h"
using namespace std;

/*Функция, которая читает первые строчки файлов, благодаря
чему можно высчитать кол-во студентов во всех файлах. */

bool first_line(string file_directory, int *amount_of_students)
{
    fstream filename;
    string number;
    filename.open(file_directory);
    if (!filename.is_open())
    {
        cout << "Cant open the file";
        return 0;
    }
    else
    {
        getline(filename, number);
        *amount_of_students += stoi(number);
        filename.close();
        return 1;
    }
}