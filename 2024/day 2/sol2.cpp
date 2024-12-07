#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

bool compdesc(int a, int b) {
    return a > b;
}

bool compdiff(int a, int b) {
    if(abs(b - a) < 1 || abs(b - a) > 3) {
        return false;
    }
    return true;
}

bool checkIfUnsafe(vector<int> report) {
    // Check if is neither ascending nor descending
    if (!is_sorted(report.begin(), report.end()) && !is_sorted(report.begin(), report.end(), compdesc)) {
        return true;
    }

    // Check if interval is too high
    int i = 0;
    while (i < report.size() - 1) {
        if (!compdiff(report[i], report[i + 1])) {
            return true;
        }
        i++;
    }

    return false;
}

int main() {
    fstream Myfile("puzzle.txt");
    string text;
    int safecount = 0;

    while(getline(Myfile, text)) {
        vector<int> levels = {};
        string delimiter = " ";
        size_t pos = 0;
        size_t next;

        // Separating levels in report and writing to array of levels
        stringstream s(text);
        string word;

        while (s >> word) {
            levels.push_back(atoi(word.c_str()));
        }

        bool unsafe = checkIfUnsafe(levels);

        // Second check
        int i = 0;
        while (unsafe == true && i < levels.size()) {
            vector<int> temp = levels;
            temp.erase(temp.begin() + i);
            unsafe = checkIfUnsafe(temp);
            i++;
        }

        if (!unsafe) safecount++;
    }

    cout << safecount << endl;
}