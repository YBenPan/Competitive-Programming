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
      int n, k;
      cin >> n >> k;
      string str;
      cin >> str;
      vector<int> pos;
      for (int i = 0; i < str.size(); i++)
        if (str[i] == '1') pos.push_back(i);
      int tot = 0;
      int diff;
      for (int i = 1; i < pos.size(); ++i)
        {
          int high = pos[i];
          int low = pos[i - 1];
          diff = high - low - 1 - 2 * k;
          if (diff > 0)
            {
              tot += (diff / (k + 1) + 1);
              if (diff % (k + 1) == 0) tot--;
            }
        }
      //cout << tot << endl;
      if (pos.size() == 0)
        {
          diff = n;
          tot += (diff / (k + 1) + 1);
          if (diff % (k + 1) == 0) tot--;
        }
      if (pos.size() > 0)
        {
          diff = pos[0] - k;
          if (diff > 0)
            {
              tot += (diff / (k + 1) + 1);
              if (diff % (k + 1) == 0) tot--;
            }
          diff = n - pos[pos.size() - 1] - 1 - k;
          if (diff > 0)
            {
              tot += (diff / (k + 1) + 1);
              if (diff % (k + 1) == 0) tot--;
            }
        }
      cout << tot << endl;
    }

  return 0;
}
