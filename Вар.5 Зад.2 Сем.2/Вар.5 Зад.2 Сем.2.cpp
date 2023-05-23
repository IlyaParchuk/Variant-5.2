// Вар.5 Зад.2 Сем.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <string>
//#include <invalid_argument>
#include <regex>
#include <iostream>
#include <locale>
#include <cstdlib>
using namespace std;

class TroikaString {
private:
    string s;

public:
    TroikaString(string s) {
        if (regex_match(s, regex("[012]+"))) {
            this->s = s;
        }
        else {
            throw invalid_argument("Строка должна состоять только из символов '0', '1' и '2'");
        }
    }

    string toString() {
        return s;
    }

    string toBinary() {
        return regex_replace(regex_replace(regex_replace(s, regex("0"), "00"), regex("1"), "01"), regex("2"), "10");
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    try {
        TroikaString troikaString(s);
        cout << "Исходная строка: " << troikaString.toString() << endl;
        cout << "Двоичное представление: " << troikaString.toBinary() << endl;
    }
    catch (invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
