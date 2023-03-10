#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL n, k;
LL a[200005];
//median is at n / 2
bool check(int num)
{
    if (num <= a[n / 2]) return true;
    LL cnt = 0;
    for (int i = n / 2; i < n; ++i)
        cnt += max((LL)0, num - a[i]);
    return cnt <= k;
}
LL binary_search()
{
    LL l = 1, r = 2E9;
    LL ans = 0;
    while (l <= r)
    {
        LL mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cout << binary_search() << endl;
    return 0;
}