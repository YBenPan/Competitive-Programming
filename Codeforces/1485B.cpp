#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL cnt[100005], pre[100005], a[100005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL n, q, k;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    pre[1] = 0; 
    for (int i = 2; i <= n; ++i)
    {
        cnt[i] = a[i + 1] - a[i - 1] - 2;
        if (i == n) cnt[i] = 0;
        pre[i] = pre[i - 1] + cnt[i]; 
        //cout << pre[i] << " ";
    }
    //cout << endl;
    LL q1, q2;
    for (int i = 0; i < q; ++i)
    {
        cin >> q1 >> q2;
        if (q1 == q2) {cout << k - 1 << endl; continue;}
        LL res = 0;
        res += a[q1 + 1] - 1 - 1; 
        res += k - a[q2 - 1] - 1; 
        if (q2 - q1 > 1) res += pre[q2 - 1] - pre[q1]; 
        cout << res << endl;
    }
    return 0;
}