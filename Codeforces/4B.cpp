#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int d, sumTime;
  cin >> d >> sumTime;
  vector<int> minTime, maxTime;
  int x, y;
  int tot_minTime = 0, tot_maxTime = 0;
  for (int i = 0; i < d; ++i)
    {
      cin >> x >> y;
      minTime.push_back(x);
      maxTime.push_back(y);
      tot_minTime += x;
      tot_maxTime += y;
    }
  if (tot_maxTime < sumTime || tot_minTime > sumTime)
    {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  int diff = sumTime - tot_minTime;
  for (int i = 0; i < d; ++i)
    {
      if (maxTime[i] - minTime[i] >= diff)
        {
          cout << minTime[i] + diff << " ";
          diff = 0;
        }
      else
        {
          diff -= (maxTime[i] - minTime[i]);
          cout << maxTime[i] << " ";
        }
    }
  cout << endl;
  return 0;
}
