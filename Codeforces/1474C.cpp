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
        int n;
        cin >> n;
        multiset<int> m, m1; 
        vi a;
        vector<pi> ans; 
        int in1; 
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> in1;
            m1.insert(in1); 
            a.pb(in1); 
        }   
        sort(a.begin(), a.end()); 
        bool found = false; 
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            m = m1; 
            auto it = m.end(); it--; 
            //cout << *it << endl;
            auto it2 = m.find(a[i]); 
            int cur = *it; 
            ans.clear(); 
            ans.pb({*it, *it2}); 
            m.erase(it); 
            m.erase(it2); 
            //for (auto i : m) cout << i << endl;
            //cout << m.size() << endl;
            bool flag = true; 
            while (!m.empty() && flag)
            {
                it = m.end(); it--;
                int target = cur - *it; 
                m.erase(it); 
                it2 = m.find(target); 
                if (it2 == m.end()) flag = false; 
                else 
                {
                    cur = *it; 
                    ans.pb({*it, target}); 
                    //cout << *it << " " << target << endl;
                    
                    m.erase(it2); 
                }
            }
            if (m.size() == 0) 
            {
                cout << "YES" << endl << ans[0].first + ans[0].second << endl;
                for (auto i : ans) cout << i.first << " " << i.second << endl;
                found = true;
                break; 
            }
        }
        if (!found) cout << "NO" << endl;
    }   
    return 0;
}