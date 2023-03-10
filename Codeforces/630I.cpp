#include <bits/stdc++.h>
long long QuickExp(long long n, int k)
{
  long long d = 1;
  while (k > 0)
    {
      if (k % 2)
        d *= n;
      n *= n;
      k /= 2;
    }
  return d;
}
int main()
{
  int n;
  long long sum;
  std::cin >> n;
  if (n == 3)
    {
      std::cout << 24 << std::endl;
      return 0;
    }
  if (n == 4)
    {
      std::cout << 132 << std::endl;
      return 0;
    }
  sum = 4 * (2 * 3 * QuickExp(4, n - 3) + (n - 3) * 9 * QuickExp(4, n - 4));
  std::cout << sum << std::endl;
  return 0;
}
