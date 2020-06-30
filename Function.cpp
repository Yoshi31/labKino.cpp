#include "Function.h"
#include "Film.h"
#include <iostream>

string name_value;
string genre_value;
float ratting_value;
int price_value;

void addfilm(string filename) {
    Film* film;
    film = new Film;
    film->ScanFilm();
    int c;
    cout << "Вы дейстительно хотите добавить этот фильм?" << endl;
    film->Print();
    cout << "1)Да" << endl << "2)Нет" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        film->Putinfile(filename);
        cout << "Фильм успешно добавлен в базу данных кинотеатра" << endl;
        break;
    case 2:
        cout << "Фильм не будет добавлен в базу данных кинотеатра";
        exit(0);
    default:
        cout << "Ошибка" << endl;

    }
    delete film;

}

/*void deletefilm(string filename) {
    cout << "Введите название фильма для удаления" << endl;
    string deletename;
    string archiv;
    cin >> deletename;
    fstream file;
    int n, s = 0;
    Film* film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        Film* film;
        film = new Film;
        file >> *film;
        //file >> name_value >> genre_value >> ratting_value >> price_value;
        //film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (deletename != film->GetName())
        {
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());

            archiv += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
        }
        delete film;

    } while (s < n - 3);
    file.close();
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file << archiv;
    file.close();
    cout << "Фильм был успешно удален!" << endl;
}*/

void deletefilm(string filename) {
    cout << "Введите название фильма для удаления" << endl;
    string deletename;
    cin >> deletename;
    fstream file;
    int n, s = 0;
    const int maxsize = 20;
    Film *masfilm = new Film[maxsize];
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    int i = 0;
    while (s < (n - 3)) {
            file >> masfilm[i];
            i++;
            s = file.tellg();
    }
    file.close();
    file.open(filename);
    file.ios_base::trunc;
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    //file.ios_base::trunc;
    for (int j = 0; j < maxsize-1; j++) {
        if ((masfilm[j].GetName() != deletename) && (masfilm[j].GetName() != "Null")) {
            file << masfilm[j];
            masfilm[j].Print();
        }
    }
    delete[]masfilm;
    file.close();
    cout << "Фильм был успешно удален!" << endl;
}

void searchfilm(string filename) {
    cout << "Поиск фильмов по:" << endl << "1)Названию" << endl << "2)Жанру" << endl;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        searchfilm_name(filename);
        break;
    case 2:
        searchfilm_genre(filename);
        break;
    default:
        cout << "Ошибка" << endl;

    }
}

void searchfilm_name(string filename) {
    string check;
    cout << "Введите название фильма для поиска" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Список фильмов по вашему запросу:" << endl;
    do
    {
        file >> *film;
       // >> name_value >> genre_value >> ratting_value >> price_value;
      // film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (film->GetName() == check) {
            film->Print();
        }



    } while (s < n - 4);
    file.close();
    delete film;
}

void searchfilm_genre(string filename) {
    string check;
    cout << "Введите жанр фильма для поиска" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Список фильмов по вашему запросу:" << endl;
    do
    {
        file >> *film;
        //file >> name_value >> genre_value >> ratting_value >> price_value;
       // film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (film->GetGenre() == check) {
            film->Print();
        }



    } while (s < n - 5);
    file.close();
    delete film;
}

void listfilm(string filename) {
    fstream file;
    int n, s = 0;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
        
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        file >> *film;
        film->Print();
        s = file.tellg();



    } while (s < n - 5);
    file.close();
    delete film;
}

void changefilm(string filename) {
    string changename;
    string archive;
    cout << "Введите название фильма который хотите изменить: ";
    cin >> changename;
    fstream file;
    int n, s = 0;
    char c;
    Film* film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do {
        file >> *film;
        s = file.tellg();
        if (changename == film->GetName()) {
            film->Print();
            cout << "Что вы хотите изменить?"<<endl;
            cout << "1)Название" << endl << "2)Жанр" << endl << "3)Рейтинг" << endl << "4)Стоимость билета" << endl;
            int c;
            cin >> c;
            string newname;
            string newgenre;
            float newratting;
            int newprice;
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());
            switch (c)
            {
            case 1:
                cout<<"Введите новое название: ";
                cin >> newname;
                archive += newname + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Название фильма успешно изменено!"<<endl;
                break;
            case 2:
                cout << "Введите новый жанр: ";
                cin >> newgenre;
                archive += film->GetName() + " " + newgenre + " " + rattingstr + " " + pricestr + "\n";
                cout << "Жанр фильма успешно изменен!" << endl;
                break;
            case 3:
                cout << "Введите новый рейтинг: ";
                cin >> newratting;
                rattingstr = to_string(newratting);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Рейтинг фильма успешно изменен!" << endl;
                break;
            case 4:
                cout << "Введите новую стоимость: ";
                cin >> newprice;
                pricestr = to_string(newprice);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Стоимость фильма успешно изменена!" << endl;
                break;
            default:
                cout << "Ошибка" << endl;

            }
        }
        else {
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());

            archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
        }
    } while (s < n - 5);
    file.close();
    file.open(filename);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file << archive;
    file.close();
    delete film;
}

ostream& operator<<(ostream& os, const Film& film) {
    os << film.name << " " << film.genre << " " << film.ratting << " " << film.price << "\n";
    return os;
}

istream& operator>>(istream& is, Film& film) {
    is >> film.name >> film.genre >> film.ratting >> film.price;
    return is;
}
int menu_select()
{
    char s[80];
    int c;
    do
    {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 - Добавить фильм" << endl << "2 - Список фильмов" << endl << "3 - Поиск фильма" << endl << "4 - Удалить фильм" << endl << "5 - Изменить фильм" << endl << "6 - выход" << endl << "Ваш выбор: ";
        cin >> s;
        c = atoi(s);
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    } while (c < 0 || c>6);
    return c;
}
