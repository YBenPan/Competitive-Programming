#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL dp[100005]; 
    dp[1] = 20;
    LL power = 27; 
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = ((7 * dp[i - 1]) % MOD + (20 * power) % MOD) % MOD;
        power = (power * 27) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}