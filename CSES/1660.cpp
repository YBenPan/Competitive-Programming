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
    int n, x, input;
    cin >> n >> x;
    LL a[200005];
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        a[i] = a[i - 1] + input;
    }
    int i = 1, j = 1; 
    LL tot = 0;
    while (i <= n && j <= n)
    {
        if (a[j] - a[i - 1] == x) {tot++; i++; continue;}
        while (a[j] - a[i - 1] < x && j <= n)
        {
            j++;
            if (a[j] - a[i - 1] == x) {tot++; break;}
        }
        i++;
    }
    cout << tot << endl;
    return 0;
}