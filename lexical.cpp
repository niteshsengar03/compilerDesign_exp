#include<bits/stdc++.h>
using namespace std;

// Global variables
vector<string> keywords = {"if", "else", "while", "return", "int", "float", "char", "void", "for"};
vector<string> operators = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="};
vector<char> delimiters = {';', ',', '(', ')', '{', '}'};

bool isKeyword(string str) {
    for (string k : keywords) {
        if (str == k) return true;
    }
    return false;
}

bool isDelimiter(char ch) {
    for (char d : delimiters) {
        if (ch == d) return true;
    }
    return false;
}

bool isOperator(char ch) {
    for (string op : operators) {
        if (op.find(ch) != string::npos) return true;
    }
    return false;
}

void analyzeTokens(string input) {
    string buffer = "";

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (isalnum(ch) || ch == '_') {
            buffer += ch;
        } else {
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    cout << "Keyword: " << buffer << endl;
                } else if (isdigit(buffer[0])) {
                    cout << "Number: " << buffer << endl;
                } else {
                    cout << "Identifier: " << buffer << endl;
                }
                buffer = "";
            }

            if (isDelimiter(ch)) {
                cout << "Delimiter: " << ch << endl;
            } else if (isOperator(ch)) {
                cout << "Operator: " << ch << endl;
            } else if (!isspace(ch)) {
                cout << "Unknown token: " << ch << endl;
            }
        }
    }

    // In case the buffer still has something left after loop ends
    if (!buffer.empty()) {
        if (isKeyword(buffer)) {
            cout << "Keyword: " << buffer << endl;
        } else if (isdigit(buffer[0])) {
            cout << "Number: " << buffer << endl;
        } else {
            cout << "Identifier: " << buffer << endl;
        }
    }
}

int main() {
    string input;
    cout << "Enter the input code: ";
    getline(cin, input);
    analyzeTokens(input);
    return 0;
}
