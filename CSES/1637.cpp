#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[1000005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 9; ++i) dp[i] = 1;
    for (int i = 10; i <= n; ++i)
    {
        int a = i;
        dp[i] = 1E9; 
        while (a)
        {
            int digit = a % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1); 
            a /= 10;
        }
    }
    cout << dp[n] << endl; 
    return 0;
}