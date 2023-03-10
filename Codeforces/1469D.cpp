#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<pi> ans;
void solve(int s)
{
    if (s == 2) return; 
    int x = s - 1;
    while (x > 1)
    {
        if (x - 1 < ceil(double(s) / (x - 1)))
        {
            ans.pb({s, x});
            ans.pb({s, x});
            break;
        }
        ans.pb({x, s});
        x--;
    }
    //x++;
    //ans.pb({x, s}); ans.pb({x, s});
    solve(x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        int n;
        cin >> n;   
        solve(n);
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}