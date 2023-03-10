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
        int n;
        cin >> n;
        int a[105], maxx = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            maxx = max(maxx, a[i]);
        }
        int r = ceil(maxx / 3.0);
        int ans = r + 1;
        bool res[3][3][105];
        memset(res, 0, sizeof(res));    
        for (int c1 = 0; c1 <= 2; c1++)
            for (int c2 = 0; c2 <= 2; c2++)
            {
                int c3 = r - c1 - c2;
                bool flag = 1;
                for (int i = 0; i < n; i++)
                {
                    bool local = 0;
                    for (int j1 = 0; j1 <= c1; j1++)
                        for (int j2 = 0; j2 <= c2; j2++)
                        {
                            int rem = a[i] - j1 - 2 * j2;
                            if (rem % 3 == 0 && rem <= c3 * 3 && rem >= 0) local = 1;
                        }
                    if (!local) flag = 0;
                }
                if (flag)
                    ans = r;
            }
        cout << ans << endl;
    }
    return 0;
}