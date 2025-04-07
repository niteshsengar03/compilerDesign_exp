// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>
using namespace std;

// Hardcoded grammar rules
vector<string> productions = {
    "A->BB",
    "B->b"
};

vector<char> nonTerminals = {'A', 'B'};
vector<char> terminals = {'a', 'b'};
int n = 2; // Number of productions

char FIRST[2][10];   // FIRST[A], FIRST[B]
char FOLLOW[2][10];  // FOLLOW[A], FOLLOW[B]

// Helper function to add symbol if not already present
void add(char arr[], char symbol) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == symbol) return;
    }
    int len = strlen(arr);
    arr[len] = symbol;
    arr[len + 1] = '\0';
}

int getIndex(char nonTerm) {
    for (int i = 0; i < nonTerminals.size(); i++) {
        if (nonTerminals[i] == nonTerm) return i;
    }
    return -1;
}

int main() {
    // Initialize arrays
    for (int i = 0; i < 2; i++) {
        FIRST[i][0] = '\0';
        FOLLOW[i][0] = '\0';
    }

    // FIRST computation (1st symbol on RHS)
    for (int i = 0; i < n; i++) {
        char lhs = productions[i][0];
        char rhs = productions[i][3]; // 1st symbol on RHS

        int idx = getIndex(lhs);
        add(FIRST[idx], rhs); // Add 1st symbol to FIRST
    }

    // FOLLOW computation
    add(FOLLOW[0], '$'); // FOLLOW of start symbol gets $

    for (int i = 0; i < n; i++) {
        string prod = productions[i];
        char lhs = prod[0];

        for (int j = 3; j < prod.length() - 1; j++) {
            char symbol = prod[j];
            if (isupper(symbol)) { // If non-terminal
                char next = prod[j + 1];
                if (!isupper(next)) {
                    int index = getIndex(symbol);
                    add(FOLLOW[index], next);
                }
            }
        }

        // If non-terminal is at end, add FOLLOW of lhs
        char last = prod[prod.length() - 1];
        if (isupper(last)) {
            int lastIdx = getIndex(last);
            int lhsIdx = getIndex(lhs);
            for (int k = 0; FOLLOW[lhsIdx][k] != '\0'; k++) {
                add(FOLLOW[lastIdx], FOLLOW[lhsIdx][k]);
            }
        }
    }

    // Output FIRST sets
    cout << "FIRST sets:\n";
    for (int i = 0; i < 2; i++) {
        cout << "FIRST(" << nonTerminals[i] << ") = { ";
        for (int j = 0; FIRST[i][j] != '\0'; j++) {
            cout << FIRST[i][j];
            if (FIRST[i][j + 1] != '\0') cout << ", ";
        }
        cout << " }\n";
    }

    // Output FOLLOW sets
    cout << "\nFOLLOW sets:\n";
    for (int i = 0; i < 2; i++) {
        cout << "FOLLOW(" << nonTerminals[i] << ") = { ";
        for (int j = 0; FOLLOW[i][j] != '\0'; j++) {
            cout << FOLLOW[i][j];
            if (FOLLOW[i][j + 1] != '\0') cout << ", ";
        }
        cout << " }\n";
    }

    return 0;
}
