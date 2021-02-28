#include <iostream>
#include <string>
#include <fstream>
#include "Head.h"

class Student
{
private:
    string name;
    int notes[4];
    bool Contract;

public:
    void SetName(string str);
    void SetNotes(int *marks);
    void SetContract(bool Contr);
    double Avarage();
};