#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> a, tree;
void buildTree(int L, int R, int treeNode)
{
  //cout << L << " " << R << " " << treeNode << endl;
  if (L == R)
    {
      tree[treeNode] = a[L];
      return;
    }
  int mid = (L + R) / 2;
  buildTree(L, mid, 2 * treeNode + 1);
  buildTree(mid + 1, R, 2 * treeNode + 2);
  tree[treeNode] = tree[2 * treeNode + 1] + tree[2 * treeNode + 2];
}
LL sum(int L, int R, int treeNode, int qL, int qR)
{
  //cout << L << " " << R << " " << treeNode << endl;
  if (L >= qL && R <= qR) // included
    {
      return tree[treeNode];
    }
  else if (L > qR || R < qL)
    return 0;
  else
    {
      int mid = (L + R) / 2;
      LL s = 0;
      s += sum(L, mid, 2 * treeNode + 1, qL, qR);
      s += sum(mid + 1, R, 2 * treeNode + 2, qL, qR);
      return s;
    }
}
void treeSet(int num, int L, int R, int treeNode, int target)
{
  if (L == R)
    {
      tree[treeNode] = num;
      return;
    }
  int mid = (L + R) / 2;
  if (target <= mid)
    treeSet(num, L, mid, 2 * treeNode + 1, target);
  else
    treeSet(num, mid + 1, R, 2 * treeNode + 2, target);
  tree[treeNode] = tree[2 * treeNode + 1] + tree[2 * treeNode + 2];
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
  /*for (int i = 0; i < 2 * n - 1; ++i)
    cout << tree[i] << endl;*/
  int qA, qB, qType;
  for (int i = 0; i < m; ++i)
    {
      cin >> qType >> qA >> qB;
      if (qType == 2) cout << sum(0, n - 1, 0, qA, qB - 1) << endl;
      else treeSet(qB, 0, n - 1, 0, qA);
    }
  return 0;
}
