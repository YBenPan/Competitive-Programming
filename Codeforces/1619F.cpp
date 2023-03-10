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
        int n, m, k;
        cin >> n >> m >> k;
        int p = (n % m) * ceil(n / (double)m);
        for (int i = 0; i < k; i++)
        {
            int num = i * p % n;
            for (int j = 0; j < n % m; j++)
            {
                int cnt = ceil(n / (double)m);
                cout << cnt << " ";
                for (int k = 0; k < cnt; k++) 
                {
                    cout << num + 1 << " ";
                    num = (num + 1) % n;
                }
                cout << endl;
            }
            for (int j = 0; j < (m - n % m); j++)
            {
                int cnt = floor(n / (double)m);
                cout << cnt << " ";
                for (int k = 0; k < cnt; k++)
                {
                    cout << num + 1 << " ";
                    num = (num + 1) % n;
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}