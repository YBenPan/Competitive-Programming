#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool check_prime(int x)
{
  for (int i = 2; i <= sqrt(x); ++i)
    if (x % i == 0)
      return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  if (check_prime(n)) {cout << 1 << endl; return 0;}
  if (n % 2 == 0) {cout << 2 << endl; return 0;}
  if (check_prime(n - 2)) {cout << 2 << endl; return 0;}
  else cout << 3 << endl;
  /*()int prime = n;
  while (prime > 1)
    {
      prime -= 2;
      if (check_prime(prime))
        {
          int x = n - prime;
          cout << x / 2 + 1 << " " << prime << endl;
          break;
        }
    }*/
  return 0;
}
