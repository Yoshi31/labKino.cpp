#include <iostream>
#include <string>
#include <fstream>
#include "Film.h"
#include "Function.h"
using namespace std;

int main(int argc, char* argv[])
{
    bool work = true;
    setlocale(LC_CTYPE, "Russian");
    if (argc != 2)
    {
        cout << "Неверное колличество параметров" << endl;
        return 1;
    }
    char choice;
    cout << "Добро пожаловать в кинотеатр!!!" << endl << "Выберите действие" << endl;
    while (work) {
        choice = menu_select();
        switch (choice) {
        case 1: addfilm(string (argv[1]));
            break;
        case 2: listfilm(string (argv[1]));
            break;
        case 3: searchfilm(string (argv[1]));
            break;
        case 4: deletefilm(string(argv[1]));
            break;
        case 5: changefilm(string(argv[1]));
            break;
        case 6: exit(0);
            return 0;
        }
    }
    return 0;
}
    

