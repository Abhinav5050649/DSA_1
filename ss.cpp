#include "bits/stdc++.h"
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void countSieve()
{
	sieve[0] = false, sieve[1] = false;
	for (int i = 2; i <= N; i++)
	{
		sieve[i] = true;
	}

	for (int i = 0; i * i <= N; i++)
	{
		if (sieve[i] == true){
			for (int j = i * i; j <= N; j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

vector<int> g_primes(int n)
{
	vector<int> ds;
	for (int i = 2; i <= n; i++)
	{
		if (sieve[i] == true)
		{
			ds.push_back(i);
		}
	}

	return ds;
}

int main()
{
	countSieve();
	int t; cin >> t;
	while (t--)
	{
		int l, r; cin >> l >> r;
		vector<int> tpr = g_primes(sqrt(r));

		int dummy[r - l + 1];
		for (int i = 0; i < r-l + 1; i++)
		{
			dummy[i] = 1;
		}

		for (auto it: tpr)
		{
			int fM = (l/it)*it;
			if (fM < l){fM += it;}

			for (int j = max(fM, it * it); j <= r; j+=it)
			{
				dummy[j - l] = 0;
			}	
		}

		vector<int> final_p;
		for (int i = l; i <= r; i++)
		{
			if (dummy[i - l] == 1){
				if (i-l == 0 || i - l == -1)
				{
					continue;
				}
				else
				{
					final_p.push_back(i);
				}
			}
		}

		for (auto it : final_p)
		{
			cout << it << endl;
		}
		final_p.clear();
		cout << endl;
		cout << endl;
	}

	return 0;
}