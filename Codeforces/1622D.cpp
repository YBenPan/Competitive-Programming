#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 998244353
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCr(unsigned long long n,
                                 int r, int p = MOD)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    char str[5005];
    int cnt = 0, a = 1, b = n;
    int one[5005] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        if (str[i] == '1') 
        {
            one[i] = one[i - 1] + 1;
            cnt++;
            if (cnt == k + 1) b = i - 1;
        }
        else one[i] = one[i - 1];
    }
    if (b == n || k == 0) {cout << 1 << endl; return 0;}
    int tot = nCr(b - a + 1, one[b] - one[a - 1]);
    int last_b = b;
    while (b < n)
    {
        a++;
        b++;
        while (b < n && str[b + 1] != '1') b++;
        // cout << a << " " << b << endl;
        tot += (nCr(b - a + 1, one[b] - one[a - 1]) - nCr(last_b - a + 1, one[last_b] - one[a - 1])) % MOD;
        last_b = b;
    }
    cout << tot << endl;
    return 0;
}