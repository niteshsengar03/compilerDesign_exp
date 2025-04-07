// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>
using namespace std;

struct Rule {
    char lhs;
    string rhs;
};

vector<Rule> rules;
vector<char> parseStack;
int n;
char startSymbol;

void push(char c) {
    parseStack.push_back(c);
}

void pop(int count) {
    while (count > 0) {
        parseStack.pop_back();
        count--;
    }
}


void printStack() {
    for (char c : parseStack) {
        cout << c;
    }
    cout << endl;
}

void reduce() {
    bool changed;
    do {
        changed = false;
        for (int r = 0; r < n; r++) {
            int len = rules[r].rhs.size();
            if (parseStack.size() >= len) {
                string topSegment = "";
                for (int i = parseStack.size() - len; i < parseStack.size(); i++) {
                    topSegment += parseStack[i];
                }

                if (topSegment == rules[r].rhs) {
                    cout << "Reducing " << rules[r].rhs << " -> " << rules[r].lhs << endl;
                    pop(len);
                    push(rules[r].lhs);
                    printStack();
                    changed = true;
                    break; // Try again from the first rule
                }
            }
        }
    } while (changed);
}

int main() {
    string input;
    cout << "No. of rules: ";
    cin >> n;

    cout << "Enter rules (e.g., S -> AB):" << endl;
    for (int i = 0; i < n; i++) {
        char lhs;
        string arrow, rhs;
        cin >> lhs >> arrow >> rhs;
        rules.push_back({lhs, rhs});
    }

    cout << "Start symbol: ";
    cin >> startSymbol;

    cout << "Input string: ";
    cin >> input;

    cout << "\nProcessing..." << endl;

    for (char ch : input) {
        cout << "Shift " << ch << endl;
        push(ch);
        printStack();
        reduce();
    }

    if (parseStack.size() == 1 && parseStack[0] == startSymbol) {
        cout << "\nAccepted. Reduced to " << startSymbol << "." << endl;
    } else {
        cout << "\nRejected. Could not reduce to " << startSymbol << "." << endl;
    }

    return 0;
}
