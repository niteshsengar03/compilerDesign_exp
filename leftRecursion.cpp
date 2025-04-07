#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char nonTerminal = 'A'; // Fixed non-terminal
    string production = "AB|Ac|aB|cd"; // Hardcoded production

    vector<string> alpha; // For left-recursive parts (like Aa → a)
    vector<string> beta;  // For non-left-recursive parts (like b)

    // Split production by '|'
    string part = "";
    for (char ch : production) {
        if (ch == '|') {
            if (part[0] == nonTerminal) {
                alpha.push_back(part.substr(1)); // skip the non-terminal
            } else {
                beta.push_back(part);
            }
            part = "";
        } else {
            part += ch;
        }
    }

    // Don't forget to check last part after loop
    if (part[0] == nonTerminal) {
        alpha.push_back(part.substr(1));
    } else {
        beta.push_back(part);
    }

    // If there's no left recursion
    if (alpha.empty()) {
        cout << nonTerminal << " -> " << production << endl;
    } else {
        // Output for eliminating left recursion
        cout << nonTerminal << " -> ";
        for (int i = 0; i < beta.size(); i++) {
            cout << beta[i] << nonTerminal << "'";
            cout << " | ";
            // if (i != beta.size() - 1) cout << " | ";
        }
        cout << endl;

        cout << nonTerminal << "' -> ";
        for (int i = 0; i < alpha.size(); i++) {
            cout << alpha[i] << nonTerminal << "'";
            cout<<" | ";
            // if (i != alpha.size() - 1) cout << " | ";
        }
        cout << " | ε" << endl;
    }

    return 0;
}
