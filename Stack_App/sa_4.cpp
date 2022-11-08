#include "bits/stdc++.h"
using namespace std;

//Prefix to Infix

bool isOperator(char c)
{
    if (c == '+' || c == '/' || c == '*' || c == '^' || c == '-')
    {
        return true;
    }else{
        return false;
    }
}

string prefixToInfix(stack<string> &s, string prefix)
{
    for (int i = prefix.length() - 1; i >= 0; --i)
    {
        if (isalpha(prefix[i]))
        {
            s.push(string(1, prefix[i]));
        }
        else if (isOperator(prefix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string op3 = "(" + op1 + prefix[i] + op2 + ")";
            s.push(op3);
        }
    }

    return s.top();
}

int main()
{
    string infix, prefix;
    
    cout << "Enter prefix expression: ";
    cin >> prefix;
    
    stack<string> s;
    infix = prefixToInfix(s, prefix);

    cout << "Infix expression: " << infix << "\n";
    s.pop();    
    return 0;
}