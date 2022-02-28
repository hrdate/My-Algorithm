/*
牛客 14369 最短路负环spfa
https://ac.nowcoder.com/acm/problem/14369
————————————————————————————————
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
using namespace std;
const int mod=1e9+7;
const int MAX=2e6+7;
const ll inf=0x3f3f3f3f;
int d[MAX]; // 从1到i的距离 
int head[MAX],vis[MAX];
struct Edge{
    int next,to,w;
}edge[MAX];
int n,m,cnt=0;
void add(int u,int v,int w){
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int spfa(int s)  
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que; //小根堆	
	d[s]=0;vis[s]=1;
     que.push( pair<int,int> (0,s));
     while(!que.empty()){
        pair<int,int>p=que.top(); que.pop();
         int u=p.second;
         vis[u]=0;
         for(int i=head[u];~i;i= edge[i].next){
            int v=edge[i].to, w=edge[i].w;
            if(w+d[u]<d[v]){
                 d[v]=w+d[u];
                 if(!vis[v]){
                 	que.push( {d[v],v});
                 	vis[v]=1;
				 }
            }
        }
     }
     return (d[n]==inf?-1:d[n]);
 }
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	    cin>>n>>m; 
 		memset(d,inf,sizeof(d));
 		memset(head,-1,sizeof(head));
	 	for(int i=0;i<m;i++){
	 		int u,v,w;	cin>>u>>v>>w;
	 		add(u,v,w);
	 	}
	 	spfa(1);
	 	for(int i=2;i<=n;i++)cout<<d[i]<<endl;
 	return 0;
}	