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
  tree[treeNode] = max(tree[2 * treeNode + 1], tree[2 * treeNode + 2]);
}
LL maxx(int L, int R, int treeNode, int q)
{
  //cout << L << " " << R << " " << treeNode << endl;
  if (L == R && tree[treeNode] >= q) return L;
  else
    {
      int mid = (L + R) / 2;
      if (tree[2 * treeNode + 1] >= q)
        return maxx(L, mid, 2 * treeNode + 1, q);
      else if (tree[2 * treeNode + 2] >= q)
        return maxx(mid + 1, R, 2 * treeNode + 2, q);
      else return -1;
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
  tree[treeNode] = max(tree[2 * treeNode + 1], tree[2 * treeNode + 2]);
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
      cin >> qType;
      if (qType == 2)
        {
          cin >> qA;
          cout << maxx(0, n - 1, 0, qA) << endl;
        }
      else {cin >> qA >> qB; treeSet(qB, 0, n - 1, 0, qA);}
    }
  return 0;
}
