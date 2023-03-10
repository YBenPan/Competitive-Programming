#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[10][10]; 
    for (int i = 8; i >= 1; --i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            cin >> a[i][j]; 
        }
    }
    int dp[10][10]; 
    dp[1][1] = 0;
    for (int i = 1; i <= 8; ++i) //rows
    {
        for (int j = 1; j <= 8; ++j) //columns
        {
            if (i == 1 && j == 1) continue; 
            dp[i][j] = 1E9; 
            if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]); 
            if (i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]); 
            if (i > 1 && j > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
            dp[i][j] += a[i][j]; 
        }
    }
    cout << dp[8][8] << endl;
    return 0;
}