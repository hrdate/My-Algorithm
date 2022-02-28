const int N=1e5+5;
struct LT{
	long long sum=0,lz=0;
}tr[N<<2];
vector<int>e[N];
int n,cnt=1;
int dep[N],fa[N],siz[N],son[N],top[N],dfn[N],rnk[N];
inline void app(int l,int r,int s,long long lz){
	tr[s].lz+=lz;
	tr[s].sum+=lz*(r-l+1);
}
inline void pushdown(int m,int l,int r,int p){
	long long &lz=tr[p].lz;
	app(l,m,p<<1,lz);
	app(m+1,r,p<<1|1,lz);
	lz=0;
}
inline void pushup(int p){
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void segement_modify(int L,int R,int v,int l,int r,int p){
	if(L<=l&&r<=R){
		tr[p].sum+=1ll*v*(l-r+1);
		tr[p].lz+=v;
		return;
	}
	int m=(l+r)>>1;
	pushdown(m,l,r,p);
	if(L<=m)segement_modify(L,R,v,l,m,p<<1);
	if(m<R)segement_modify(L,R,v,m+1,r,p<<1|1);
	pushup(p);
}
void dot_modify(int x,int v,int l,int r,int p){
	if(l==r){
		tr[p].sum=v;
		return;
	}
	int m=(l+r)>>1;
	if(x<=m)dot_modify(x,v,l,m,p<<1);
	else dot_modify(x,v,m+1,r,p<<1|1);
	pushup(p);
}
int segement_sum(int L,int R,int l,int r,int p){
	if(L<=l&&r<=R)return tr[p].sum;
	int tp=0;
	int m=(l+r)>>1;
	if(L<=m)tp+=segement_sum(L,R,l,m,p<<1);
	if(m<R)tp+=segement_sum(L,R,m+1,r,p<<1|1);
	return tp;
}
inline void dfs1(int u,int f,int depth){
	dep[u]=depth; //深度 
	fa[u]=f;// 父节点 
	siz[u]=1;//子树大小 
	for(auto v:e[u]){
		if(v!=f){
			dfs1(v,u,depth+1);
			siz[u]+=siz[v];
			if(son[u]==-1||siz[v]>siz[son[u]])son[u]=v;
		}
	}
}
inline void dfs2(int u,int tp){
	top[u]=tp;//所在链的链顶
	dfn[u]=++cnt;  //DFS 序
	rnk[cnt]=u;//DFS 序对应的节点编号
	if(son[u]==-1)return;
	dfs2(son[u],tp);
	for(auto v:e[u]){
		if(v!=son[u]&&v!=fa[u])dfs2(v,v);
	}
}
inline int rangesum(int u,int v){
	int sum=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		sum+=segement_sum(dfn[top[u]],dfn[u],1,n,1);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	sum+=segement_sum(dfn[u],dfn[v],1,n,1);
	return sum;
}
inline void rangeupdate(int u,int v,int w){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		segement_modify(dfn[top[u]],dfn[u],w,1,n,1);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	segement_modify(dfn[u],dfn[v],w,1,n,1);
}