#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
pair<LL, LL> pf[205]; 
LL dp[2][205][5200]; 
LL a[205]; 
pair<LL, LL> getFactor(LL x)
{
    LL x1 = x;
    LL cnt2 = 0, cnt5 = 0;
    while (x1 % 2 == 0)
    {
        x1 /= 2;
        cnt2++; 
    }
    while (x1 % 5 == 0)
    {
        x1 /= 5;
        cnt5++;
    }
    return {cnt2, cnt5};
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k; 
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i]; 
        pf[i] = getFactor(a[i]); 
        //cout << a[i] << " " << pf[i].first << " " << pf[i].second << endl;
    }
    for (int j = 0; j <= k; ++j) for (int p = 0; p < 5200; ++p) dp[0][j][p] = -1E16;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j) for (int p = 0; p < 5200; ++p) dp[i & 1][j][p] = -1E16;
        for (int j = 0; j <= k; ++j)
        {
            //cout << i << " " << j << ": ";
            for (int p = 0; p < 5200; ++p)
            {
                if (p >= pf[i].second && j >= 1) dp[i & 1][j][p] = max(dp[i & 1][j][p], dp[(i - 1) & 1][j - 1][p - pf[i].second] + pf[i].first); 
                dp[i & 1][j][p] = max(dp[i & 1][j][p], dp[(i - 1) & 1][j][p]); 
                //if (p <= 10) cout <<  dp[i & 1][j][p] << " ";
            }
            //cout << endl;
        }
    } 
    LL maxx = 0;
    for (LL i = 0; i < 5200; ++i) maxx = max(maxx, min(i, dp[n & 1][k][i]));
    cout << maxx << endl;
    return 0;
}