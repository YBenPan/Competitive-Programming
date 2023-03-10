#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
map<int, int> pre; //first occurence of balance
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int balance = 0, ans = 0;
    string str;
    cin >> str;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (str[i - 1] == '1') balance++;
        else balance--;
        if (pre.count(balance))
        {
            ans = max(ans, i - pre[balance]);
        }
        else 
        {
            pre[balance] = i;
        }
    }
    //for (auto i : pre) cout << i.first << " " << i.second << endl;;
    cout << ans << endl;
    return 0;
}