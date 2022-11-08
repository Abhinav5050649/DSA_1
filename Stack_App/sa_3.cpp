#include "bits/stdc++.h"
using namespace std;

//Postfix to Infix

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^'){
        return true;
    }
    else{
        return false;
    }
}

string postfixToInfix(stack<string> &s, string postfix)
{
    string infix = "";

    for (int i = 0, n = postfix.length(); i < n; ++i)
    {
        if (isalpha(postfix[i]))
        {
            s.push(string(1, postfix[i]));
        }
        else if (isOperator(postfix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 +")");
        }
    }

    string ans = s.top();
    return ans;
}

int main()
{
    string postfix, infix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack<string> s; 
    infix = postfixToInfix(s, postfix);
    cout << "Answer: " << infix << "\n";  
    return 0;
}