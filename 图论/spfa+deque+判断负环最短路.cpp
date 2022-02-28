/*
https://blog.csdn.net/qq_25845753/article/details/87472373
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
struct Edge{
    int next,to,w;
}edge[MAX];
int tot[MAX],n,m,cnt=0;
int dis[MAX]; // 从1到i的距离 
int head[MAX],vis[MAX];
void add(int u,int v,int w){
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool spfa(int s)  
{
	deque<int>que;	
	for(int i=0;i<=n;i++)dis[i]=inf,vis[i]=tot[i]=0; 
	dis[s]=0;vis[s]=1; tot[s]=1;
     que.push_back(s);
     while(!que.empty()){
        int u=que.front(); que.pop_front();
        vis[u]=0;
         for(int i=head[u];~i;i= edge[i].next){
            int v=edge[i].to, w=edge[i].w;
            if(w+dis[u]<dis[v]){
            	 if(tot[v]>n)return 0;
            	tot[v]=tot[u]+1;  //判断负环
                 dis[v]=w+dis[u];
                 if(!vis[v]){
                 	if(que.empty())que.push_back(v);
                 	else {
                 		if(dis[v]<dis[que.front()])que.push_front(v);
						else que.push_back(v);
					 }
                 	vis[v]=1;
				 }
            }
        }
     }
     return 1;
 }
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	    cin>>n>>m; 
 		memset(head,-1,sizeof(head));
	 	for(int i=0;i<m;i++){
	 		int u,v,w;	cin>>u>>v>>w;
	 		add(u,v,w);
	 	}
	 	if(spfa(1)==0)cout<<"Forever love"<<endl;
	 	else for(int i=2;i<=n;i++)cout<<dis[i]<<endl;
 	return 0;
}	