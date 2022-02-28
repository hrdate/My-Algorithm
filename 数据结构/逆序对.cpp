
#include<bits/stdc++.h>
using namespace std;
const int MAX=100010;
const int mod=1e9+7;
#define ll long long 
#define _for(i,j,k) for(int i=j;i<k;i++)
#define endl  '\n'
#define inf 1<<29
int a[MAX],n,Max;
int tree[MAX];

int lowbit(int x)  //找最低位的1 
{
	return x&-x;
}
void add(int i,int x)//修改数据在i加x 
{
    while(i<=n)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}

int sum(int x)//求1至i的和，若需求a至b的和，只需sum(b)-sum(a)+a[i]; 
{
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<int>ans(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[i]=a[i];
	}
	sort(ans.begin(),ans.end());
		ll cnt=0; 
	for(int i=n-1;i>=0;i--)
	{
		int id=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin()+1;
		cnt+=sum(id-1);
		add(id,1);
	}
	cout<<cnt;
}