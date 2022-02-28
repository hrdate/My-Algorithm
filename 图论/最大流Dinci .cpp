//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e4+7;
const unsigned ll inf=LLONG_MAX;
struct edge{
	ll to,cap,rev;
};
vector<edge>G[MAX];  //图的邻接表 
int level[MAX];  //顶点到源点的距离标号 
int iter[MAX];  //当前弧，在其之前的边已经没有用了

//有向图增加一条从from到to的容量为cap的边 
void add_edge(int from,int to,ll cap){
	G[from].push_back( (edge){to,cap,G[to].size()} );
	G[to].push_back( (edge){from,0,G[from].size()-1} ); 
} 

//通过bfs计算从源点出发的距离标号
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

//通过dfs寻找增广路
int dfs(int v,int t,ll f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			ll d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0; 
} 

//求解从s到t的最大流
int max_flow(int s,ll t){
	ll flow=0;
	while(1){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		ll f=0;
		while((f= dfs(s,t,inf)) >0)flow+=f;
	}
	return flow;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,m,s,t; //点、边、源点、汇点 
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		ll u,v,w;cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	cout<<max_flow(s,t);
   return 0;
} 