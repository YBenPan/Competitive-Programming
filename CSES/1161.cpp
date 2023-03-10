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
    int x, n;
    cin >> x >> n;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        pq.push(input);
    }
    LL sum = 0;
    while (pq.size() > 1)
    {
        LL t1 = pq.top(); 
        pq.pop();
        LL t2 = pq.top();
        pq.pop();
        sum += (t1 + t2);
        pq.push(t1 + t2); 
    }
    cout << sum << endl;
    return 0;
}