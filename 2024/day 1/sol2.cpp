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

    vector<int>::iterator it_a;
    
    int similarity = 0;
    for (it_a = a.begin(); it_a != a.end(); ++it_a) {
        int occurrences = count(b.begin(), b.end(), *it_a);
        similarity += (*it_a * occurrences);
    }

    cout << similarity << endl;
    MyFile.close();
}