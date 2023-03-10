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
    int a[3], b[3], win[3], lose[3]; 
    for (int i = 0; i < 3; ++i) cin >> a[i]; 
    for (int i = 0; i < 3; ++i) cin >> b[i]; 
    win[0] = 1, win[1] = 2, win[2] = 0; 
    lose[0] = 2, lose[1] = 0, lose[2] = 1; 

    //calc min
    int res[3]; 
    res[0] = b[0] - (a[0] + a[1]); 
    res[1] = b[1] - (a[1] + a[2]);
    res[2] = b[2] - (a[2] + a[0]); 
    for (int i = 0; i < 3; ++i) 
    {
        if (res[i] >= 0) {cout << res[i] << " "; break;}
        if (i == 2) cout << 0 << " ";
    }
    cout << min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]) << endl;
    return 0;
}