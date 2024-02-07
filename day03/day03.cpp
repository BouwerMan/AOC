// https://adventofcode.com/2023/day/3
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define FILE_NAME "sample.txt"
#define FILE_LENGTH 10

using namespace std;

int find_num(vector<string>& vect, size_t line_num, size_t char_num)
{
    // Looking up
    if (line_num != 0) {
        for (size_t i = -1; i <= 1; i++) {
            char d = vect[line_num - 1][i];
            if (!isalpha(d)) {
                break;
            }
        }
    }
    return 0;
}

void solve(vector<string>& vect)
{
    for (size_t i = 0; i < vect.size(); i++) {
        string line = vect[i];
        for (size_t j = 0; j < line.length(); j++) {
            char c = line[j];
            if (!ispunct(c) || c == '.') {
                continue;
            }
            cout << "Found char: " << c << endl;
            find_num(vect, i, j);
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
