/*
https://www.luogu.com.cn/problem/P3376
P3376 【模板】网络最大流

*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
const int MAX=1e4+7;
const ll inf=LLONG_MAX;
struct Edge{
	ll nxt,to,cap;
}edge[2*MAX];
int cnt=1; 
int level[MAX];  //顶点到源点的距离标号
int head[MAX],rad[MAX]; 
void add(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].cap=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
//有向图增加一条从from到to的容量为cap的边 
void add_edge(int from,int to,ll cap){
	add(from,to,cap);
	add(to,from,0);  ////反向边
} 

//通过bfs计算从源点出发的距离标号
bool bfs(int s,int t){
	memset(level,0,sizeof(level));
	queue<int>que;
	level[s]=1;
	que.push(s);
	while(!que.empty()){
		int v=que.front(); que.pop();
		rad[v]=head[v];  //复原当前弧 
		for(int i=head[v];i;i=edge[i].nxt){
			Edge &e=edge[i];
			if(e.cap&&!level[e.to]){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
	return level[t]!=0;
}

//通过dfs寻找增广路
int dfs(int v,int t,ll flow){
	if(v==t)return flow;
	ll tmp=flow,k;
	for(int i=rad[v];i;i=edge[i].nxt){
		Edge &e=edge[i]; rad[v]=i;
		if(e.cap&&level[v]+1==level[e.to]){
			k=dfs(e.to,t,min(tmp,e.cap));
			edge[i].cap-=k;
			edge[i^1].cap+=k;  //反向边 
			tmp-=k;  
			if(!tmp)break;
		}
	}
	return flow-tmp; 
} 

//求解从s到t的最大流
ll Dinic(int s,int t){
	ll max_flow=0;
	while(bfs(s,t))
		max_flow+=dfs(s,t,inf);
	return max_flow;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,m,s,t; //点、边、源点、汇点 
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	cout<<Dinic(s,t);
   return 0;
} 