/*
P6577 【模板】二分图最大权完美匹配
给定一个二分图，其左右点的个数各为 n，带权边数为 m，保证存在完美匹配。
求一种完美匹配的方案，使得最终匹配边的边权之和最大。
https://www.luogu.com.cn/problem/P6577
*/

//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n" 
#define int long long
const ll inf=0x3f3f3f3f;
const int MAX=1005;
int n,m,match[MAX],pre[MAX];
bool vis2[MAX];
ll favor[MAX][MAX],val1[MAX],val2[MAX],slack[MAX];

void bfs(int p){
    int x,y=0,yy=0;
    memset(pre,0,sizeof(pre));
    memset(slack,inf,sizeof(slack));
    match[0]=p;
    do{
        ll d=inf;
        x=match[y];
        vis2[y]=true;
        for(int i=1;i<=n;i++){
            if(vis2[i])continue;
            if(slack[i]>val1[x]+val2[i]-favor[x][i]){
                slack[i]=val1[x]+val2[i]-favor[x][i];
                pre[i]=y;
            }
            if(slack[i]<d){
                d=slack[i]; //d取最小可能
                yy=i; //记录最小可能存在的点
            }
        }
        for(int i=0;i<=n;i++){
            if(vis2[i]) val1[match[i]]-=d,val2[i]+=d;
            else slack[i]-=d;
        }
        y=yy;
    }while(match[y]);
    
    while(y){
        match[y]=match[pre[y]]; //bfs对访问路径进行记录，并在最后一并改变match
        y=pre[y];
    }
}

ll KM(){
    memset(match,0,sizeof(match));
    memset(val1,0,sizeof(val1));
    memset(val2,0,sizeof(val2));
    for(int i=1;i<=n;i++){
        memset(vis2,false,sizeof(vis2));
        bfs(i);
    }
    ll res=0;
    //最后将对应匹配的边权求和输出
    for(int i=1;i<=n;i++) res+=favor[match[i]][i]; 
    return res;
}

signed main(){
    int u,v,w;cin>>n>>m;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
    		favor[i][j]=-inf;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        favor[u][v]=max(favor[u][v],w);
    }
    cout<<KM()<<endl;
    for(int i=1;i<=n;i++)cout<<match[i]<<" ";
    return 0;
}