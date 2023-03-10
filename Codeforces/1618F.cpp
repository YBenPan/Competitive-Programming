#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
string toBinary(int a)
{
    string res; 
    while (a > 0)
    {
        res += (char)(a % 2 + '0');
        a /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x == y) {cout << "YES" << endl; return 0;}
    string sx = toBinary(x);
    string sy = toBinary(y);
    string s1 = sx + '1'; reverse(s1.begin(), s1.end());
    string s2 = sx; reverse(s2.begin(), s2.end()); while (s2[0] == '0') s2.erase(0, 1);
    string rs1 = s1; reverse(rs1.begin(), rs1.end());
    string rs2 = s2; reverse(rs2.begin(), rs2.end());
    string str[4] = {s1, s2, rs1, rs2};
    for (auto s : str)
    {
        int st = sy.find(s);
        if (st == string::npos) continue;
        int end = st + s.size() - 1;
        bool local = 1;
        for (int i = 0; i < st; i++) if (sy[i] != '1') local = 0;
        for (int i = end + 1; i < sy.size(); i++) if (sy[i] != '1') local = 0;
        if (local) {cout << "YES" << endl; return 0;}
    }
    cout << "NO" << endl;
    return 0;
}