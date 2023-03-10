#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool area[200005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[55];
        for (int i = 0; i < n; ++i) cin >> a[i];
        memset(area, 0, sizeof(area));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j) continue;
                int calc = abs(a[j] - a[i]); 
                area[calc] = true;
            }
        }
        int cnt = 0;
        for (int i = 1; i < 200000; ++i)
        {
            if (area[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}