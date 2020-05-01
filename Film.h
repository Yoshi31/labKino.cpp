#pragma once
#include <string>
#include <fstream>
using namespace std;
class Film
{
private:
    string name;
    string genre;
    float ratting;
    int price;
public:
    Film();
    void SetFilm(string name_value, string genre_value, float ratting_value, int price_value);
    string GetName();
    string GetGenre();
    float GetRatting();
    int GetPrice();
    void ScanFilm();
    void Print();
    void Putinfile(string filename);
    friend ostream& operator << (ostream& os, const Film& film);
    friend istream& operator >> (istream& is, Film& film);
};
