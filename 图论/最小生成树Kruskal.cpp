//洛谷P3366 【模板】最小生成树
//https://www.luogu.com.cn/problem/P3366
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	bool operator<(const Edge tmp){
		return w<tmp.w;
	}
}edge[200005];
int root[5005];
int n,m; //点数，边数
int cnt,cost;   //cnt:当前连通的点数  cost:权值和 
//vector<pair<int, int> >res;  //存储构成最小生成树中的边
int finds(int x){  //并查集
	return root[x]==x?x:root[x]=finds(root[x]);	
}
void Kruskal(int n,int m){
	for(int i=1;i<=n;i++)root[i]=i;  //初始化个点的根节点为本身
	sort(edge+1,edge+1+m);  //按照边权值从小到大排序
	cost=0;cnt=0;
	for(int i=1;i<=m;i++){
		int fu=finds(edge[i].u);
		int fv=finds(edge[i].v);
		if(fu!=fv){    //根节点不同表示不在同个连通块
			root[fv]=fu;
			cost+=edge[i].w;
			cnt++;
			if(cnt==n-1)break;   //n个点中至少需要n-1条边就可以联通
			//res.push_back(make_pair(edge[i].u,edge[i].v)); 存储连通点 
		}	
	}	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;  //输入点数和边数
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	Kruskal(n,m);
	if(cnt==n-1) cout<<cost<<'\n';
	else cout<<"NO"<<'\n';    //无法构成连通块
	/*  //输出连通块中的边
	for(int i = 0; i < res.size(); i++)
        cout<<"("<<res[i].first<<","<<res[i].second<<")"<<" ";
    */
}


——————————————————————————————————
#1601. [Usaco2008 Oct]灌水
设置一个源点，额外建源点到各点的边，再进行最小生成数。
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define AC 0 
#define Please return
#define endl "\n" 
#define ll long long
const int MAX=1e6+7;
const int mod=1e9+7;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
int pre[MAX],cnt,cost;
struct Edge{
	int u,v,w;
	bool operator<(Edge tmp){return w<tmp.w;}
}edge[MAX];
int Find(int x){
	return pre[x]==x?x:pre[x]=Find(pre[x]);
}
void kruskal(int n,int m){
	for(int i=0;i<=n;i++)pre[i]=i;
	sort(edge+1,edge+m+1);
	cost=0;cnt=0;
	for(int i=1;i<=m;i++){
		int fu=Find(edge[i].u);
		int fv=Find(edge[i].v);
		if(fu!=fv){
			//cout<<"fu:"<<fu<<" fv:"<<fv<<endl;
			pre[fv]=fu;
			cost+=edge[i].w; cnt++;
			if(cnt==n)break;
		}	
	}	
} 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,m=0;cin>>n;
	for(int i=1,w;i<=n;i++){
		cin>>w;
		//edge[++m]={0,i,w[i]};
		edge[++m].u=0;edge[m].v=i;edge[m].w=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			if(i==j)continue;
			//edge[++m]={i,j,x};
			edge[++m].u=i;edge[m].v=j;edge[m].w=x;
		}
	}
	kruskal(n,m);
	cout<<cost;
   Please AC;
} 
