#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m, orix, oriy; 
char g[1005][1005], parent[1005][1005];
bool visited[1005][1005] = {0}; 
int mdist[1005][1005], dist[1005][1005], dx[4]{-1, 1, 0, 0}, dy[4]{0, 0, -1, 1}; 
string dir = "LRUD", ans; 
bool success = false; 
queue<pi> q; 
void retrace(int x, int y)
{   
    while (x != orix || y != oriy)
    {
        char curdir = parent[x][y]; 
        if (curdir == 'L') x++; 
        else if (curdir == 'R') x--;
        else if (curdir == 'U') y++; 
        else y--; 
        ans += curdir; 
    }
}
void bfs(int type) // 0: Monster 1: me
{
    while (!q.empty() && !success)
    {
        pi t = q.front(); q.pop(); 
        int tx = t.first, ty = t.second;
        for (int i = 0; i < 4; ++i)
        {
            int x = tx + dx[i], y = ty + dy[i]; 
            if (x < 1 || x > m || y < 1 || y > n) continue;
            if (visited[x][y]) continue; 
            if (g[x][y] == '#') continue; 
            if (type == 0)
            {
                visited[x][y] = true; 
                mdist[x][y] = mdist[tx][ty] + 1; 
                q.push({x, y}); 
            }
            else
            {
                visited[x][y] = true; 
                dist[x][y] = dist[tx][ty] + 1;
                if (mdist[x][y] > dist[x][y]) //good
                {
                    parent[x][y] = dir[i]; 
                    q.push({x, y}); 
                    if (x == 1 || x == m || y == 1 || y == n) //success
                    {
                        success = true; 
                        cout << "YES" << endl;
                        retrace(x, y); 
                        reverse(ans.begin(), ans.end()); 
                        cout << ans.size() << endl;
                        cout << ans << endl;
                    }
                }
            }
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(mdist, 0x3f, sizeof(mdist));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)   
        {
            cin >> g[j][i]; 
            if (g[j][i] == 'M') 
            {
                q.push({j, i}); 
                visited[j][i] = true;
                mdist[j][i] = 0;
            }
            if (g[j][i] == 'A') orix = j, oriy = i; 
        }
    if (orix == 1 || orix == m || oriy == 1 || oriy == n)
    {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }
    bfs(0); 
    memset(visited, 0, sizeof(visited)); 
    visited[orix][oriy] = 1; 
    dist[orix][oriy] = 0; 
    q = queue<pi>(); 
    q.push({orix, oriy}); 
    bfs(1); 
    if (!success) cout << "NO" << endl;
    return 0;
}