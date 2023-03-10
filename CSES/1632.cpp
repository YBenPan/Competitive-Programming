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
    int n, k;
    cin >> n >> k;
    vector<pi> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;
        //first: end time, second: start time
    }
    sort(a.begin(), a.end());
    multiset<int> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        auto pos = s.upper_bound(a[i].second);
        if (pos != s.begin())
        {
            pos--;
            cnt++;
            s.erase(pos);
            s.insert(a[i].first);
        }
        else if (s.size() < k)
        {
            cnt++;
            s.insert(a[i].first);
        }
    }
    cout << cnt << endl;
    return 0;
}