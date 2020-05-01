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
    cout << "НОВЫЙ ФИЛЬМ" << endl << "Введите данных о фильме" << endl;
    cout << "Название:" << endl;
    cin >> name;
    cout << "Жанр:" << endl;
    cin >> genre;
    cout << "Рэйтинг:" << endl;
    cin >> ratting;
    cout << "Цену за билет:" << endl;
    cin >> price;
};

void Film::Print() {
    setlocale(LC_CTYPE, "Russian");
    cout << "Название: " << name << "\t Жанр: " << genre << "\t Рэйтинг: " << ratting << "\t Цена: " << price << endl;
}

void Film::Putinfile(string filename) {
    ofstream file;
    file.open(filename, ios_base::app);
    if (!file) {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    file << name << " ";
    file << genre << " ";
    file << ratting << " ";
    file << price << " " << endl;
    file.close();
}


