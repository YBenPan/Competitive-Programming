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
        LL a, b;
        cin >> a >> b;
        if (a == b) {cout << 2 << endl; continue;}
        if (b > a) {cout << 1 << endl; continue;}
        LL minn = 1E9; 
        for (int i = b; i <= b + 100; ++i)
        {
            if (i == 1) continue;
            LL x = a, cnt = 0;
            while (x > 0) 
            {
                x /= i;
                cnt++;
            }
            //cout << i << " " << cnt << endl;
            minn = min(minn, i - b + cnt); 
        }
        cout << minn << endl;
    }
    return 0;
}