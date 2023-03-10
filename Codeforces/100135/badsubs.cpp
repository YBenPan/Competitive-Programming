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
    LL dp[25]; 
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] * 3 - dp[i - 2]; 
    }
    cout << dp[n] << endl;
    return 0;
}