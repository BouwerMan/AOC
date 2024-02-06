// https://adventofcode.com/2023/day/3
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define FILE_NAME "sample.txt"
#define FILE_LENGTH 10

using namespace std;
void solve(vector<string>& vect)
{
    for (string line : vect) {
        for (char& c : line) {
            if (ispunct(c) && c != '.') {
                cout << "Found char: " << c << endl;
            }
        }
    }
}

int main()
{

    vector<string> vect;
    vect.reserve(FILE_LENGTH);

    ifstream file(FILE_NAME);
    string line;

    if (!file.is_open()) {
        cerr << "Could not open file: " << FILE_NAME << endl;
        return 1;
    }

    while (getline(file, line)) {
        vect.push_back(line);
    }

    solve(vect);

    file.close();
    return 0;
}
