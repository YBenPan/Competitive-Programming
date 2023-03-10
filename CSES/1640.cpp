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
    int n, x;
    cin >> n >> x;
    vector<pi> val;
    int input;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        val.pb({input, i});
    }
    sort(val.begin(), val.end(), cmp);
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = val[i].first + val[j].first; 
        if (sum == x)
        {
            cout << val[i].second << " " << val[j].second << endl;
            return 0;
        }
        if (sum < x)
            i++;
        else j--;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
