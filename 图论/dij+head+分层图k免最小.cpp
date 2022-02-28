/*
Dij+head+分层图k免最小
https://www.luogu.com.cn/problem/P4568
有一个  n个点 m 条边的无向图，你可以选择 k 条道路以零代价通行，求 s到 t 的最小花费。
dis_i_j=min( min(dis_from_j-1) , min(dis_from_j+w) )  从起点i使用j次免费权限后的最短路径
*/
#define endl  '\n'
#define ll long long
#define int long long
const int MAX=4e5+7;
const ll inf=0x3f3f3f3f;
int d[MAX][11],vis[MAX][11]; // 从1到i的距离 
int head[MAX];
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
struct node{
	int u,ki,dis;
	bool operator<(const node&tmp)const{   //小根堆
		return dis>tmp.dis;
	}
};
int n,m,k,s,t;
int dijkstra(int s,int t)  {
	priority_queue<node>que; 
	memset(d,inf,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s][0]=0;
    que.push({s,0,0});
    while(!que.empty()){ //bfs版本
        auto p = que.top();que.pop();
        int u=p.u,ki=p.ki,dis=p.dis;
        if(u==t)return dis; //遍历到t
        if(vis[u][ki])continue;
        vis[u][ki]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to,w=edge[i].w;
            if(ki<k&&vis[v][ki]==0&&d[v][ki+1]>d[u][ki]){  //免费 连接下一层
				d[v][ki+1]=d[u][ki];
				que.push({v,ki+1,d[v][ki+1]});
			}
            if(vis[v][ki]==0&&d[v][ki]>d[u][ki]+w){   //不免费 连接同一层
            	d[v][ki]=d[u][ki]+w;
            	que.push({v,ki,d[v][ki]});
			}
        }
    }
}
void solve(){
	cin>>n>>m>>k>>s>>t;
 	for(int i=0;i<m;i++){
 		int u,v,w;	cin>>u>>v>>w;
 		add(u,v,w);  //第一层相连 
 		add(v,u,w);
 	}
 	cout<<dijkstra(s,t)<<endl; 
}		