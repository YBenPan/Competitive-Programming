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
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<string> g, ans;
vector<vector<int>> val;
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        g.clear(); g.resize(n);
        ans.clear(); ans.resize(n);
        val.clear(); val.resize(n, vi(m));
        pi lab;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char ch; cin >> ch;
                g[i].pb(ch);
                ans[i].pb(ch);
                if (ch == 'L') lab = {i, j};
            }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                val[i][j] = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    val[i][j] += (g[x][y] == '.' || g[x][y] == 'L');
                }
            }
        }
        queue<pi> q;
        q.push(lab);
        val[lab.fi][lab.se] = -1;
        while (!q.empty())
        {
            pi p = q.front();
            q.pop();
            int x = p.fi, y = p.se;
            if (p != lab) ans[x][y] = '+';
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || g[xx][yy] == '#') continue;
                if (val[xx][yy] != -1) val[xx][yy]--;
                if (val[xx][yy] == 1 || val[xx][yy] == 0) 
                {
                    q.push({xx, yy});
                    val[xx][yy] = -1;
                }
            }
        }        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) cout << ans[i][j];
            cout << "\n";
        }
    }
    return 0;
}