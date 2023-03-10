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
    int a, b, c, m, val;
    cin >> a >> b >> c;
    cin >> m;
    if (m == 0) {cout << "0 0" << endl; return 0;}
    vi usb, ps;
    string str;
    for (int i = 0; i < m; i++)
    {
        cin >> val >> str;
        if (str == "USB") usb.pb(val);
        else ps.pb(val);
    }
    int i1 = 0, i2 = 0;
    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());
    LL tot = 0, cnt = 0;
    while (i1 < a && i1 < usb.size())
    {
        tot += usb[i1++];
        cnt++;
    }
    while (i2 < b && i2 < ps.size())
    {
        tot += ps[i2++];
        cnt++;
    }
    for (int i = 0; i < c && (i1 < usb.size() || i2 < ps.size()); ++i)
    {
        if (i2 == ps.size() || (i1 < usb.size() && usb[i1] < ps[i2]))
        {
            tot += usb[i1++];
        }
        else tot += ps[i2++];
        cnt++;
        //if (i1 == usb.size() && i2 == ps.size()) break;
    }
    cout << cnt << " " << tot << endl;
    return 0;
}