#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
  vector<int> ans;
  sort(a.begin(), a.end(), greater<int>());
  int m = a[0];
  for (int i = max(1, m - n + 1); i < m; ++i) // current starting candies
    {
      int cnt = n;
      int sum = 1;
      for (int j = 0; j < n; ++j)
        {
          if (a[j] <= i) sum = sum * cnt % p;
          else if (a[j] >= i + cnt) {sum *= 0; break;}
          else sum = sum * (cnt + i - a[j]) % p;
          cnt--;
        }
      if (sum != 0) ans.push_back(i);
    }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+7;
typedef long long ll;
int T,n,p;
int a[maxn];
vector < int > ans;

int f(int x){
    int sum=n,ans=1;
    for(int i=1;i<=n;i++){
        if(a[i]<=x){
           ans=(ans*sum)%p;
        }
        else if(x+sum-a[i]<=0) return 0;
        else ans=(ans*(x+sum-a[i]))%p;
        sum--;
    }
    if(ans==0) return 0;
    return 1;
}
int main(){
         cin>>n>>p;
         for(int i=1;i<=n;i++){
             scanf("%d",&a[i]);
         }
         sort(a+1,a+n+1);
         reverse(a+1,a+n+1);
         int m=a[1];
         for(int i=max(1,m-n+1);i<m;i++){
             if(f(i)) ans.push_back(i);
         }
         cout<<ans.size()<<endl;
         for(auto i: ans) cout<<i<<" ";
         cout<<endl;
}
*/
