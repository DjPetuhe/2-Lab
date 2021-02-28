#include <iostream>
#include <string>
#include <fstream>
#include "Head.h"
#include "StudentClass.h"
using namespace std;

int main()
{
    //Ввод кол-ва файлов, и проврека на то, чтобы значения были приемлимыми.
    int amount_of_files;
    input("How many files do you want to work with?: ", &amount_of_files);
    if (amount_of_files <= 0 || amount_of_files >= 100)
    {
        cout << "Wrong value.";
        return 0;
    }
    //Ввод директории файлов в массив стрингов.
    string file_directories[amount_of_files];
    for (int i = 0; i < amount_of_files; i++)
    {
        input("Enter the file directory (or file name): ", &file_directories[i]);
    }
    //Нахождение кол-ва всех студентов.
    int amount_of_students = 0;
    for (int i = 0; i < amount_of_files; i++)
    {
        if (!first_line(file_directories[i], &amount_of_students))
        {
            return 0;
        }
    }
    return 0;
}