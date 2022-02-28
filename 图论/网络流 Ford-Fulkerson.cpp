//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e4+7;
const ll inf=0x3f3f3f3f;
struct edge{
	ll to,cap,rev;
};
vector<edge>G[MAX];
int used[5005];
void add_edge(ll from,ll to,ll cap){
	G[from].push_back({to,cap,G[to].size()});
	G[to].push_back({from,0,G[from].size()-1});
}
int dfs(ll v,ll t,ll f){
	used[v]=1;
	if(v==t)return f;
	for(edge &e:G[v]){ //引用 
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		} 
	}
	return 0;
} 
ll max_flow(ll s,ll t){           // Ford-Fulkerson
	ll flow=0;
	while(1){
		memset(used,0,sizeof(used));
		ll f=dfs(s,t,inf);
		if(f==0)break;
		flow+=f;
	}
	return flow;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	ll n,m,s,t;cin>>n>>m>>s>>t;
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	cout<<max_flow(s,t);
   return 0;
} 