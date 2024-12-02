#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string text;

    // Read puzzle input
    fstream MyFile("puzzle.txt");
    vector<int> a = {};
    vector<int> b = {};

    while (getline(MyFile, text)) {
        string delimiter = " ";
        string tempa = text.substr(0, text.find(delimiter));
        string tempb = text.substr(text.find(delimiter) + 1);

        a.push_back(atoi(tempa.c_str()));
        b.push_back(atoi(tempb.c_str()));
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    int i = 0;
    int size = a.size();

    while (i < size) {
        int diff = abs(b[i] - a[i]);
        sum += diff;
        i++;
    }

    cout << sum << endl;
    MyFile.close();
}