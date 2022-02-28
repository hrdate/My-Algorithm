/*
求解直径最小生成树，首先需要找到 图的绝对中心 ， 图的绝对中心 可以存在于一条边上或某个结点上，
该中心到所有点的最短距离的最大值最小。
根据 图的绝对中心 的定义可以知道，到绝对中心距离最远的结点至少有两个。
*/
bool cmp(int a, int b){
    return val[a] < val[b];
}

void Floyd(){
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve(){
    Floyd();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++) {
            rk[i][j] = j;
            val[j] = d[i][j];
        }
        sort(rk[i] + 1, rk[i] + 1 + n, cmp);
    }
    int ans = INF;
    // 图的绝对中心可能在结点上
    for (int i = 1; i <= n; i ++) ans = min(ans, d[i][rk[i][n]] * 2);
    // 图的绝对中心可能在边上
    for (int i = 1; i <= m; i ++){
        int u = a[i].u, v = a[i].v, w = a[i].w;
        for (int p = n, i = n - 1; i >= 1; i --){
            if (d[v][rk[u][i]] > d[v][rk[u][p]]){
                ans = min(ans, d[u][rk[u][i]] + d[v][rk[u][p]] + w);
                p = i;
            }
        }
    }
}