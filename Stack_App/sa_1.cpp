#include "bits/stdc++.h"
using namespace std;

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

string infixToPostfix(stack<char> &s, string infix)
{
	string postfix = "";

	for (int i = 0, n = infix.length(); i < n; ++i)
	{
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix += infix[i];
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((!s.empty()) && (s.top() != '('))
			{
				char temp = s.top();
				postfix += temp;
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
			else
			{ 
				if (precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(s.top())) && (s.top() == '^'))
				{
					s.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(s.top()) && (s.top() != '^')))
				{
					while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
					{
						postfix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}	
			}
		}
	}	

	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

int main()
{
	cout << "Enter infix expression: ";
	string infix, postfix;
	cin >> infix;
	stack<char> s;
	postfix = infixToPostfix(s, infix);

	cout << "New Expression: "<< postfix<< "\n";
	return 0;
}