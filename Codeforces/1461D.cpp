#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, q;
LL a[1000005], last[1000005];
vector<LL> ind;
set<LL> sum;
LL solve(int l, int r)
{
    LL s = 0;
    if (l == r) 
    {
        s = a[ind[l]];
        sum.insert(s);
        return s;
    }
    int left = ind[l], right = ind[r], mid = (left + right) / 2;
    int bound_left = last[mid];
    s += solve(l, bound_left);
    s += solve(bound_left + 1, r);
    sum.insert(s);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        memset(a, 0, sizeof(a));
        memset(last, 0, sizeof(last));
        sum.clear(), ind.clear();
        int input;
        for (int i = 0; i < n; ++i) 
        {
            cin >> input; 
            a[input] += input;
        }
        for (int i = 1; i <= 1E6; ++i)
        {
            if (a[i]) ind.pb(i);
            last[i] = ind.size() - 1;
        }
        solve(0, ind.size() - 1);
        for (int i = 0; i < q; ++i)
        {
            cin >> input;
            if (sum.count(input)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}