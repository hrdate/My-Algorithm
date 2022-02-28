/*
洛谷 P3388 【模板】割点（割顶）
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;  // 点数、边数
int dfs[100001], low[100001], inde, res;
// dfs：记录每个点的时间戳
// low：能不经过父亲到达最小的编号，inde：时间戳，res：答案数量
bool vis[100001], flag[100001];  // flag:答案 ; vis:标记是否重复
vector<int> edge[100001];        // 存图
void Tarjan(int u, int father) {  
	vis[u] = true;                  // 标记
	low[u] = dfs[u] = ++inde;  // 打上时间戳
	int child = 0;             // 每一个点儿子数量
	for (auto v : edge[u]) {   
		if (!vis[v]) {
    		child++;                      
    		Tarjan(v, u);                  
    		low[u] = min(low[u], low[v]);  
      				// 主要代码
                    // 如果不是自己，且不通过父亲返回的最小点符合割点的要求，并且没有被标记过
                    // 要求即为：删了父亲连不上去了，即为最多连到父亲
    		if (father != u && low[v] >= dfs[u] &&!flag[u])  {
				flag[u] = true;
        		res++;  
    		}
    	} 
		else if (v != father)  // 如果这个点不是自己，更新能到的最小节点编号
      	low[u] = min(low[u], dfs[v]);  
   }
  // 如果搜到了自己（在环中），如果他有两个及以上的儿子，那么他一定是割点了
	if (father == u && child >= 2 &&!flag[u]) {  
		flag[u] = true;
		res++;  
	}
}
void solve(){
	cin >> n >> m;                  
	for (int i = 1; i <= m; i++) {  
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}                             
	for (int i = 1; i <= n; i++)  // 因为 Tarjan 图不一定连通
		if (!vis[i]) {
			inde = 0;      // 时间戳初始为 0
			Tarjan(i, i);  // 从第 i 个点开始，父亲为自己
    	}
	cout << res << endl;
	for (int i = 1; i <= n; i++)
		if (flag[i]) cout << i << " ";  
	cout << endl;
}