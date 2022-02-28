vector<ll>g[MAX]; //存图 
ll cost[MAX];
ll n,dfn[MAX],dfncnt,low[MAX],st[MAX],in_stack[MAX],top;
int scc[MAX], sc;  // 结点 i 所在 强连通分量scc 的编号 
int siz[MAX];       // 强连通 i 的大小
void tarjan(int u){
	st[++top]=u;   
	dfn[u]=low[u]=++dfncnt;
	in_stack[u]=1;
	for(int v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]); 
		}
		else if(in_stack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		sc++;
		while(1){
			ll now=st[top--];
			in_stack[now]=0;
			scc[now]=sc;
			siz[sc]++;
			//cost[sc]=min(cost[sc],cir[now].w);
			if(now==u)break; 
		}
	}
}

void init(){
	for(int i=0;i<=n;i++)g[i].clear();
	dfncnt=top=sc=0;
	memset(dfn,0,sizeof(dfn)); 
	memset(low,0,sizeof(low));
	memset(in_stack,0,sizeof(in_stack));
	//memset(cost,inf,sizeof(cost));
}