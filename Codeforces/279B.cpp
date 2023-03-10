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
    int n, t, input;
    cin >> n >> t;
    int pre[100005];
    pre[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        pre[i] = pre[i - 1] + input;
    }
    int i = 1, j = 1;
    int maxx = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (pre[j] - pre[i - 1] <= t && j <= n)
        {
            j++;
        }
        j--;
        maxx = max(maxx, j - i + 1);
    }
    cout << maxx << endl;
    return 0;
}