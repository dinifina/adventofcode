#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <string.h>

using namespace std;

int split_then_mul(string expression) {
    regex r("[0-9]+\\,[0-9]+");
    smatch match;
    regex_search(expression, match, r);

    string unparsed = match.str();
    string delimiter = ",";
    string tempa = unparsed.substr(0, unparsed.find(delimiter));
    string tempb = unparsed.substr(unparsed.find(delimiter) + 1);
    return stoi(tempa) * stoi(tempb);
}

int main() {
    fstream MyFile("puzzle.txt");
    string input { istreambuf_iterator<char>(MyFile), istreambuf_iterator<char>() };
    // replace all newlines
    regex newl("\r\n");
    regex_replace(input, newl, "");

    // search for all strings that match the regex mul\\([0-9]+\\,[0-9]+\\)
    smatch target;
    int sum = 0;
    regex r("mul\\([0-9]+\\,[0-9]+\\)");
    while (regex_search(input, target, r)) {
        // calculate product
        int result = split_then_mul(target.str());
        sum += result;
        input = target.suffix().str();
    }

    cout << "Sum: " << sum << endl;
}