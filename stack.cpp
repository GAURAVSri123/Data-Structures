#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (!isFull())
            arr[++top] = x;
        else
            cout << "Stack Overflow\n";
    }

    int pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int peek() {
        return arr[top];
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluate(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
    return 0;
}


int evaluatePostfix(string exp) {
    Stack st;

    for (char c : exp) {
        if (c == ' ') continue;

        // if operand (digit)
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();
            int result = evaluate(a, b, c);
            st.push(result);
        }
    }
    return st.pop();
}

int evaluatePrefix(string exp) {
    Stack st;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if (c == ' ') continue;

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int a = st.pop();
            int b = st.pop();
            int result = evaluate(a, b, c);
            st.push(result);
        }
    }
    return st.pop();
}


int main() {
    string postfix, prefix;

    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);
    cout << "Postfix Evaluation = " << evaluatePostfix(postfix) << endl;

    cout << "\nEnter Prefix Expression: ";
    getline(cin, prefix);
    cout << "Prefix Evaluation = " << evaluatePrefix(prefix) << endl;

    return 0;
}
