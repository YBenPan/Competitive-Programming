#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
priority_queue<LL> subject[100005];
set<LL> indx;
LL sum[100005] = {0};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int input1, input2;
    for (int i = 0; i < n; ++i)
    {
        cin >> input1 >> input2;
        subject[input1].push(input2);
        indx.insert(input1);
    }
    LL maxx = 0;
    while (!indx.empty())
    {
        LL local_sum = 0;
        set<LL> cpy = indx;
        for (set<LL>::iterator it = indx.begin(); it != indx.end(); it++)
        {
            LL ind = *it;
            LL t = subject[ind].top();
            sum[ind] += t;
            if (sum[ind] >= 0) local_sum += sum[ind];
            subject[ind].pop();
            if (subject[ind].empty()) cpy.erase(ind);
        }
        maxx = max(maxx, local_sum);
        indx = cpy;
    }
    cout << maxx << endl;
    return 0;
}