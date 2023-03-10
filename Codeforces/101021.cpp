#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>

main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l = 1, r = 1000000; 
    while (l != r)
    {
        int mid = (l + r + 1) / 2; 
        cout << mid << endl;
        fflush(stdout); 
        string str;
        cin >> str;
        if (str == ">=")
            l = mid;
        else
            r = mid - 1;
    }
    cout << "! " << l << endl;
    fflush(stdout); 
    return 0;
}