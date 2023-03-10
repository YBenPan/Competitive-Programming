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
struct coord
{
    int l, r, i;
};
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--)
    {
        int n, m;
        cin >> n >> m;
        string str;
        int a[1005], prev[1005];
        memset(prev, -1, sizeof(prev));
        map<string, coord> two, three;
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            for (int j = 1; j <= m - 1; j++)
            {
                string two_str = str.substr(j - 1, 2), three_str = str.substr(j - 1, 3);
                two[two_str] = {j, j + 1, i};
                if (j != m - 1) three[three_str] = {j, j + 2, i};
            }
        }
        cin >> str;
        prev[0] = -1;
        prev[1] = {two.find(str.substr(0, 2)) != two.end() ? 0 : -1};
        prev[2] = {three.find(str.substr(0, 3)) != three.end() ? 0 : -1};
        for (int i = 3; i < m; i++)
            if (prev[i - 2] != -1 && two.find(str.substr(i - 1, 2)) != two.end())
                prev[i] = i - 2;
            else if (prev[i - 3] != -1 && three.find(str.substr(i - 2, 3)) != three.end())
                prev[i] = i - 3;
        if (prev[m - 1] == -1) {cout << -1 << endl; continue;}
        int cur = m - 1;
        vector<coord> ans;
        for (cur; cur != -1;)
        {
            int last = prev[cur];
            if (last == 0) last = -1;
            if (cur - last == 2) ans.pb(two[str.substr(last + 1, 2)]);
            else ans.pb(three[str.substr(last + 1, 3)]);
            cur = last;            
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i.l << " " << i.r << " " << i.i << endl;
    }
    return 0;
}