#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int r[100005], c[100005];
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    int q, a, b; cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (r[a] + c[b] >= n + 1) cout << '#';
        else cout << '.';
    }
    return 0;
}