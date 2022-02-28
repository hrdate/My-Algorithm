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
const int maxn = 1024;
const int maxm = 100008;
struct Edge{ 
	int v, nxt, w;
};
struct Node{
    int pos, Cost, F;
    bool operator < (const Node & rhs) const { //重载的时候注意符号
        if(F == rhs.F) return this->Cost > rhs.Cost;
        return F > rhs.F;
    };
};

Edge edge[maxm],redge[maxm];
int head[maxn], rhead[maxn];
int cnt, Rcnt;
int N, M, K, S, des;
void init(){
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    cnt = Rcnt = 0;
}
void AddEdge(int from, int to, int weight){
    edge[cnt].w = weight;
    edge[cnt].v = to;
    edge[cnt].nxt = head[from];
    head[from] = cnt++;
}
void AddREdge(int from, int to, int weight){
    redge[Rcnt].w = weight;
    redge[Rcnt].v = to;
    redge[Rcnt].nxt = rhead[from];
    rhead[from] = Rcnt++;
}
int vis[maxn];
int H[maxn];
void SPFA(int st){
    queue<int> que;
    memset(H, inf, sizeof(H));
    memset(vis, 0, sizeof(vis));
    H[st] = 0;
    que.push(st);
    while(!que.empty()){
        int cur = que.front(); que.pop();
        vis[cur] = 0;
        for(int i=rhead[cur]; i!=-1; i=redge[i].nxt) {
            int v = redge[i].v;
            if(H[v] > H[cur] + redge[i].w) {
                H[v] = H[cur] + redge[i].w;
                if(!vis[v]) {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
}
int A_Star(int s, int t, int k){
    if(s == t) k++;
    if(H[s]==inf) return -1;
    priority_queue<Node> que;
    Node cur={s,0,H[s]}, into;
    que.push(cur);
    int CNT = 0;
    while(!que.empty()){
        cur = que.top();
        que.pop();
        if(cur.pos == t) CNT++;
        if(CNT == k) return cur.Cost; //返回k短路权值 
        for(int i=head[cur.pos]; i!=-1; i=edge[i].nxt){
            into.Cost = cur.Cost+edge[i].w;
            into.F = cur.Cost+edge[i].w+H[edge[i].v];
            into.pos = edge[i].v;
            que.push(into);
        }
    }
	return -1;
}
int main(){
    while(cin>>N>>M){
        init();
        while(M--){
            int from, to, weight;
			cin>>from>>to>>weight;
            AddEdge(from, to, weight);
            AddREdge(to, from, weight);//建反向边
        }
        cin>>S>>des>>K;
        SPFA(des);//求其他点到终点的最短路，作为H值
        cout<<A_Star(S,des,K)<<endl;
    }
    return 0;
}