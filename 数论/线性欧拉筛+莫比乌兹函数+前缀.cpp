int mu[MAX],phi[MAX],pri[MAX],sum_mu[MAX],tot;
bool vis[MAX];
void getMu() {
	tot = 0;
	mu[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		if (!vis[i]) {
			pri[++tot] = i; phi[i] = i - 1; mu[i] = -1;
		}
	    for (int j = 1; j <= tot && i * pri[j] < MAX; ++j) {
	    	vis[i * pri[j]] = 1;
	    	if (i % pri[j] == 0) {
	    		mu[i * pri[j]] = 0;
	    		phi[i * pri[j]] = phi[i] * pri[j];    //i与pri[j]不互质 
	    		break;
	    	}
	    	mu[i * pri[j]] = -mu[i];
	    	phi[i * pri[j]] = phi[i] * (pri[j] - 1);  //i与pri[j]互质 
		}
	}
	for (int i = 1; i < MAX; ++i) sum_mu[i] += mu[i - 1];
}