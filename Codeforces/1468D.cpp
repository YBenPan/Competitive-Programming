#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL t;
    cin >> t;
    while (t--)
    {
        LL n, m, a, b, in1;
        cin >> n >> m >> a >> b;
        multiset<LL> f;
        for (int i = 0; i < m; ++i) 
        {
            cin >> in1; 
            f.insert(in1);
        }
        LL dist;
        if (b > a) dist = b - 1; else dist = n - b; 
        LL time = abs(a - b) - 1;
        if (a == n || a == 1) time++; 
        LL T = 1, cnt = 0; 
        while (true)
        {
            if (T > time || f.empty()) break; 
            LL target = dist - T;
            auto it = f.upper_bound(target);
            if (it == f.begin()) break;
            cnt++; 
            it--;
            f.erase(it); 
            T++; 
        }
        cout << cnt << endl;
    }   
    return 0;
}