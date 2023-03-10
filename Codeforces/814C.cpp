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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int t;
    cin >> t;
    while (t--)
    {
        int m; char c;
        cin >> m >> c;
        int pre[1505] = {0};
        pre[0] = 0;
        for (int i = 1; i <= str.size(); ++i)
        {
            pre[i] = pre[i - 1] + 1;
            if (str[i - 1] == c) pre[i]--;
        }
        int j = 1, maxx = 0;
        for (int i = 1; i <= str.size(); ++i)
        {
            while (j <= n && pre[j] - pre[i - 1] <= m) j++;
            maxx = max(maxx, j - i);
        }
        cout << maxx << endl;
    }
    return 0;
}