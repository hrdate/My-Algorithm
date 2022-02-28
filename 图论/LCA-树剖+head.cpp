//https://www.luogu.com.cn/record/44719857  洛谷模板
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAX = 2 * 500000 + 5;
//任意两村之间有且仅有一条路径，说明该图可以用树存储而且不存在重边和环
struct Edge{
	int next; //上一个节点在head数组的cnt下标
	int to;  //指向的下一个节点
}edge[MAX<<2+1]; 
int head[MAX + 5], cnt;//头,链式前向星存图，点head[x]表示点x所在边在edge数组出现最后一次的下标
void edge_add(int u, int v) { ////添加由点u指向点v的边
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int n; // 点数为n、边数为n-1
int m; // 询问一组a,b,c的次数
int s; //源点 
int father[MAX + 5];//表示点x的父节点
int deep[MAX + 5];//表示点x的深度
int siz[MAX + 5];//表示点x的子树大小，子树的节点个数
int hson[MAX + 5];//表示点x的重子节点，重子节点表示其子节点中子树节点个数最大的子结点
int top[MAX + 5];//表示点x所在重链的顶部节点，重链表示重子节点所在的链

void dfs1(int now) { //当前节点为now，它的父节点为fa，深度为dep
    siz[now] = 1; //子树大小
    deep[now] = deep[father[now]]+1; //深度+1
    for (int i = head[now]; i != 0; i = edge[i].next) {
        int to = edge[i].to; //当前节点i所在边指向的下一个节点
        if (to==father[now])continue; //因为是双向建边，所以需要跳过下一个节点是父节点的情况
        father[to] = now; //父节点
        dfs1(to); //换根再进行深度遍历
        siz[now] += siz[to]; //统计以now为根节点的子树大小
        if (hson[now]==0||siz[hson[now]] <siz[to] ){//选择出以节点now为父节点的子树中最大子子树
            hson[now] = to;
        }
    }
}
void dfs2(int now,int top_fa) {
    top[now] = top_fa;//这个点所在链的顶端
    if (hson[now])//
        dfs2(hson[now], top_fa);//按先处理重儿子，再处理轻儿子的顺序递归处理 
    for (int i = head[now]; i != 0; i = edge[i].next) {
        int to = edge[i].to;
        if (to == father[now] || to == hson[now])continue;
        dfs2(to, to); //对于每一个轻儿子都有一条从它自己开始的链
    }
}
//求最近公共祖先?
int lca(int u, int v) {
    //不断向上跳重链，先跳所在重链顶端深度较大的那个，当跳到同一条重链上时，深度较小的结点即为 LCA
    while (top[u] != top[v]) {
        if (deep[top[u]] > deep[top[v]])
            u = father[top[u]];
        else 
            v = father[top[v]];
    }
    return deep[u] < deep[v] ? u : v;
}

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0); 
    cin>>n>>m>>s;
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		edge_add(u,v);
		edge_add(v,u);
	} 
	dfs1(s) ;
	dfs2(s,s);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		cout<<lca(u,v)<<endl;
	}
    return 0;
}