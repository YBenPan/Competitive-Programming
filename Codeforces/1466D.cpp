#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int w[100005];
int g[100005] = {0};
priority_queue<pi> q;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, input1, input2;
        cin >> n;
        memset(g, 0, (n + 5) * sizeof(int));
        memset(w, 0, (n + 5) * sizeof(int));
        LL sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> w[i];
            sum += w[i];
        }
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> input1 >> input2;
            g[input1]++;
            g[input2]++;
        }
        for (int i = 1; i <= n; ++i)
        {
            int s = g[i]; 
            if (s > 1) q.push({w[i], s - 1});
        }
        cout << sum << " ";
        while (!q.empty())
        {
            pi t = q.top();
            for (int i = 0; i < t.second; ++i)
            {
                sum += t.first; 
                cout << sum << " ";
            }
            q.pop();
        }
        cout << endl;
    }   
    return 0;
}