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
        string str;
        cin >> str;
        int ans = 0, n = str.size();
        for (int i = 0; i < n; ++i)
        {
            if (i + 1 < n && str[i] == str[i + 1] && str[i] != '?') //aa
            {
                str[i + 1] = '?';
                ans++;
            }
            if (i + 2 < n && str[i] == str[i + 2] && str[i] != '?') //bab
            {
                str[i + 2] = '?';
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}