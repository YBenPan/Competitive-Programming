#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int input;
  long long sum = 0;
  vector<int> a;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      a.push_back(input);
      sum += input;
    }
  if (sum % 2 == 1)
    {
      cout << "NO" << endl;
      return 0;
    }
  sort(a.begin(), a.end());
  if (a[n - 1] > sum - a[n - 1])
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
