#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool cmp(const pi &a, const pi &b)
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, input;
    cin >> n >> x;
    vector<pi> a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        a.pb({input, i});
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++i)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = a[i].first + a[l].first + a[r].first;
            if (sum == x) 
            {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
                return 0;
            }
            else if (sum < x)
                l++;
            else 
                r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}