http://acm.hdu.edu.cn/showproblem.php?pid=2586
HDU 2586 How far away?    LCA最近公共祖先模板题
——————————————————————————
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
#define inf 0x3f3f3f3f
#define MAX 50007
using namespace std;
struct Edge 
{
    int nxt,to,w;
}edge[MAX*2+5];

int n,m; // 点数、边数 
int root,cnt; 
int head[MAX+5],dep[MAX+5],dis[MAX+5]; //头，深度，距离权值 
int f[MAX+5][35];//存f[x][i]，x的2^i个祖先 
int vis[MAX+5];

void add(int u,int v,int w)
{
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=0; i<=31; i++)   //自下而上，f[u][i]表示u的第2^i个祖先
        f[u][i+1]=f[f[u][i]][i];

    for(int i=head[u]; i; i=edge[i].nxt){
        if(edge[i].to==fa)continue;
        f[edge[i].to][0]=u;
        dis[edge[i].to]=dis[u]+edge[i].w;
        dfs(edge[i].to,u);   //换根再次进行dfs 
    }
}
int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=31; i>=0; i--)      //先向上调整深度较大的点，令他们深度相同
    	if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
        	if(x==y) return x;//深度相同时,特判是否是同个点
		}    
    for(int i=31; i>=0&&x!=y; i--)
        if(f[x][i]!=f[y][i]){  //深度相同,共同向上跳转，直到相遇 
            x=f[x][i];
            y=f[y][i];
        }
    return f[x][0];   //返回最近公共祖先的下标 
}
void init(){
	cnt=0;
	memset(vis,0,sizeof(vis));
    memset(edge,0,sizeof(edge));
    memset(f,0,sizeof(f));
    memset(dep,0,sizeof(dep));
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m;
        for(int i=1; i<=n-1; i++){
            int u,v,w;cin>>u>>v>>w;
            add(u,v,w); add(v,u,w);
            vis[v]=1;
        }
        root=1;
		while(vis[root]!=0)root++; 
        dfs(root,0);
        for(int i=1; i<=m; i++){
            int a,b;cin>>a>>b;
            cout<<dis[a]+dis[b]-2*dis[LCA(a,b)]<<endl;  //求距离 
        }
    }
    return 0;
}