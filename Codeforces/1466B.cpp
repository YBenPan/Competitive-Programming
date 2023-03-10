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
        int n;
        cin >> n;
        int a[100005], b[100005];
        bool pre[200050] = {0};
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
            b[i] = a[i];
        }
        pre[a[0]] = true;
        for (int i = 1; i < n; ++i)
        {
            if (pre[a[i]]) 
            {
                a[i]++;
            }
            pre[a[i]] = true;
        }
        int cnt = 0;
        for (int i = 0; i <= 2 * n + 5; ++i)
        {
            if (pre[i]) cnt++;
        }
        bool pre1[200050] = {0};
        b[0]++;
        pre1[b[0]] = true;
        for (int i = 1; i < n; ++i)
        {
            if (pre1[b[i]])
            {
                b[i]++;
            }
            pre1[b[i]] = true;
        }
        int cnt2 = 0;
        for (int i = 0; i <= 2 * n + 5; ++i)
        {
            if (pre1[i]) cnt2++;
        }
        cout << max(cnt, cnt2) << endl;
    }    
    return 0;
}