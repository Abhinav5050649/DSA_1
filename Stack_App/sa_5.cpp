#include "bits/stdc++.h"
using namespace std;

//Postfix to Prefix

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
        return true;
    else
        return false;    
}

string postfixToPrefix(stack<string> &s, string postfix)
{
    for (int i = 0, n = postfix.length(); i < n; ++i)
    {
        if (isalpha(postfix[i]))
        {
            s.push(string(1, postfix[i]));
        }
        else if (isOperator(postfix[i]))
        {
            string ops = string(1, postfix[i]);
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + ops + op2 + op1 + ")");
        }
    }

    return s.top();
}

int main()
{
    string prefix, postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    stack<string> s;
    prefix = postfixToPrefix(s, postfix);

    cout << "Prefix expression: " << prefix << "\n";
    return 0;
}