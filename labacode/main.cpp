#include <iostream>

using namespace std;

#include "tarif.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №9. Телефонные разговоры\n";
    cout << "Автор: Петров Станислав\n\n";
    tarif* tarifs[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", tarifs, size);
        for (int i = 0; i < size; i++)
        {
            cout << tarifs[i]->duration.second << '\n';
            cout << tarifs[i]->duration.minute << '\n';
            cout << tarifs[i]->duration.hour << '\n';
            cout << tarifs[i]->call_date.day << ' ';
            cout << tarifs[i]->call_date.month << ' ';
            cout << tarifs[i]->call_date.year << '\n';
            cout << tarifs[i]->title << '\n';
            cout << tarifs[i]->price << '\n';
            cout << tarifs[i]->phone_number << '\n';

            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete tarifs[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}