/*
一个长度为 n的数组，编程输出每 k个连续的数中的最大值和最小值。

*/
#define MAX 1000100
int q[MAX], a[MAX];
int n, k;
void getmin() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    cout<<a[q[head]]<<" ";
  }
}

void getmax() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    cout<<a[q[head]]<<" ";
  }
}

int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; i++) cin>>a[i];
  getmin();
  cout<<endl;
  getmax();
  cout<<endl;
  return 0;
}