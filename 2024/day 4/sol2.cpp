#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

vector<char> convert(string s) {
    return vector<char>(s.begin(), s.end());
}

bool checkXmas(vector<vector<char>> map, int i, int j) {
    bool forwardDiagonalFound = false;
    bool backwardDiagonalFound = false;

    // Bound error-checking
    if (i <= 0 || i >= map.size() - 1 || j <= 0 || j >= map[i].size() - 1) {
        return false;
    }

    // Checking \ diagonal
    if (map[i + 1][j + 1] == 'S' && map[i - 1][j - 1] == 'M') {
        forwardDiagonalFound = true;
    } else if (map[i + 1][j + 1] == 'M' && map[i - 1][j - 1] == 'S') {
        forwardDiagonalFound = true;
    }
    // Checking / diagonal
    if (map[i + 1][j - 1] == 'S' && map[i - 1][j + 1] == 'M') {
        backwardDiagonalFound = true;
    } else if (map[i + 1][j - 1] == 'M' && map[i - 1][j + 1] == 'S') {
        backwardDiagonalFound = true;
    }

    return (forwardDiagonalFound && backwardDiagonalFound);
}

int main() {
    fstream MyFile("puzzle.txt");
    vector<vector<char>> map;
    string line;
    int count = 0;

    while (getline(MyFile, line)) {
        map.push_back(convert(line));
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'A' && checkXmas(map, i, j)) {
                count++;
            }
        }
    }
    
    cout << "Count: " << count << endl;
}