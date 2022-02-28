/*
P2071 座位安排
https://www.luogu.com.cn/problem/P2071
已知车上有N排座位，有N*2个人参加省赛，每排座位只能坐两人，
且每个人都有自己想坐的排数，问最多使多少人坐到自己想坐的位置。

*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
const int MAX=2e4+7;
const ll inf=LLONG_MAX;
struct Edge{
	ll nxt,to,cap;
}edge[4*MAX];
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
	int n;cin>>n; //源点 
	int s=3*n+1,t=3*n+2; //源点、汇点 
	for(int i=1;i<=2*n;i++){
		int s1,s2;cin>>s1>>s2;
		add_edge(i,s1+2*n,1);    // 人与座位连接
		add_edge(i,s2+2*n,1);
	}
	for(int i=1;i<=2*n;i++)add_edge(s,i,1);   // 源点s和点i连接 
	for(int i=1;i<=n;i++)add_edge(i+2*n,t,2); // 点i和汇点连接 
	cout<<Dinic(s,t);
   return 0;
} 