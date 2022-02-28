/*
树形dp-换根
Codeforces Round #627 (Div. 3) F. Maximum White Subtree(1324F)
树上有黑0白1节点，求包含这个点的连通块中白点-黑点数量最大值
预处理白点为1，黑点为-1，转化成求包含这个点的连通块权值和最大值
*/
const int MAX=1e6+7; 
vector<int>G[MAX];
int a[MAX],d[MAX],ans[MAX];
void dfs(int u,int fa){
	d[u]=a[u];
	for(int v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(d[v]>0)d[u]+=d[v];
	}
}
void dfs(int u,int fa,int c){
	ans[u]=d[u]+max(0,c);
	for(int v:G[u]){
		if(v==fa)continue;
		dfs(v,u,ans[u]-max(0,d[v]));
	}
} 
void solve(){
	int n,u,v;cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>u;
    	a[i]=(u==1?1:-1);
	}
    for(int i=0;i<n-1;i++){
    	cin>>u>>v;
    	G[u].push_back(v);
    	G[v].push_back(u);
	}
	dfs(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}