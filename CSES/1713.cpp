#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int divisible[1000005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    //Sieve of Eratosthenes
    for (int i = 2; i <= 1E6; ++i)
    {
        if (!divisible[i])
        {
            for (int j = i; j <= 1E6; j += i)
                divisible[j] = i;
        }
    } 
    
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        int ans = 1;
        while (x > 1)
        {
            int p = divisible[x], cnt = 1;
            //cout << x << " " << p << endl;
            //system("pause");
            while (x % p == 0)
            {
                x /= p;
                cnt++; 
            }
            ans *= cnt; 
        }
        cout << ans << endl;
    }   
    return 0;
}