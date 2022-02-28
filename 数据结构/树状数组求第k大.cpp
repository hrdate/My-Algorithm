// O(n)建树
void init() {
  for (int i = 1; i <= n; ++i) {
    t[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) t[j] += t[i];
  }
}

kth的复杂度为O(logn)

//权值树状数组查询第k小
int kth(int k) {
  int cnt = 0, ret = 0;    //数组t[i]表示元素i出现的次数
  for (int i = log2(n); ~i; --i) {      // i与上文depth含义相同
    ret += 1 << i;                      // 尝试扩展
    if (ret >= n || cnt + t[ret] >= k)  // 如果扩展失败
      ret -= 1 << i;
    else
      cnt += t[ret];  // 扩展成功后 要更新之前求和的值
  }
  return ret + 1;
}