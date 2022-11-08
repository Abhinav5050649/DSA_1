#include "bits/stdc++.h"
using namespace std;

//Prefix to Postfix

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return true;
    }
    else{
        return false;
    }
}

string prefixToPostfix(stack<string> &s, string prefix)
{
    for (int i = prefix.length() - 1; i >= 0; --i)
    {
        if (isalpha(prefix[i]))
        {
            s.push(string(1, prefix[i]));
        }
        else if (isOperator(prefix[i])){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string op3 = string(1, prefix[i]);
            s.push("(" + op1 + op2 + op3 + ")");
        }
    }

    return s.top();
}

int main()
{
    string postfix, prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    stack<string> s;
    postfix = prefixToPostfix(s, prefix);
    cout << "Postfix expression: " << postfix << "\n";
    s.pop();
    return 0;
}