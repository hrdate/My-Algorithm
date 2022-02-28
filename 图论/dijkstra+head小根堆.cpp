
http://acm.hdu.edu.cn/showproblem.php?pid=2544
hdu-2544
只适用于边长为非负数的图
——————————————————————————
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
using namespace std;
const int mod=1e9+7;
const int MAX=2e6+7;
#define inf 0x3f3f3f3f
int d[MAX]; // 从1到i的距离 
int head[MAX],vis[MAX];
struct Edge{
    int next,to,w;
}edge[MAX];
int cnt=0;
void add(int u,int v,int w){
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
/*
struct node{
	ll d,id;
	bool operator<(const node&a)const{
		return d>a.d; //小根堆 
	}
};
*/
void dijkstra(int s,int n,int m)  {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >que; //小根堆	
	for(int i=1;i<=n;i++)d[i]=inf,vis[i]=0;
	d[s]=0;
    que.push({0,s});
    while(!que.empty()){ //bfs版本
        auto p = que.top();que.pop();
        int u=p.second;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to,w=edge[i].w;
            if(w+d[u]<d[v]){
                d[v]=w+d[u];
                que.push({d[v],v});
            }
        }
     }
 }
int main(){
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	int E,n;
 	while(cin>>n>>E){
 		if(n==0&&E==0)break;
 		memset(head,0,sizeof(head)); cnt=0;
	 	for(int i=0;i<E;i++){
	 		int u,v,w;	cin>>u>>v>>w;
	 		add(u,v,w);
	 		add(v,u,w);
	 	}
	 	 dijkstra(1,n,E);
	 	 cout<<d[n]<<endl;
	}
 	return 0;
}		