/*
P5091 【模板】扩展欧拉定理
https://www.luogu.com.cn/problem/P5091
求a^b%mod
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,mod,phi=1;
ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
ll euler_phi(ll n) {
  ll m = int(sqrt(n + 0.5));
  ll ans = n;
  for (ll i = 2; i <= m; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
int main(){
	cin>>a>>mod;
	phi=euler_phi(mod);
	char c;int flag=0;
	while((c=getchar())<'0'||c>'9');
	while(b=b*10ll+(c ^ '0'),(c = getchar()) >= '0' && c <= '9'){
		if(b>=phi){
			b%=phi;
			flag=1;
		}
	}
	if(flag)b+=phi;
	cout<<qpow(a,b);
}