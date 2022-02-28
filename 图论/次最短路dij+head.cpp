POJ 3255
牛客 新冠病毒要回家  https://ac.nowcoder.com/acm/contest/7031/F
——————————————————————————————
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
#define inf 0x3f3f3f3f
using namespace std;
ll d[5050],d2[5050];
struct edge{
    int u,v,w,next;
}e[200100];
int head[5050],visit[5050];
int cnt,n,m;
struct node{
    int id;
    ll dist;
    node(int _id=0,ll _dist=0):id(_id),dist(_dist){}
    bool operator < (const node &a)const{
        return dist>a.dist;
    }
};

void add(int u,int v,int w)
{
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dij()
{
    for(int i=0;i<=n;i++)
        d[i]=d2[i]=inf;
    priority_queue<node> q;
    while(!q.empty())
        q.pop();
    d[1]=0;
    q.push(node(1,0));
    while(!q.empty())
    {
        node p=q.top();q.pop();
        int u=p.id;
        ll dis=p.dist;
        if(d2[u]<dis) continue;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            ll dd=dis+e[i].w;
            if(d[v]>dd)
            {
                swap(d[v],dd);
                q.push(node(v,d[v]));
            }
            if(d2[v]>dd&&dd>d[v])
            {
                d2[v]=dd;
                q.push(node(v,d2[v]));
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
    int u,v,w;
    cnt=0;
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        u++;v++;
        add(u,v,w);
        add(v,u,w);
    }
    dij();
    cout<<d2[n];
    return 0;
}