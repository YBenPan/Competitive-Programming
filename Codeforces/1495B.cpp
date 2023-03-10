#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<pi> pt;
int a[100005]; 
map<int, int> seq;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    //Find all monotone sequences
    int dir = a[1] < a[2]; //0: decreasing 1: increasing
    pt.pb({1, !dir}); 
    for (int i = 2; i < n; ++i)
    {
        if (dir == 0 && a[i + 1] > a[i])
        {
            pt.pb({i, 0}); 
            dir = 1;
        }
        else if (dir == 1 && a[i + 1] < a[i])
        {
            pt.pb({i, 1}); 
            dir = 0;
        }
    }
    if (a[n - 1] < a[n]) pt.pb({n, 1});
    else pt.pb({n, 0});
    //Check if this satisfies the constraints
    int maxx = 0, maxx_dist = 0;
    bool found = false;
    for (int i = 1; i < pt.size(); ++i)
    {
        pi cur = pt[i], next = pt[i + 1], prev = pt[i - 1];
        int dist = cur.first - prev.first + 1; 
        seq[dist]++; 
        maxx = max(maxx, dist);
        if (cur.second == 0 || i == pt.size() - 1) continue; 
        if (dist == next.first - cur.first + 1 && dist % 2 == 1)
        {
            maxx_dist = max(maxx_dist, dist); 
            found = true;
        }
    }
    if (maxx == maxx_dist && seq[maxx] == 2 && found) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}