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
    int t;
    cin >> t;
    while (t--)
    {   
        int n, w;
        cin >> n >> w;
        int a[100005];
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n, greater<int>()); 
        multiset<int> s;
        for (int i = 0; i < n; ++i)
        {
            auto it = s.lower_bound(a[i]); 
            if (it == s.end())
            {
                s.insert(w - a[i]);
            }
            else 
            {
                int tmp = *it; 
                s.erase(it); 
                s.insert(tmp - a[i]); 
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}