#include "StudentClass.h"

void Student::SetName(string str)
{
    this->name = str;
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

double Student::Avarage()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += this->notes[i];
    }
    return sum / 5;
}