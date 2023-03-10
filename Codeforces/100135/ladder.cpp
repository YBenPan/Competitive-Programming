#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[105];
    for (int i = 2; i <= n + 1; ++i) cin >> a[i]; 
    int dp[105] = {0};
    for (int i = 2; i <= n + 1; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2]) + a[i]; 
    }
    cout << dp[n + 1] << endl;    
    return 0;
}