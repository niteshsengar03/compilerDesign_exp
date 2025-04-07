#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char nonTerminal = 'A'; // Fixed non-terminal
    string productionInput = "abc|abd|abf"; // Hardcoded input as a string

    vector<string> productions;
    string part = "";

    // Split the string by '|'
    for (char ch : productionInput) {
        if (ch == '|') {
            productions.push_back(part);
            part = "";
        } else {
            part += ch;
        }
    }
    if (!part.empty()) {
        productions.push_back(part);
    }

    // Find common prefix
    string prefix = productions[0];
    for (int i = 1; i < productions.size(); i++) {
        string current = productions[i];
        int j = 0;
        while (j < prefix.size() && j < current.size() && prefix[j] == current[j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }

    // If no common prefix
    if (prefix == "") {
        cout << nonTerminal << " -> ";
        for (int i = 0; i < productions.size(); i++) {
            cout << productions[i];
            if (i != productions.size() - 1) cout << " | ";
        }
        cout << endl;
        return 0;
    }

    // Left Factoring Output
    cout << nonTerminal << " -> " << prefix << nonTerminal << "'" << endl;

    cout << nonTerminal << "' -> ";
    for (int i = 0; i < productions.size(); i++) {
        string suffix = productions[i].substr(prefix.size());
        if (suffix == "") suffix = "ε";
        cout << suffix;
        if (i != productions.size() - 1) cout << " | ";
    }
    cout << endl;

    return 0;
}
