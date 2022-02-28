///
///
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e3+7;
const int mod=1e9+7;
const ll inf=0x3f3f3f3f3f;
struct Point{
	ll x,y,r,w;
}cir[MAX];
vector<ll>g[MAX]; //存图 

ll dis(Point a,Point b){
	ll dx=a.x-b.x,dy=a.y-b.y;
	return dx*dx+dy*dy;
} 

ll n,dfn[MAX],dfncnt,low[MAX],st[MAX],in_stack[MAX],top,cost[MAX];
int scc[MAX], sc;  // 结点 i 所在 强连通分量scc 的编号 
int siz[MAX];       // 强连通 i 的大小

void tarjan(int u){
	st[++top]=u;   
	dfn[u]=low[u]=++dfncnt;
	in_stack[u]=1;
	for(int v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]); 
		}
		else if(in_stack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		sc++;
		while(1){
			ll now=st[top--];
			in_stack[now]=0;
			scc[now]=sc;
			siz[sc]++;
			cost[sc]=min(cost[sc],cir[now].w);
			if(now==u)break; 
		}
	}
}

void init(){
	for(int i=1;i<=n;i++)g[i].clear();
	dfncnt=top=sc=0;
	memset(dfn,0,sizeof(dfn)); 
	memset(low,0,sizeof(low));
	memset(in_stack,0,sizeof(in_stack));
	memset(cost,inf,sizeof(cost));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int _,cas=1;cin>>_;
	while(_--){
		cin>>n; init();
		for(int i=1;i<=n;i++)cin>>cir[i].x>>cir[i].y>>cir[i].r>>cir[i].w;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(dis(cir[i],cir[j])<=cir[i].r*cir[i].r)
					g[i].push_back(j);
			}
		} 
		for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
		ll ans=0;
		vector<int>edge(n+1,0);
		for(int i=1;i<=n;i++){
			for(auto x:g[i])
				if(scc[x]!=scc[i])edge[scc[x]]++;
		}
		for(int i=1;i<=sc;i++)
		if(!edge[i])ans+=cost[i];
		cout<<"Case #"<<cas++<<": "<<ans<<endl;
	}
   return 0;
} 