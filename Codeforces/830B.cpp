#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
set<LL> loc[100005];
LL a[100005], r[100005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        loc[a[i]].insert(i);
    }
    sort(a + 1, a + n + 1);
    LL cur = n, ans = n, fnd = 1;
    for (int i = 1; i <= n; ++i)
    {
        auto k = loc[a[i]].lower_bound(fnd);
        
        if (k == loc[a[i]].end())
        {
            fnd = 1; 
            ans += cur;
            k = loc[a[i]].lower_bound(fnd);
        }
        fnd = *k;
        loc[a[i]].erase(k);
        cur--;
        //cout << a[i] << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}