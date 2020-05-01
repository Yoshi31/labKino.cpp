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
    cout << "�� ������������ ������ �������� ���� �����?" << endl;
    film->Print();
    cout << "1)��" << endl << "2)���" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        film->Putinfile(filename);
        cout << "����� ������� �������� � ���� ������ ����������" << endl;
        break;
    case 2:
        cout << "����� �� ����� �������� � ���� ������ ����������";
        exit(0);
    default:
        cout << "������" << endl;

    }
    delete film;

}

void deletefilm(string filename) {
    cout << "������� �������� ������ ��� ��������" << endl;
    string deletename;
    string archiv;
    cin >> deletename;
    fstream file;
    int n, s = 0;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
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

    } while (s < n - 4);
    file.close();
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
        return;
    }
    file << archiv;
    file.close();
    cout << "����� ��� ������� ������!" << endl;
}

void searchfilm(string filename) {
    cout << "����� ������� ��:" << endl << "1)��������" << endl << "2)�����" << endl;
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
        cout << "������" << endl;

    }
}

void searchfilm_name(string filename) {
    string check;
    cout << "������� �������� ������ ��� ������" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "������ ������� �� ������ �������:" << endl;
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
}

void searchfilm_genre(string filename) {
    string check;
    cout << "������� ���� ������ ��� ������" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "������ ������� �� ������ �������:" << endl;
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
}

void listfilm(string filename) {
    fstream file;
    int n, s = 0;
    Film *film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
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
}

void changefilm(string filename) {
    string changename;
    string archive;
    cout << "������� �������� ������ ������� ������ ��������: ";
    cin >> changename;
    fstream file;
    int n, s = 0;
    char c;
    Film* film;
    film = new Film;
    file.open(filename);
    if (!file) {
        cout << "������ ������ � ������" << endl;
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
            cout << "��� �� ������ ��������?"<<endl;
            cout << "1)��������" << endl << "2)����" << endl << "3)�������" << endl << "4)��������� ������" << endl;
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
                cout<<"������� ����� ��������: ";
                cin >> newname;
                archive += newname + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "�������� ������ ������� ��������!"<<endl;
                break;
            case 2:
                cout << "������� ����� ����: ";
                cin >> newgenre;
                archive += film->GetName() + " " + newgenre + " " + rattingstr + " " + pricestr + "\n";
                cout << "���� ������ ������� �������!" << endl;
                break;
            case 3:
                cout << "������� ����� �������: ";
                cin >> newratting;
                rattingstr = to_string(newratting);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "������� ������ ������� �������!" << endl;
                break;
            case 4:
                cout << "������� ����� ���������: ";
                cin >> newprice;
                pricestr = to_string(newprice);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "��������� ������ ������� ��������!" << endl;
                break;
            default:
                cout << "������" << endl;

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
        cout << "������ ������ � ������" << endl;
        return;
    }
    file << archive;
    file.close();
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
        cout << "1 - �������� �����" << endl << "2 - ������ �������" << endl << "3 - ����� ������" << endl << "4 - ������� �����" << endl << "5 - �������� �����" << endl << "6 - �����" << endl << "��� �����: ";
        cin >> s;
        c = atoi(s);
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    } while (c < 0 || c>6);
    return c;
}
