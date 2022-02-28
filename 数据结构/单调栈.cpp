单调栈是一种特殊的栈，特殊之处在于栈内的元素都保持一个单调性。
利用单调栈可以找出从左/右遍历第一个比它小/大的元素的位置



#include<iostream>
#include<stack>
using namespace std;

int main() {
	//n表示要找的总数
	int n; cin >> n;
	//a用来保存输入的数据
	int* a = new int[n];
	//res_left用来保存对应的结果
	int* res_left = new int[n];
	stack<int>s;
	for (int i = 0; i < n; i++)cin >> a[i];
	//找出a[i]左边和右边最近的一个比他小的值的下标
	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[i] <= a[s.top()])s.pop();
		if (s.empty())res_left[i] = 0;
		else res_left[i] = s.top() + 1;
		s.push(i);
	}
	//这个栈就是递减的一个，取最小值的时候，复杂度是O（1）
	for (int i = 0; i < n; i++) {
		cout << res_left[i] << " ";
	}
}
输入数据: 6
4 7 8 5 3 1
输出数据:
0 1 2 1 0 0

————————————————————————————

https://www.luogu.com.cn/problem/P5788
P5788 【模板】单调栈
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second 
#define ll long long 
#define _for(i,j,k) for(int i=j;i<k;i++)
#define endl  '\n'
#define inf 1<<29
const int mod=1e9+7;
const int MAX=1e6+5;

int n,a[3000005],f[3000005];//a是需要判断的数组（即输入的数组），f是存储答案的数组
stack<int>s;//模拟用的栈
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
		cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();//弹出栈顶比当前数小的
        f[i]=s.empty()?0:s.top();//存储答案，由于没有比她大的要输出0，所以加了个三目运算
        s.push(i);//压入当前元素
    }
    for(int i=1;i<=n;i++) 
	cout<<f[i]<<" ";//输出
}
输入 #1
5
1 4 2 3 5
输出 #1
2 5 4 5 0

————————————————————————————
stack<int> stk;
int n = p.size();
vector<int> S;
for (int i = 0; i < n; i++) {
  while (!stk.empty() && p[i] <= p[stk.top()]) stk.pop();
  stk.push(i);
  S.push_back((int)stk.size());
}