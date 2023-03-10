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
        int a[300005]; 
        vi hill, valley; 
        bool ishill[300005] = {0}, isval[300005] = {0}; 
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }
        for (int i = 1; i < n - 1; ++i)
        {
            if (a[i] > a[i + 1] && a[i] > a[i - 1]) hill.pb(i), ishill[i] = true;  
            if (a[i] < a[i + 1] && a[i] < a[i - 1]) valley.pb(i), isval[i] = true; 
        }
        int minn = 0; 
        for (int i = 1; i < n - 1; ++i)
        {
            int ind = i, ch = a[ind]; 
            int cnt = 0, now = 0; 
            if (ishill[ind - 1] || isval[ind - 1]) cnt++; 
            if (ishill[ind] || isval[ind]) cnt++;
            if (ishill[ind + 1] || isval[ind + 1]) cnt++; 
            a[ind] = a[ind - 1]; 
            for (int j = ind - 1; j <= ind + 1; ++j)
            {
                if (j <= 0 || j >= n - 1) continue; 
                if (a[j] > a[j + 1] && a[j] > a[j - 1]) now++; 
                if (a[j] < a[j + 1] && a[j] < a[j - 1]) now++; 
            }
            minn = min(minn, now - cnt); 
            a[ind] = a[ind + 1]; 
            now = 0;
            for (int j = ind - 1; j <= ind + 1; ++j)
            {
                if (j <= 0 || j >= n - 1) continue; 
                if (a[j] > a[j + 1] && a[j] > a[j - 1]) now++; 
                if (a[j] < a[j + 1] && a[j] < a[j - 1]) now++; 
            }
            minn = min(minn, now - cnt); 
            a[ind] = ch;
        }       
        cout << hill.size() + valley.size() + minn << endl;
    }   
    return 0;
}