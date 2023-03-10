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
    int n, m;
    cin >> n >> m;
    int a[100005], b[100005];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    int maxx = 0, ai = 0, bi = 0;
    for (int i = 0; i < n; ++i)
    {
        while (bi < m && a[i] > b[bi])
        {
            bi++;
        }
        if (bi == m) maxx = max(maxx, a[i] - b[m - 1]);
        else if (bi == 0) maxx = max(maxx, b[0] - a[i]);
        else maxx = max(maxx, min(a[i] - b[bi - 1], b[bi] - a[i]));
        //cout << i << " " << bi << endl;
    }
    cout << maxx << endl;
    return 0;
}