#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
pi r[200005];
int h[200005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        memset(r, 0, n * sizeof(pi));
        for (int i = 0; i < n; ++i) cin >> h[i];
        r[0].first = h[0] + k; //upper bound
        r[0].second = h[0]; //lower bound
        bool flag = true;
        for (int i = 1; i < n && flag; ++i)
        {
            r[i].first = min(r[i - 1].first + k - 1, h[i] + k - 1 + k);
            r[i].second = max(r[i - 1].second - (k - 1), h[i]);
            if (r[i].first - r[i].second < k) flag = false;
        }
        if (r[n - 1].first < h[n - 1] + k || r[n - 1].second > h[n - 1]) flag = false;
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}