/*
选择线性基的一组子集，使异或值最大
https://vjudge.net/problem/SGU-275

http://acm.hdu.edu.cn/showproblem.php?pid=3949
求xor所有值的第k小
*/

#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
ll d[105],d2[105],n,m,tot,k;
inline void insert(ll x){
	for(int i=61;i>=0;i--){
		if(x&(1ll<<i)){   // x的第i位不是0
			if(!d[i]){
				d[i]=x;break;
			}
			x^=d[i];
		}
	}
}
ll maxor(){  //从高位到低位 
	ll ans=0;
	for(int i=61;i>=0;i--)
		if((ans^d[i])>ans)ans^=d[i];  //优先考虑位高的尽可能大
	return ans;
}
ll mixor(int n){   //从低位到高位，0或第一个d[i] 
	int cnt=0;
	for(int i=0;i<=61;i++)
		if(d[i])cnt++;
	if(cnt<n)return 0; //线性基个数小于原序列个数
	for(int i=0;i<=60;i++)
		if(d[i])return d[i]; 
}
void change(){  //处理线性基
	tot=0;
	for(int i=60;i>=0;i--){
		if(!d[i])continue;
		for(int j=i-1;j>=0;j--)   //倒序 
			if(d[i]&(1ll<<j))d[i]^=d[j];
	}
	for(int i=0;i<=60;i++)
		if(d[i])d2[tot++]=d[i];
}
ll k_th(ll k){  //第k小 
	if(k>=(1ll<<tot))return -1; 
	ll ans=0;
	for(int i=0;i<=60;i++)
		if(d2[i]!=0){
			if(k%2==1)ans^=d2[i];
			k/=2;
		}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t,cas=1;cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case #"<<cas++<<":"<<endl; 
		memset(d,0,sizeof(d)); //初始化base 
		for(ll i=0,x;i<n;i++){
			cin>>x;
			insert(x);
		}
		change();  //处理线性基
		cin>>m; 
		while(m--){
			cin>>k;
			if(tot!=n)k--;  //排除0的特殊情况 
			cout<<k_th(k)<<endl; 
		}
	}
   return 0;
} 
