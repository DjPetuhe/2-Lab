#include "Head.h"
using namespace std;

/*Функция, которая читает первые строчки файлов, благодаря
чему можно высчитать кол-во студентов во всех файлах. */

bool first_line(string *file_directories, int *amount_of_students, int amount_of_files)
{
    for (int i = 0; i < amount_of_files; i++)
    {
        fstream filename;
        string number;
        filename.open(file_directories[i]);
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
        }
    }
    return 1;
}

/*Функция, которая возвращает значение строки до запятой
+ стирает это значение из первоначальной строки*/

string information_to_the_comma(string &all_information)
{
    int len = all_information.find(',');
    string needful_information = all_information.substr(0, len);
    all_information.erase(0, len + 1);
    return needful_information;
}

/*Функция, которая инициализирует массив объектов
класса Student значениями из файлов*/

void class_inicial(Student *stud, string *file_directories, int amount_of_files)
{
    fstream filename;
    string number;
    string all_information;
    int amount_of_students = 0;
    bool Contract;
    for (int i = 0; i < amount_of_files; i++)
    {
        filename.open(file_directories[i]);
        getline(filename, number);
        amount_of_students += stoi(number);
        for (int j = amount_of_students - stoi(number); j < amount_of_students; j++)
        {
            int marks[5];
            getline(filename, all_information);
            string name = information_to_the_comma(all_information);
            stud[j].SetName(name);
            for (int k = 0; k < 5; k++)
            {
                marks[k] = stoi(information_to_the_comma(all_information));
            }
            stud[j].SetNotes(marks);
            if (all_information == "TRUE")
            {
                Contract = true;
            }
            else
            {
                Contract = false;
            }
            stud[j].SetContract(Contract);
        }
        filename.close();
    }
   
}

// Функция которая выводит параметры массива объектов student.

void object_out(Student* stud, int amount_of_students)
{
    for (int i = 0; i < amount_of_students; i++)
    {
        cout << "#" <<setw(3)<<left<< i+1 << " Surname: " <<setw(26)<<left<<stud[i].GetName() << " Marks: ";
        for (int j = 0; j < 5; j++)
        {
            cout <<setw(4)<<left<<stud[i].GetNotes()[j];
        }
        cout << "Contract: " << stud[i].GetContract() << endl;
    }
}