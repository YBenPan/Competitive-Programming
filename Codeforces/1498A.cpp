#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL gcd(LL a, LL b)
{
    if (a == 0) return b;
    return gcd(b % a, a); 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        for (LL i = n; i <= n + 2; ++i)
        {
            LL sum = 0, ii = i;
            while (ii > 0)
            {
                sum += (ii % 10); 
                ii /= 10; 
            }
            //cout << sum << endl;
            LL g = gcd(sum, i); 
            if (g > 1) {cout << i << endl; break;}
        }
    }
    return 0;
}