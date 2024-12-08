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
    regex newl("\r?\n");
    input = regex_replace(input, newl, "");

    smatch target;
    int sum = 0;
    regex regInstruction("(do\\(\\)|don't\\(\\)|mul\\([0-9]+\\,[0-9]+\\))");
    regex mul("mul\\([0-9]+\\,[0-9]+\\)");

    string lastInstruction = "do";
    
    while (regex_search(input, target, regInstruction)) {
        if (regex_match(target.str(), mul) && lastInstruction == "do") {
            int result = split_then_mul(target.str());
            sum += result;
        } else if (target.str() == "do()") {
            lastInstruction = "do";
        } else if (target.str() == "don't()") {
            lastInstruction = "don't";
        }

        input = target.suffix().str();
    }

    cout << "Sum: " << sum << endl;
}