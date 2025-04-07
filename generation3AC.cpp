#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

struct TAC {
    string result, op, arg1, arg2;
};

vector<TAC> tacList;
int tempCount = 1;

string newTemp() {
    return "t" + to_string(tempCount++);
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

void process(stack<string> &operands, stack<char> &operators) {
    string right = operands.top(); operands.pop();
    string left = operands.top(); operands.pop();
    char op = operators.top(); operators.pop();
    string temp = newTemp();
    tacList.push_back({temp, string(1, op), left, right});
    operands.push(temp);
}

void generateTAC(string expr) {
    stack<string> operands;
    stack<char> operators;

    for (char ch : expr) {
        if (isspace(ch)) continue;
        if (isalnum(ch)) operands.push(string(1, ch));
        else if (ch == '(') operators.push(ch);
        else if (ch == ')') {
            while (operators.top() != '(') process(operands, operators);
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch))
                process(operands, operators);
            operators.push(ch);
        }
    }

    while (!operators.empty())
        process(operands, operators);

    tacList.push_back({"x", "=", operands.top(), ""});
}

void printTAC() {
    for (auto &t : tacList) {
        if (t.op == "=")
            cout << t.result << " = " << t.arg1 << endl;
        else
            cout << t.result << " = " << t.arg1 << " " << t.op << " " << t.arg2 << endl;
    }
}

int main() {
    string expr;
    // cout << "Enter expression (e.g., x = a + b * c - d): ";
    // getline(cin, expr);
    // auto eq = expr.find('=');
    // if (eq != string::npos) expr = expr.substr(eq + 1);
    // generateTAC(expr);
    generateTAC("a + b * c - d");
    cout << "\nThree Address Code:\n";
    printTAC();
    return 0;
}
