#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::pow;

void first() {
    double S;
    int n, p;
    cout << "Input S, n, p: ";
    cin >> S >> n >> p;

    float r = p / 100;
    cout << "m = " << (S * r * pow(1 + r, n)) / (12 * ((pow(1 + r, n) - 1))) << endl;
}


void second() {
    double S;
    int n, m;
    cout << "Input S, n, m: ";
    cin >> S >> n >> m;

    float r;
    for (float p = 0; p <= 100; p += 0.1) {
        r = p / 100;
        
        float k = (S * r * pow(1 + r, n)) / (12 * ((pow(1 + r, n) - 1)));
        if (m == k) {
            cout << p << endl; return;
        }
    }
    cout << "No answer" << endl;
}

void read_from_files(std::string& file_path) {
    std::ifstream f;
    f.open(file_path);
    std::string s;

    while (f >> s) {
        cout << s << endl;
    }
}

void third() {
    std::string path = "file.txt";
    read_from_files(path);
}

std::vector<char> read_int_from_files(std::string& file_path) {
    std::ifstream f;
    f.open(file_path);
    char s;
    std::vector<char> res;

    while (f >> s) {
        res.push_back(s);
    }
    return res;
}

void fourth() {
    std::string path = "file.txt";
    auto chars = read_int_from_files(path);

    bool last = true;

    for (auto e = chars.begin(); e != chars.end(); ++e) {
        if (isdigit(*e)) {
            if (!last) {
                cout << ", ";
            }
            cout << *e;
            last = true;
        }
        else {
            last = false;
        }
    }
    cout << endl;
}

void fifth() {
    char charArr[30];

    char c;
    for (int i = 0; i <= 29; ++i) {
        cin >> c;
        charArr[i] = c;
    }
    
    for (int i = 0; i <= 29; ++i) {
        for (int j = i + 1; j <= 29; ++j) {
            if (charArr[j] < charArr[i]) {
                char help_e = charArr[j];
                charArr[j] = charArr[i];
                charArr[i] = help_e;
            }
        }
    }
    for (int i = 0; i <= 29; ++i) {
        cout << charArr[i];
    }
    cout << endl;
    
}

int main()
{
    first();
    second();
    third();
    fourth();
    fifth();
}
