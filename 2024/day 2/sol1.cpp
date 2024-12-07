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

        // Check if is neither ascending nor descending
        bool unsafe = false;
        if (!is_sorted(levels.begin(), levels.end()) && !is_sorted(levels.begin(), levels.end(), compdesc)) {
            unsafe = true;
        }

        // Check if interval is too high
        int i = 0;
        while (i < levels.size() - 1) {
            if (!compdiff(levels[i], levels[i + 1])) {
                unsafe = true;
                break;
            }

            i++;
        }

        if (!unsafe) safecount++;
    }

    cout << safecount << endl;
}