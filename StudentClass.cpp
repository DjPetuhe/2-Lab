#include "StudentClass.h"

//Сеттеры класса Student

void Student::SetName(string str)
{
    this->name = str; //Программа почему-то прекращает свое выполнение тут. я пока не разобрался в чем проблема.
}

void Student::SetNotes(int *marks)
{
    for (int i = 0; i < 5; i++)
    {
        this->notes[i] = marks[i];
    }
}

void Student::SetContract(bool Contr)
{
    this->Contract = Contr;
}

//Геттеры класса Student

string Student::GetName()
{
    return this->name;
}

int *Student::GetNotes()
{
    return this->notes;
}

bool Student::GetContract()
{
    return this->Contract;
}

// Остальные методы класса Student:

double Student::Avarage()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += this->notes[i];
    }
    return sum / 5;
}