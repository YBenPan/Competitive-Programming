#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vi sq;
bool prime(int x)
{
    for (int i = 2; i <= sqrt(x); ++i) 
        if (x % i == 0) return false;
    return true; 
}
int reduce(int x)
{
    for (int i = 0; i < sq.size() && i * i <= x; ++i)
        while (x % sq[i] == 0)
            x /= sq[i]; 
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 2; i * i <= 10000000; ++i)
        if (prime(i)) 
            sq.pb(i * i); 
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, input;
        cin >> n >> k;
        int a[200005];
        for (int i = 1; i <= n; ++i) 
        {
            cin >> input;
            a[i] = reduce(input); 
        }
        set<int> rep; 
        int ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (rep.find(a[i]) != rep.end()) 
            {
                ans++; 
                rep.clear(); 
            }
            rep.insert(a[i]); 
        }
        cout << ans << endl;
    }
    return 0;
}