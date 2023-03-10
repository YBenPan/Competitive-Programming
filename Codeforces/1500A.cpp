#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, a[200005];
bool visited[5000005] = {0};
pi s[5000005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i]; 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int sum = a[i] + a[j];
            if (visited[sum])
            {
                if (i != s[sum].first && i != s[sum].second && j != s[sum].first && j != s[sum].second)
                {
                    //found answer
                    cout << "YES" << endl;
                    cout << i << " " << j << " " << s[sum].first << " " << s[sum].second << endl;
                    return 0;
                }
            }
            else 
            {
                visited[sum] = 1;
                s[sum].first = i;
                s[sum].second = j;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}