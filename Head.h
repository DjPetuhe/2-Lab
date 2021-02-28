#include <iostream>
#include <string>
using namespace std;

/*Шаблонная функция для получения определенного значения.
я оставил её в хедере, потому что в противном случае возникают проблемы с template*/

template <typename T>
void input(string str, T *a)
{
    cout << str;
    cin >> *a;
}

bool first_line(string, int *);