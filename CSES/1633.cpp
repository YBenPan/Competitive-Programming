#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[1000005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    
    dp[0] = 1; 
    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 4; 
    dp[4] = 8;
    dp[5] = 16; 
    for (int i = 6; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]+ dp[i - 4] + dp[i - 5] + dp[i - 6]) % MOD;
    }  
    cout << dp[n] << endl;
    return 0;
}