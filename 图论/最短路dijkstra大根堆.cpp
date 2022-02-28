

http://acm.hdu.edu.cn/showproblem.php?pid=2544
hdu-2544
只适用于边长为非负数的图
——————————————————————————

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define endl  '\n'
using namespace std;
const int MAX=20050;
const int inf=0x3f3f3f;
int dis[MAX],vis[MAX];
int n,m,point;// 点数 边数  起始点
vector<pair<int,int> >v[MAX];
struct node
{
    int id;
    ll d;
    node(){};
    node(int id,ll d):id(id),d(d){};
    bool operator <(const node&a)const{
         return d>a.d;
    }
};
void dijkstra(int point)
{
    for(int i=1;i<=n;i++){
        vis[i]=0;dis[i]=inf;
    }
    dis[point]=0;
    priority_queue<node>q;  //大根堆，优先队列在logn内可以从大到小排序
    q.push(node(point,0));
    node temp;
    while(!q.empty())
    {
        temp=q.top();q.pop();
        if(vis[temp.id]==1)continue;
        vis[temp.id]=1;
        for(int i=0;i<v[temp.id].size();i++)
        {
            int j=v[temp.id][i].first;
            int k=v[temp.id][i].second;
            if(temp.d+k<dis[j]&&vis[j]==0)
            {
                dis[j]=temp.d+k;
                q.push(node(j,dis[j]));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		point=1;
	    for(int i=1;i<=n;i++)v[i].clear();
	    for(int i=1;i<=m;i++)
	    {
	        int x,y,z;
	        cin>>x>>y>>z;
	        v[x].push_back(make_pair(y,z));
	        v[y].push_back(make_pair(x,z));
	    }
	    dijkstra(point);
	        cout<<dis[n]<<endl;
	}
    return 0;
}