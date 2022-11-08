#include "bits/stdc++.h"
using namespace std;

//Infix to Prefix
 
bool isOperator(char c)
{
    if (c == '*' || c == '+' || c == '/' || c == '-' || c == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c)
{
    if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

string infixToPrefix(stack<char> &s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());
    int n = infix.length();
    for (int i  = 0; i < n; ++i)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')'){
            infix[i] = '(';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (isalpha(infix[i]))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((!s.empty()) && (s.top() != '('))
            {
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else if (precedence(infix[i] > precedence(s.top())))
            {
                s.push(infix[i]);
            }
            else if ((precedence(infix[i]) == precedence(s.top())) && (s.top() == '^'))
            {
                while ((precedence(infix[i]) == precedence(s.top())) && (s.top() == '^'))
                {
                    prefix += s.top();
                    s.pop();
                }
            }
            else if ((precedence(infix[i]) == precedence(s.top())) && (s.top() != '^'))
            {
                s.push(infix[i]);
            }
            else{
                while (precedence(infix[i]) < precedence(s.top()))
                {
                    prefix += s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix, prefix;
    cout << "ENter infix exp: ";
    cin >> infix;

    stack<char> s;
    prefix = infixToPrefix(s, infix);

    cout << "Prefix expression: " << prefix << "\n";
    return 0;
}