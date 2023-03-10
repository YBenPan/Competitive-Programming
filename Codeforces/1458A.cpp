#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL a[200005], b[200005], diff[200005];
LL gcd(LL a, LL b)
{
    LL t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{ 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        if (i > 0)
        {
            diff[i - 1] = abs(a[i] - a[0]);
        }
    }
    LL common = diff[0];
    for (int i = 1; i < n - 1; ++i)
    {
        common = gcd(common, diff[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        LL sum = a[0] + b[i];
        LL ans = gcd(common, sum);
        cout << ans << " ";
    }
    return 0;
}