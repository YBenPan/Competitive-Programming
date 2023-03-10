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
    LL a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) 
    {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    LL ans, l = 1, r = 1E10;
    while (l <= r)
    {
        LL mid = (l + r) / 2;
        if ((1 + mid) * mid <= 2 * (a + b)) 
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    bool numa[100005] = {false};
    int maxx = ans;
    while (a >= maxx && maxx > 0)
    {
        a -= maxx; 
        numa[maxx] = true;
        maxx--;
    }
    numa[a] = true;
    vi ansa, ansb;
    for (int i = 1; i <= ans; ++i)
    {
        if (numa[i]) ansa.pb(i);
        else ansb.pb(i);
    }
    cout << ansa.size() << endl;
    for (auto i : ansa ) cout << i << " ";
    cout << endl;
    cout << ansb.size() << endl;
    for (auto i : ansb) cout << i << " ";
    cout << endl;
    return 0;
}