#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[5005][5005] = {0};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a; cin >> b;
    for (int i = 1; i <= a.size(); ++i) dp[i][0] = i;
    for (int i = 1; i <= b.size(); ++i) dp[0][i] = i;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            dp[i + 1][j + 1] = min(dp[i + 1][j] + 1, min(dp[i][j + 1] + 1, dp[i][j] + (a[i] != b[j]))); 
            //cout << dp[i + 1][j + 1] << " ";
        }
        //cout << endl;
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}