#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>

main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[200005], sum = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum <= k) {cout << 0 << endl; continue;}
        sort(a, a + n);   
        int pre = 0, ans = 1E16;
        for (int i = 0; i < n; i++)
        {
            pre += a[i];
            int x = floor((k + a[0] - pre) / (double)(n - i)); 
            int cnt = max((int)0, a[0] - x) + (n - i - 1);
            //cout << i << " " << cnt << endl;
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}