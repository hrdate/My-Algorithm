
http://acm.hdu.edu.cn/showproblem.php?pid=2586
HDU 2586 How far away? 
——————————————————————————
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
#define inf 0x3f3f3f3f
using namespace std;
const int mod=1e9+7;
const int MAX=50007;
using namespace std;
vector<int>v[MAX],w[MAX];

int fa[MAX][31], cost[MAX][31], dep[MAX];
int n, m , N; //点数，边数 ,最多跳的次数 
int a, b, c;
void dfs(int root, int fno) {
  fa[root][0] = fno;
  dep[root] = dep[fa[root][0]] + 1;
  for (int i = 1; i < 31; ++i) {    //自下而上，fa[root][i]表示root的第2^i个祖先 
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
    cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
  }
  int sz = v[root].size();//当前根的节点数 
  for (int i = 0; i < sz; ++i) {
    if (v[root][i] == fno) continue;
    cost[v[root][i]][0] = w[root][i];
    dfs(v[root][i], root);  //换根再次进行dfs 
  }
}
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)   //先向上调整深度较大的点，令他们深度相同
    if (tmp & 1) ans += cost[y][j], y = fa[y][j];
  if (y == x) return ans; //深度相同时是同个点 
  for (int j = 30; j >= 0 && y != x; --j) {  //深度相同,共同向上跳转，直到相遇 
    if (fa[x][j] != fa[y][j]) {
      ans += cost[x][j] + cost[y][j];
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  ans += cost[x][0] + cost[y][0];
  return ans;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		memset(fa,0,sizeof(fa));
		memset(cost,0,sizeof(cost));
		memset(dep,0,sizeof(dep));
	  	cin>>n>>m;
	  	//N = floor(log(n + 0.0) / log(2.0));
	  	for(int i=0;i<=n+1;i++)v[i].clear(),w[i].clear();
		for(int i=1;i<=n-1;i++){
	   		cin>>a>>b>>c; 
		    v[a].push_back(b); v[b].push_back(a);
		    w[a].push_back(c); w[b].push_back(c);
		}
		dfs(1,0);
	  	for (int i=0;i<m;i++) {
	    	cin>>a>>b;
	    	cout<<lca(a,b)<<endl;
	  	}
	}
	
  return 0;
}