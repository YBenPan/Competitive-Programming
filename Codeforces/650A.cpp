#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  unordered_map<int, int> x, y;
  map<pair<int, int>, int> pairs;
  int input1, input2;
  for (int i = 0; i < n; ++i)
    {
      cin >> input1 >> input2;
      x[input1]++;
      y[input2]++;
      pairs[make_pair(input1, input2)]++;
    }
  long long tot = 0;
  for (unordered_map<int, int>:: iterator i = x.begin(); i != x.end(); ++i)
    {
      long long k = i->second;
      tot += k * (k - 1) / 2;
    }
  for (unordered_map<int, int>:: iterator i = y.begin(); i != y.end(); ++i)
    {
      long long k = i->second;
      tot += k * (k - 1) / 2;
    }
  for (map<pair<int, int>, int> :: iterator i = pairs.begin(); i != pairs.end(); ++i)
    {
      long long k = i->second;
      tot -= k * (k - 1) / 2;
    }
  cout << tot << endl;
  return 0;
}
