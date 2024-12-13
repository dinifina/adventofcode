#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Guard {
    int row;
    int col;
    char direction;
};

bool goStraight(Guard* guard, vector<vector<char>> &map) {
    int prevRow = guard->row;
    int prevCol = guard->col;
    int nextRow = prevRow;
    int nextCol = prevCol;
    bool visited = false;

    // different if statements based on direction to determine next position
    // if current tile has been visited, then return true
    switch(guard->direction) {
        case 'r':
            nextCol++;
            break;
        case 'l':
            nextCol--;
            break;
        case 'u':
            nextRow--;
            break;
        case 'd':
            nextRow++;
            break;
        default:
            break;
    }

    guard->row = nextRow;
    guard->col = nextCol;

    if (nextRow >= 0 
    && nextRow < map.size()
    && nextCol >= 0
    && nextCol < map[0].size()
    && map[nextRow][nextCol] == 'X') {
        visited = true;
        map[nextRow][nextCol] = '^';
    }

    map[prevRow][prevCol] = 'X';

    return visited;
}

void turnRight(Guard* guard) {
    switch(guard->direction) {
        case 'r':
            guard->direction = 'd';
            break;
        case 'd':
            guard->direction = 'l';
            break;
        case 'l':
            guard->direction = 'u';
            break;
        case 'u':
            guard->direction = 'r';
            break;
        default:
            break;
    }
}

bool hasObstacle(Guard* guard, vector<vector<char>> map) {
    int row = guard->row;
    int col = guard->col;

    switch(guard->direction) {
        case 'r':
            col++;
            if (col < map[0].size() && map[row][col] == '#') return true;
            break;
        case 'd': 
            row++;
            if (row < map.size() && map[row][col] == '#') return true;
            break;
        case 'l':
            col--;
            if (col >= 0 && map[row][col] == '#') return true;
            break;
        case 'u':
            row--;
            if (row >= 0 && map[row][col] == '#') return true;
            break;
        default:
            break;
    }

    return false;
}

int main() {
    fstream MyFile("puzzle.txt");
    string input;
    fstream NewMap("newMap.txt");

    vector<vector<char>> map;
    int guardRow, sum = 0;
    Guard* guard = new Guard();
    guard->direction = 'u';

    while (getline(MyFile, input)) {
        vector<char> row;
        int guardCol = 0;
        for (char c : input) {
            if (c == '^') {
                guard->row = guardRow;
                guard->col = guardCol;
            }
            row.push_back(c);
            guardCol++;
        }
        map.push_back(row);
        guardRow++;
    }

    bool visited = false;
    while (guard->row >= 0 && guard->row < map.size()
    && guard->col >= 0 && guard->col < map[0].size()) {
        if (hasObstacle(guard, map)) {
            turnRight(guard);
        }

        visited = goStraight(guard, map);

        if (!visited) {
            sum++;
        }
    }

    for (vector<char> row : map) {
        for (char c : row) {
            NewMap << c;
        }
        NewMap << endl;
    }

    cout << "Sum of distinct tiles: " << sum << endl;
}