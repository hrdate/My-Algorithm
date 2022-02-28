/*
SSP（Successive Shortest Path）算法：在最大流的 EK 算法求解最大流的基础上，
把 用 BFS 求解任意增广路 改为 用 SPFA 求解单位费用之和最小的增广路 即可
相当于把  w(u,v) 作为边权，在残存网络上求最短路。
*/
const int N=1e3+5;
const int M=2e3+5;
struct qxx {
  int nex, t, v, c;
};
qxx e[M];
int h[N], cnt = 1;
void add_path(int f, int t, int v, int c) {
  e[++cnt] = (qxx){h[f], t, v, c}, h[f] = cnt;
}
void add_flow(int f, int t, int v, int c) {
  add_path(f, t, v, c);
  add_path(t, f, 0, -c);
}
int dis[N], pre[N], incf[N];
bool vis[N];
bool spfa() {
  memset(dis, 0x3f, sizeof(dis));
  queue<int> q;
  q.push(s), dis[s] = 0, incf[s] = INF, incf[t] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = h[u]; i; i = e[i].nex) {
      const int &v = e[i].t, &w = e[i].v, &c = e[i].c;
      if (!w || dis[v] <= dis[u] + c) continue;
      dis[v] = dis[u] + c, incf[v] = min(w, incf[u]), pre[v] = i;
      if (!vis[v]) q.push(v), vis[v] = 1;
    }
  }
  return incf[t];
}
int maxflow, mincost;
void update() {
  maxflow += incf[t];
  for (int u = t; u != s; u = e[pre[u] ^ 1].t) {
    e[pre[u]].v -= incf[t], e[pre[u] ^ 1].v += incf[t];
    mincost += incf[t] * e[pre[u]].c;
  }
}
// 调用：while(spfa())update();