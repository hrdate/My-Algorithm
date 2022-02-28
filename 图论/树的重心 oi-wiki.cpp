树的重心
定义：树上一节点最大子树的节点数最小；
性质：
1.删除重心后所得的所有子树，节点数不超过原树的1/2，一棵树最多有两个重心；
2.树中所有节点到重心的距离之和最小，如果有两个重心，那么他们距离之和相等；
3.两个树通过一条边合并，新的重心在原树两个重心的路径上；
4.树删除或添加一个叶子节点，重心最多只移动一条边；
——————————————————————————————
1.定义求解
void getCentroid(int u, int fa) {
  siz[u] = 1;
  wt[u] = 0;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) {
      getCentroid(v, u);
      siz[u] += siz[v];
      wt[u] = max(wt[u], siz[v]);
    }
  }
  wt[u] = max(wt[u], n - siz[u]);
  if (rt == 0 || wt[u] < wt[rt]) rt = u;  // rt 为重心编号
}

