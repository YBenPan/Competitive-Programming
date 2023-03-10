#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct points
{
    int x, y, idx; 
};
vector<points> a; 
//int miny[200005][4]; 
bool cmp(points a, points b)
{
    if (a.x == b.x) 
    {
        return a.y > b.y;
    }
    return a.x < b.x; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int in1, in2;
        int ans[200005]; 
        a.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> in1 >> in2;
            int l = max(in1, in2);
            int r = min(in1, in2);
            a.pb({l, r, i}); 
        }
        sort(a.begin(), a.end(), cmp);
        int minn = 0;
        ans[a[0].idx] = -1; 
        for (int i = 1; i < n; ++i)
        {
            if (a[minn].y < a[i].y) 
            {
                ans[a[i].idx] = a[minn].idx + 1; 
            }
            else 
            {
                minn = i; 
                ans[a[i].idx] = -1;
            }
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}