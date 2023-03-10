#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> tree, a;
void buildTree(int L, int R, int node)
{
  if (L == R)
    {
      tree[node] = a[L];
      return;
    }
  int mid = (L + R) / 2;
  buildTree(L, mid, 2 * node + 1);
  buildTree(mid + 1, R, 2 * node + 2);
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
void treeSet(int L, int R, int node, int target)
{
  if (L == R)
    {
      tree[node] = 1 - tree[node];
      return;
    }
  int mid = (L + R) / 2;
  if (target <= mid)
    treeSet(L, mid, 2 * node + 1, target);
  else
    treeSet(mid + 1, R, 2 * node + 2, target);
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
int kth(int L, int R, int node, int k)
{
  //cout << L << " " << R << " " << node << " " << k << endl;
  if (L == R)
    {
      return L;
    }
  int mid = (L + R) / 2;
  if (k < tree[2 * node + 1])
    return kth(L, mid, 2 * node + 1, k);
  else
    return kth(mid + 1, R, 2 * node + 2, k - tree[2 * node + 1]);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int input;
  for (int i = 0; i < n; ++i) {cin >> input; a.push_back(input);}
  int power = 1;
  while (power < n) power *= 2;
  tree.assign(2 * power, 0LL);
  buildTree(0, n - 1, 0);
  int qType, q;
  for (int i = 0; i < m; ++i)
    {
      cin >> qType >> q;
      if (qType == 1) treeSet(0, n - 1, 0, q);
      else cout << kth(0, n - 1, 0, q) << endl;
    }
  return 0;
}
