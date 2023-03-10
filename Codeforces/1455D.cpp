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
        int n, x;
        cin >> n >> x;
        int input;
        vi a;
        for (int i = 0; i < n; ++i) 
        {
            cin >> input;
            a.pb(input);
        }
        int index = 0, tot = 0; 
        bool flag = true;
        while (index < n)
        {
            bool sorted = true;
            for (int i = 0; i < n - 1; ++i) 
                if (a[i + 1] < a[i]) sorted = false;
            if (sorted) break;
            int minn = x;
            for (int i = index; i < n; ++i) minn = min(minn, a[i]);
            if (minn != x && minn != a[index]) 
            {
                flag = false;
                break;
            }
            if (minn == x && minn != a[index])
            {
                swap(x, a[index]);
                tot++;
            }
            index++;
        }
        if (flag) cout << tot << endl;
        else cout << -1 << endl;
    }
    return 0;
}