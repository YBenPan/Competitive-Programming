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
        string str;
        cin >> str;
        int n = str.size();
        /*
        seg[n - 1] = n - 1; 
        for (int i = n - 2; i >= 0; --i)
        {
            if (str[i] == str[i + 1]) seg[i] = seg[i + 1];
            else seg[i] = i;
        }
        for (int i = 0; i < n; ++i)
            cout << seg[i] << " ";*/
        int cur_x = 0, cur_y = 0;
        bool found = false;
        for (int i = 0; i < n && !found; ++i)
        {
            //traverse
            if (str[i] == 'L')
                cur_x--;
            else if (str[i] == 'R') 
                cur_x++;
            else if (str[i] == 'D') 
                cur_y--;
            else if (str[i] == 'U') 
                cur_y++;
            
            //sim
            int x = 0, y = 0;
            for (int j = 0; j < n; ++j)
            {
                if (str[j] == 'L' && (x - 1 != cur_x || y != cur_y))
                    x--;
                else if (str[j] == 'R' && (x + 1 != cur_x || y != cur_y))
                    x++;
                else if (str[j] == 'D' && (x != cur_x || y - 1 != cur_y))
                    y--;
                else if (str[j] == 'U' && (x != cur_x || y + 1 != cur_y)) 
                    y++;
            }
            if (x == 0 && y == 0)
            {
                found = true;
                cout << cur_x << " " << cur_y << endl;
            }
        }
        if (!found) cout << "0 0" << endl;
    }
    return 0;
}