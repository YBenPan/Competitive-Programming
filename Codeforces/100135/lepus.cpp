#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int dp[2005]; 
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int add; 
        dp[i] = -1;
        if (str[i] == 'w') continue;
        else if (str[i] == '"') add = 1;
        else add = 0;
        if (i >= 1 && dp[i - 1] != -1) dp[i] = max(dp[i], dp[i - 1] + add); 
        if (i >= 3 && dp[i - 3] != -1) dp[i] = max(dp[i], dp[i - 3] + add); 
        if (i >= 5 && dp[i - 5] != -1) dp[i] = max(dp[i], dp[i - 5] + add);
    }
    //for (int i = 0; i < n; ++i) cout << dp[i] << " ";
    cout << dp[n - 1] << endl;
    return 0;
}