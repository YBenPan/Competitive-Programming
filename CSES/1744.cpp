#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[505][505]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j) {dp[i][j] = 0; continue;}
            else dp[i][j] = 1E9;
            for (int k = 1; k < i; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1); 
            }
            for (int k = 1; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1); 
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}