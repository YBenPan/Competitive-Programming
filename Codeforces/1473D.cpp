#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[200005], premin[200005], premax[200005], sufmin[200005], sufmax[200005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        
        //construct control arrays
        a[0] = 0; premin[0] = 0; premax[0] = 0; sufmin[n + 1] = 1E9; sufmax[n + 1] = -1E9;
        for (int i = 1; i <= n; ++i) 
        {   
            if (str[i - 1] == '+') a[i] = a[i - 1] + 1; 
            else a[i] = a[i - 1] - 1;
            premin[i] = min(premin[i - 1], a[i]);
            premax[i] = max(premax[i - 1], a[i]); 
        }   
        for (int i = n; i >= 1; --i)
        {
            sufmax[i] = max(sufmax[i + 1], a[i]); 
            sufmin[i] = min(sufmin[i + 1], a[i]); 
        }
        int l, r;
        for (int i = 0; i < m; ++i)
        {
            cin >> l >> r;
            int leftmin = premin[l - 1]; 
            int leftmax = premax[l - 1];
            int rightmin = sufmin[r + 1]; 
            int rightmax = sufmax[r + 1]; 
            if (l > 1 && r == n)
            {
                cout << leftmax - leftmin + 1 << endl; 
                continue; 
            }
            if (l == 1 && r == n) {cout << 1 << endl; continue;}
            int diff = a[r] - a[l - 1];
            rightmin -= diff; rightmax -= diff; 
            int minn = min(leftmin, rightmin), maxx = max(leftmax, rightmax); 
            cout << maxx - minn + 1 << endl;
        }
    }   
    return 0;
}