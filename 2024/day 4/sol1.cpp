#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

const vector<char> XMAS_STR = {'X', 'M', 'A', 'S'};

vector<char> convert(string s) {
    return vector<char>(s.begin(), s.end());
}

bool searchRight(vector<vector<char>> map, int i, int j) {
    for (int x = j, z = 0; z < XMAS_STR.size(); x++, z++) {
        if (x >= map[j].size() || map[i][x] != XMAS_STR[z]) {
            return false;
        }
    }

    return true;
}

bool searchLeft(vector<vector<char>> map, int i, int j) {
    for (int x = j, z = 0; z < XMAS_STR.size(); x--, z++) {
        if (x < 0 || map[i][x] != XMAS_STR[z]) {
            return false;
        }
    }

    return true;
}

bool searchUp(vector<vector<char>> map, int i, int j) {
    for (int x = i, z = 0; z < XMAS_STR.size(); x--, z++) {
        if (x < 0 || map[x][j] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

bool searchDown(vector<vector<char>> map, int i, int j) {
    for (int x = i, z = 0; z < XMAS_STR.size(); x++, z++) {
        if (x >= map.size() || map[x][j] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

bool searchUpRight(vector<vector<char>> map, int i, int j) {
    for (int x = i, y = j, z = 0; z < XMAS_STR.size(); x--, y++, z++) {
        if (x < 0 || y >= map[i].size() || map[x][y] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

bool searchDownRight(vector<vector<char>> map, int i, int j) {
    for (int x = i, y = j, z = 0; z < XMAS_STR.size(); x++, y++, z++) {
        if (x >= map.size() || y >= map[i].size() || map[x][y] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

bool searchDownLeft(vector<vector<char>> map, int i, int j) {
    for (int x = i, y = j, z = 0; z < XMAS_STR.size(); x++, y--, z++) {
        if (x >= map.size() || y < 0 || map[x][y] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

bool searchUpLeft(vector<vector<char>> map, int i, int j) {
    for (int x = i, y = j, z = 0; z < XMAS_STR.size(); x--, y--, z++) {
        if (x < 0 || y < 0 || map[x][y] != XMAS_STR[z]) {
            return false;
        }
    }

    return true; 
}

int main() {
    fstream MyFile("puzzle.txt");
    vector<vector<char>> map;
    string line;
    int count;

    while (getline(MyFile, line)) {
        map.push_back(convert(line));
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'X') {
                if (searchRight(map, i, j)) count++;
                if (searchLeft(map, i, j)) count++;
                if (searchUp(map, i, j)) count++;
                if (searchDown(map, i, j)) count++;
                if (searchUpRight(map, i, j)) count++;
                if (searchDownRight(map, i, j)) count++;
                if (searchDownLeft(map, i, j)) count++;
                if (searchUpLeft(map, i, j)) count++;
            }
        }
    }

    cout << "Count: " << count << endl;
}