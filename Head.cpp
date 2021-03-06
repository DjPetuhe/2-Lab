#include "Head.h"
using namespace std;

/*Функция, которая читает первые строчки файлов, благодаря
чему можно высчитать кол-во студентов во всех файлах.*/

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
+ стирает это значение из первоначальной строки.*/

string information_to_the_comma(string &all_information)
{
    int len = all_information.find(',');
    string needful_information = all_information.substr(0, len);
    all_information.erase(0, len + 1);
    return needful_information;
}

/*Функция, которая инициализирует массив объектов
класса Student значениями из файлов.*/

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

//Функция которая выводит параметры массива объектов класса "Student".

void object_out(Student *stud, int amount_of_students)
{
    for (int i = 0; i < amount_of_students; i++)
    {
        cout << "#" << setw(3) << left << i + 1 << " Surname: " << setw(26) << left << stud[i].GetName() << " Marks: ";
        for (int j = 0; j < 5; j++)
        {
            cout << setw(4) << left << stud[i].GetNotes()[j];
        }
        cout << "Contract: " << boolalpha << stud[i].GetContract() << endl;
    }
}

//Функция, которая записывает средние баллы в массив.

float *arr_avarage(Student *stud, int amount_of_students)
{
    float *arr = new float[amount_of_students];
    for (int i = 0; i < amount_of_students; i++)
    {
        arr[i] = stud[i].Avarage();
    }
    return arr;
}

//Функция, которая считает количество бюджетников.

int count_budgete(Student *stud, int amount_of_students)
{
    int count = 0;
    for (int i = 0; i < amount_of_students; i++)
    {
        if (!stud[i].GetContract())
        {
            count++;
        }
    }
    return count;
}

//Функция, которая состовляет список студентов со средним баллом.

string *stipendia(Student *stud, float *avarage, int amount_of_students)
{
    string *str = new string[amount_of_students];
    int count = 0;
    for (int i = 0; i < amount_of_students; i++)
    {
        if (!stud[i].GetContract())
        {
            str[count] = stud[i].GetName() + ' ' + to_string(avarage[i]);
            str[count].erase(str[count].length() - 3, str[count].length());
            count++;
        }
    }
    return str;
}

//Функция, которая сортирует список по среднему баллу.

string *rating(string *str, int num)
{
    string temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            string s = str[j].substr(str[j].find_last_of(' ') + 1, (str[j].size() - 1) - str[j].find_last_of(' ') + 1);
            string s1 = str[j + 1].substr(str[j + 1].find_last_of(' ') + 1, (str[j + 1].size() - 1) - str[j + 1].find_last_of(' ') + 1);
            if (stof(s, 0) < stof(s1, 0))
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    return str;
}

//Функция, которая записывает рейтинг в файл.

void do_rating(string *str, int num)
{
    ofstream outFile("rating.csv");
    int persents_40 = ceil((num * 40) / 100);
    for (int i = 0; i < persents_40; i++)
    {
        outFile << str[i] << endl;
    }
    outFile.close();
    string s = str[persents_40 - 1].substr(str[persents_40 - 1].find_last_of(' '), (str[persents_40 - 1].size() - 1) - str[persents_40 - 1].find_last_of(' ') + 1);
    cout << "minimal avarage mark for grant: " << s;
}