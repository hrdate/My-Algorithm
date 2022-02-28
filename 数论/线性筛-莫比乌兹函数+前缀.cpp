/*
筛质数pri[]，总共tot个
莫比乌斯函数mu[]，前缀和sum_mu[]
*/
const int MAX = 5e4+7;
int mu[MAX],phi[MAX],pri[MAX],sum_mu[MAX],tot;
bool vis[MAX];
void getMu() {
	tot = 0;
	mu[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		if (!vis[i]) {
			pri[++tot] = i;  mu[i] = -1;
		}
	    for (int j = 1; j <= tot && i * pri[j] < MAX; ++j) {
	    	vis[i * pri[j]] = 1;
	    	if (i % pri[j] == 0) {
	    		mu[i * pri[j]] = 0;
	    		break;
	    	}
	    	mu[i * pri[j]] = -mu[i];
		}
	}
	for (int i = 1; i < MAX; ++i) sum_mu[i] += mu[i - 1];
}