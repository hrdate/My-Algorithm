
HDU - 1269 

——————————————————————————————
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e5+7;
// g 是原图，g2 是反图
vector<int>g[MAX],g2[MAX];
vector<int>s;
int vis[MAX],cnt;
int n,m; // 点和边 
void dfs1(int u) {
	vis[u] = 1;
	for (int v : g[u])
    	if (!vis[v]) dfs1(v);
  	s.push_back(u);
}

void dfs2(int u) {
	vis[u] = cnt;
	for (int v : g2[u])
		if (!vis[v]) dfs2(v);
}

void kosaraju() {
  	cnt = 0;
  	memset(vis,0,sizeof(vis));
  	for (int i = 1; i <= n; ++i)
    	if (!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
  	for (int i = n-1; i >= 0; --i)
	    if (!vis[s[i]]) {
		      ++cnt;
		      dfs2(s[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   while(cin>>n>>m){
   		if(n==0&&m==0)break;
   		s.clear();
   		for(int i=0;i<=n;i++)g[i].clear(),g2[i].clear();
   		for(int i=0;i<m;i++){
   			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g2[v].push_back(u);   	
		}
   		kosaraju();
   		if(cnt==1)cout<<"Yes"<<endl;
   		else cout<<"No"<<endl;
   }
   return 0;
} 