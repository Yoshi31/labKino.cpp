#include "Film.h";
#include <string>
#include <iostream>

Film::Film() {
    name = "Null";
    genre = "Null";
    ratting = 0;
    price = 0;
}

void Film::SetFilm(string name_value, string genre_value, float ratting_value, int price_value) {
    name = name_value;
    genre = genre_value;
    ratting = ratting_value;
    price = price_value;
}
string Film::GetName() {
    return name;
}

string Film:: GetGenre() {
    return genre;
}

float Film::GetRatting() {
    return ratting;
}

int Film::GetPrice() {
    return price;
}

void Film:: ScanFilm() {
    setlocale(LC_CTYPE, "Russian");
    cout << "����� �����" << endl << "������� ������ � ������" << endl;
    cout << "��������:" << endl;
    cin >> name;
    cout << "����:" << endl;
    cin >> genre;
    cout << "�������:" << endl;
    cin >> ratting;
    cout << "���� �� �����:" << endl;
    cin >> price;
};

void Film::Print() {
    setlocale(LC_CTYPE, "Russian");
    cout << "��������: " << name << "\t ����: " << genre << "\t �������: " << ratting << "\t ����: " << price << endl;
}

void Film::Putinfile(string filename) {
    ofstream file;
    file.open(filename, ios_base::app);
    if (!file) {
        cout << "������ ������ � ������" << endl;
        return;
    }
    file << name << " ";
    file << genre << " ";
    file << ratting << " ";
    file << price << " " << endl;
    file.close();
}


