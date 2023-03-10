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
        int n, k;
        cin >> n >> k;
        int a, b, c;
        if (n % 2) a = n / 2, b = n / 2, c = 1;       
        else if (n % 4 == 0) a = n / 2, b = n / 4, c = n / 4;
        else a = n / 2 - 1, b = n / 2 - 1, c = 2;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}