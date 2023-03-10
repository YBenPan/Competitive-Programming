#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>

main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool flag = false;
        if (a == b + c || b == a + c || c == a + b) flag = 1;
        if ((a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (b == c && a % 2 == 0)) flag = 1;
        if (flag ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}