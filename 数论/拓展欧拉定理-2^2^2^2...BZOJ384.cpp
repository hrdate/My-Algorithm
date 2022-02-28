/*
BZOJ3884-拓展欧拉定理
求解f(p)=2^2^2^2^2^2....%mod(p)=(2^2^2^2....modφ(p)+φ(p))%mod=(2^(f(φ(p)+φ(p)))%mod
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
const int MAX=1e7+7;
int pri[MAX],phi[MAX],vis[MAX],cnt;
void init(){
	cnt=0;
	phi[1]=1;
	for(int i=2;i<MAX;i++){
		if(!vis[i]){
			pri[cnt++]=i;
			phi[i]=i-1;
		} 
		for(int j=0;j<cnt;j++){
			if(1ll*i*pri[j]>=MAX)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		} 	
	}
}
ll qpow(ll a,ll b,ll mod){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
ll f(ll p){   //2^2^2^2..... 
	if(p==1)return 0;
	return qpow(2,f(phi[p])+phi[p],p);   // (2^2^2^2....modφ(p)+φ(p))%mod=(2^(f(φ(p)+φ(p)))%mod
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		ll p;cin>>p;	
		cout<<f(p)<<endl;
	}
   return 0;
} 