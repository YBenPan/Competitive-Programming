#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int ans[100005]; 
vector<bool> visited(100005, 0); 
LL ceiling(LL x, LL div)
{
    return (x + div - 1) / div; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(ans, -1, sizeof(ans)); 
    visited[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        LL t, x, y;
        cin >> t >> x >> y;
        vector<bool> tmp = visited; 
        for (int j = 0; j <= m; ++j)
        {
            if (!visited[j]) continue; 
            LL num = j;
            for (int k = 1; k <= y; ++k)
            {
                if (t == 1)
                    num += ceiling(x, 1E5);    
                else num = ceiling(num * x, 1E5); 
                if (num > m || visited[num]) break; 
                tmp[num] = true; 
                ans[num] = i; 
            }
        }
        visited = tmp; 
    }
    for (int i = 1; i <= m; ++i) 
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}