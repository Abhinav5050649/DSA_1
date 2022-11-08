#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;

bool isPrime(ll n)
{
    ll flag = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag++;
        }
    }

    if (flag == 1)
        return true;
    else 
        return false;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void solve(ll a, ll b)
{
    if (abs(a- b) <= 1)
        cout << "-1\n";
    else
    {
        if (isPrime(a) && isPrime(b))
            cout << "-1\n";
        else
        {
            if ((isPrime(a)) && (!isPrime(b)))
            {
                if (a * 2 <= b)
                {
                    cout << (a) << " " << (a * 2) << endl;
                }
            }
            else
            {
                int flag = 0;
                for (ll i = a + 2; i <= b; i += 2)
                {
                    if (gcd(a, i) != 1)
                    {
                        cout << a << " " << i << endl;
                        flag = 1;
                        break;                            
                    }
                }

                if (flag == 0)
                {
                    cout << "-1\n";
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
	ll T; cin >> T;
	while (T--)
	{
	    ll a, b; cin >> a >> b;
	    solve(a, b);
	}
	return 0;
}
