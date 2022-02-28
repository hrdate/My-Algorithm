const int MAX=1e6+7;
int phi[MAX],pri[MAX],vis[MAX],cnt; 
void init() {
  phi[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    if (!vis[i]) {
      phi[i] = i - 1;
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt; ++j) {
      if (1ll * i * pri[j] >= MAX) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j]) {    
        phi[i * pri[j]] = phi[i] * (pri[j] - 1);  //i与pri[j]互质 
      } else {
        // i % pri[j] == 0
        // 换言之，i 之前被 pri[j] 筛过了
        // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定也是
        // pri[j] 的倍数 它们都被筛过了，就不需要再筛了，所以这里直接 break
        // 掉就好了
        phi[i * pri[j]] = phi[i] * pri[j];    //i与pri[j]不互质 
        break;
      }
    }
  }
}