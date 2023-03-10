#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct route
{
    int x, y;
    char dir; 
};
int n, m;
char g[1005][1005];
route parent[1005][1005]; 
bool visited[1005][1005] = {0}; 
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
char dc[4]{'R', 'L', 'D', 'U'};  
pi start, term;
bool found = false;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; //n is height, m is width
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[j][i];
            if (g[j][i] == 'A') start = {j, i}; 
            else if (g[j][i] == 'B') term = {j, i}; 
        }
    }
    queue<pi> q; 
    visited[start.first][start.second] = true; 
    q.push(start); 
    while (!q.empty())
    {
        pi t = q.front(); q.pop(); 
        int tx = t.first, ty = t.second; 
        //visited[tx][ty] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x = tx + dx[i], y = ty + dy[i];
            if (x < 1 || x > m || y < 1 || y > n) continue;
            if (visited[x][y]) continue;
            if (g[x][y] == '#') continue; 
            visited[x][y] = true;
            parent[x][y] = {tx, ty, dc[i]}; 
            q.push({x, y}); 
            if (x == term.first && y == term.second) found = true;
        }    
    }
    if (!found)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int xx = term.first, yy = term.second; 
    string ans; 
    while (xx != start.first || yy != start.second)
    {
        route cur = parent[xx][yy]; 
        xx = cur.x;
        yy = cur.y;
        ans += cur.dir; 
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
