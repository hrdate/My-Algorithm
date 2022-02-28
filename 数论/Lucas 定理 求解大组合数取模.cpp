const ll mod=1e9+7; 
ll jz[MAX],ijz[MAX];  //阶乘，阶乘的逆元 
ll Lucas(ll x,ll y){ //从x中取y个 
	if(x<y)return 0;
	return x<mod?jz[x]*ijz[y]*ijz[x-y]%mod:Lucas(x%mod,y%mod)*Lucas(x/mod,y/mod)%mod;
}
void init(){
	jz[0]=ijz[0]=jz[1]=ijz[1]=1;
	for(ll i=2;i<=n+m;i++){
	    jz[i]=jz[i-1]*i%mod;
	    ijz[i]=(mod-mod/i)*ijz[mod%i]%mod;
	}
	for(ll i=2;i<=n+m;i++)ijz[i]=ijz[i]*ijz[i-1]%mod;
}