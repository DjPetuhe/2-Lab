#include <iostream>
#include <string>
#include <fstream>
#pragma once
#include "StudentClass.h"
#include <iomanip>
using namespace std;

/*Шаблонная функция для получения определенного значения.
Я оставил её в хедере, потому что в противном случае возникают проблемы с template*/

template <typename T>
void input(string str, T *a)
{
    cout << str;
    cin >> *a;
}

bool first_line(string *, int *, int);

void class_inicial(Student *, string *, int);

string information_to_the_comma(string *);

void object_out(Student*, int);

float* arr_avarage(Student* , int );

int count_budgete(Student* , int);

string* stipendia(Student* stud, float* avarage, int amount_of_students);

string* rating(string* str, int num);

void do_rating(string* str, int num);

