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
    int n, k;
    cin >> n >> k;
    int a[200005];
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    LL j = 0, ans = 0;
    map<int, int> m; 
    for (int i = 0; i < n; ++i)
    {
        m[a[i]]++; 
        while (j < i && m.size() > k)
        {
            if (m[a[j]] == 1) 
            {
                m.erase(a[j]); 
            }
            else m[a[j]]--;
            j++; 
        }
        ans += (i - j + 1);
    }   
    cout << ans << endl;
    return 0;
}