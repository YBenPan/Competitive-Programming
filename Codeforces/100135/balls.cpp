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
    int test[25], maxx = 0; 
    int dp[300005]; 
    memset(dp, 0x3f3f3f3f, sizeof(dp)); 
    vi pyramid;
    dp[1] = 1; 
    for (int i = 0; i < n; ++i)
    {
        cin >> test[i]; 
        maxx = max(maxx, test[i]);
    }
    int sum = 1, x = 1, i = 1;  
    pyramid.pb(1);
    while (sum <= maxx)
    {
        i++; 
        x += i; 
        sum += x;
        dp[sum] = 1; 
        pyramid.pb(sum); 
        //cout << i << " " << x << " " << sum << endl;
    }
    for (int i = 2; i <= maxx; i++)
    {
        for (auto j : pyramid)
        {
            if (j >= i) break;
            dp[i] = min(dp[i], dp[i - j] + 1); 
        }
        //cout << i << " " << dp[i] << endl;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << dp[test[i]] << endl;
    }
    return 0;
}