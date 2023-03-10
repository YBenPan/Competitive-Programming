#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      vector<int> a(n);
      bool mex_arr[1005];
      memset(mex_arr, false, sizeof(mex_arr));
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          mex_arr[a[i]] = true;
        }
      int mex = 0;
      for (int i = 0; i <= n; ++i)
        if (mex_arr[i] == false)
          {mex = i; break;}
      bool inc = true;
      for (int i = 1; i < n && inc; ++i)
        {
          if (a[i] < a[i - 1]) inc = false;
        }
      if (inc) {cout << 0 << endl << endl; continue;}
      bool flag = false; // false: 1 to n. true: 0 to n - 1
      vector<int> ans;
      vector<bool> fixed(n);
      while (true)
        {
          memset(mex_arr, false, sizeof(mex_arr));
          for (int i = 0; i < n; ++i)
            mex_arr[a[i]] = true;
          for (int i = 0; i <= n; ++i)
            if (mex_arr[i] == false)
              {mex = i; break;}
          if (mex == n)
            {
              int pos;
              for (int i = 0; i < n; ++i)
                if (!fixed[i])
                  pos = i;
              a[pos] = n;
              ans.push_back(pos);
            }
          else
            {
              a[mex] = mex;
              fixed[mex] = true;
              ans.push_back(mex);
            }
          inc = true;
          //cout << a[0] << " ";
          for (int i = 1; i < n; ++i)
            {
              if (a[i] < a[i - 1]) inc = false;
              //cout << a[i] << " ";
            }
          //cout << endl;
          if (inc) break;
        }
      cout << ans.size() << endl;
      for (int i : ans) cout << i + 1 << " ";
      cout << endl;
    }

  return 0;
}
