#include <iostream>
#include <string>
#include <fstream>
#pragma once
using namespace std;

/* Класс "Студент", в котором будут приватно хранится данные
про имя студента, его оценки и то, является ли он контрактником.
Методы этого класса позвляють получать доступ к этим данным,
+ узнат средний балл */

class Student
{
private:
    string name;
    int notes[4];
    bool Contract;

public:
    Student();
    void SetName(string str);
    void SetNotes(int *marks);
    void SetContract(bool Contr);
    string GetName();
    int *GetNotes();
    bool GetContract();
    double Avarage();
};