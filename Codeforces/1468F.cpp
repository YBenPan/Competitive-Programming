#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
map<pi, int> m; 
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b); 
    }
    return a; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        m.clear(); 
        int n;
        cin >> n; 
        int in1, in2, in3, in4; 
        for (int i = 0; i < n; ++i)
        {
            cin >> in1 >> in2 >> in3 >> in4; 
            int c1 = in3 - in1, c2 = in4 - in2; 
            if (c1 == 0 && c2 == 0) continue; 
            int g = gcd(abs(c1), abs(c2)); 
            c1 /= g, c2 /= g; 
            m[{c1, c2}]++; 
        }
        LL cnt = 0;
        for (auto i : m)
        {
            pi p = i.first; 
            int a = -p.first, b = -p.second; 
            cnt += (LL)i.second * m[{a, b}]; 
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}