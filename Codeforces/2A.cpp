#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string str[1005];
  int score[1005];
  int maxx = -100000000;
  map<string, int> count, count1;
  for (int i = 0; i < n; ++i)
    {
      cin >> str[i] >> score[i];
      count[str[i]] += score[i];
    }
  for (auto i : count)
    {
      maxx = max(maxx, i.second);
    }
  //cout << maxx << endl;
  for (int i = 0; i < n; ++i)
    {
      count1[str[i]] += score[i];
      if (count1[str[i]] >= maxx && count[str[i]] == maxx)
        {
          cout << str[i] << endl;
          break;
        }
    }
  return 0;
}
