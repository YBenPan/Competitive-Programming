#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct op
{
    int x1, y1, x2, y2, x3, y3;
};
vector<op> v;
void print(int a, int b, int c, int d, int e, int f)
{
    v.pb({a + 1, b + 1, c + 1, d + 1, e + 1, f + 1});
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        v.clear();
        int n, m;
        cin >> n >> m;
        char input;
        int g[205][205];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                {
                    cin >> input;
                    g[i][j] = input - '0';
                    //cout << g[i][j] << " ";
                }
            //cout << endl;
        }
        // clean first n - 2 rows
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (g[i][j] == 1)
                {
                    if (j != m - 1)
                    {
                        g[i][j] = 0;
                        g[i][j + 1] = 1 - g[i][j + 1];
                        g[i + 1][j] = 1 - g[i + 1][j];
                        print(i, j, i, j + 1, i + 1, j);
                    }
                    else
                    {
                        g[i][j] = 0;
                        g[i + 1][j - 1] = 1 - g[i + 1][j - 1];
                        g[i + 1][j] = 1 - g[i + 1][j];
                        print(i, j, i + 1, j - 1, i + 1, j);
                    }
                }
                //cout << g[i][j] << " ";
            }
            //cout << endl;
        }
        //clean last two rows
        for (int j = 0; j < m - 1; ++j)
        {
            if (g[n - 2][j] == 1)
            {
                g[n - 2][j] = 0;
                g[n - 2][j + 1] = 1 - g[n - 2][j + 1];
                g[n - 1][j + 1] = 1 - g[n - 1][j + 1];
                print(n - 2, j, n - 2, j + 1, n - 1, j + 1);
            }
            if (g[n - 1][j] == 1)
            {
                g[n - 1][j] = 0;
                g[n - 2][j + 1] = 1 - g[n - 2][j + 1];
                g[n - 1][j + 1] = 1 - g[n - 1][j + 1];
                print(n - 1, j, n - 2, j + 1, n - 1, j + 1);
            }
        }
        if (g[n - 1][m - 1] == 1 && g[n - 2][m - 1] == 1)
        {
            //g[n - 2][m - 2] = 1 - g[n - 2][m - 2]; g[n - 2][m - 1] = 1 - g[n - 2][m - 1]; g[n - 1][m - 2] = 1 - g[n - 1][m - 2];
            //g[n - 2][m - 2] = 1 - g[n - 2][m - 2]; g[n - 1][m - 2] = 1 - g[n - 1][m - 2]; g[n - 1][m - 1] = 1 - g[n - 1][m - 1]; 
            print(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
            print(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
        }
        else if (g[n - 1][m - 1] == 0 && g[n - 2][m - 1] == 1)
        {
            print(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
            print(n - 2, m - 1, n - 1, m - 2, n - 1, m - 1);
            print(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
        }
        else if (g[n - 1][m - 1] == 1 && g[n - 2][m - 1] == 0)
        {
            print(n - 2, m - 2, n - 1, m - 2, n - 2, m - 1);
            print(n - 2, m - 1, n - 1, m - 2, n - 1, m - 1);
            print(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
        }
        cout << v.size() << endl;
        for (auto i : v)
        {
            cout << i.x1 << " " << i.y1 << " " << i.x2 << " " << i.y2 << " " << i.x3 << " " << i.y3 << endl;
        }
    }
    return 0;
}