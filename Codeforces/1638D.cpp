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

//dfs from all nodes
// if colors agree, then proceed. else return
struct answer
{
    int x, y, col;
};
answer ans[1000005];
int g[1005][1005];
int n, m, cnt = 0;
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m) return;
    // check if square is good
    int c = 0;
    for (int dx = x; dx <= x + 1; dx++)
        for (int dy = y; dy <= y + 1; dy++)
        {
            if (dx < 1 || dx > n || dy < 1 || dy > m) return;
            if (g[dx][dy] == 0) continue;
            if (c && c != g[dx][dy]) return;
            c = g[dx][dy];
        }
    //good now
    if (c) 
    {
        ans[++cnt] = {x, y, c};
        g[x][y] = 0; g[x + 1][y] = 0; g[x][y + 1] = 0; g[x + 1][y + 1] = 0;
        for (int nx = x - 1; nx <= x + 1; nx++) 
            for (int ny = y - 1; ny <= y + 1; ny++)
                dfs(nx, ny);
    }
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
           dfs(i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
           if (g[i][j]) {cout << -1 << endl; return 0;}
    cout << cnt << endl;
    for (int i = cnt; i >= 1; i--)
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].col << "\n";
    return 0;
}