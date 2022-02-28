/*
abc191-E
https://atcoder.jp/contests/abc191/tasks/abc191_e
给定一个有向图，对于每一个结点，确定从这个结点出发，
经过一条或多条有向边回到这个结点的最短路径的长度。
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
const int MAX=2005;
const int mod=1e9+7;
const ll inf=0x3f3f3f3f3f;
const double pi=3.1415926535;
ll d[MAX][MAX],loop[MAX]; // 从1到i的距离 
int head[MAX],vis[MAX];
struct Edge{
    ll next,to,w;
}edge[MAX];
int cnt=0;
void add(int u,int v,int w){
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra(int s,int n,int m)  {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >que; //小根堆	
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)d[s][i]=inf;	
	d[s][s]=0;
     que.push({0,s});
     while(!que.empty())  {
        auto p = que.top();que.pop();
         int u=p.second;
         if(vis[u])continue;
         vis[u]=1;
         for(int i=head[u];i;i= edge[i].next){
            ll v=edge[i].to,w=edge[i].w;
            if(w+d[s][u]<d[s][v]){
                d[s][v]=w+d[s][u];
                que.push( {d[s][v],v});
            }
        }
     }
 }
void solve(){
	int n,m;
 	cin>>n>>m;
	for(int i=1;i<=n;i++)loop[i]=inf; 
 	for(int i=0;i<m;i++){
 		ll u,v,w;	cin>>u>>v>>w;
 		if(u==v)loop[u]=min(loop[u],w);
 		else add(u,v,w);
 	}
 	for(int i=1;i<=n;i++)dijkstra(i,n,m);
 	for(int i=1;i<=n;i++){
 		ll ans=inf;
 		for(int j=1;j<=n;j++){
 			if(i==j)continue;
			 ans=min(ans,d[i][j]+d[j][i]);	
		}
		ans=min(ans,loop[i]);
		cout<<(ans==inf?-1:ans)<<endl;
	}
}