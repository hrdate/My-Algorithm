/*
POJ-1811-Prime Test-Pollard-Rho分解大质因数模板
牛客链接： https://ac.nowcoder.com/acm/problem/106408
题意：输入一个大数n，输出最小的质因子
*/
#define endl "\n" 
#define ll long long
const int MAX=2e6+7;
ll factor[MAX],cnt=0;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
//快速乘法 
ll mul(ll a,ll b,ll mod){  
	ll res=0; a%=mod; b%=mod;
	for(;b;b>>=1){
		if(b&1)res=(res+a)%mod;
		a=(a+a)%mod;
	}
	return res;
}
//快速幂 
ll qpow(ll a,ll b,ll mod){   
	ll res=1; a%=mod;
	for(;b;b>>=1){
		if(b&1)res=mul(res,a,mod); //快速乘法 
		a=mul(a,a,mod)%mod;
	}
	return res;
}
//判断n是是否为质数 
bool Miller_Rabin(ll n){   //n是测试的大数
	if(n==2||n==3)return 1;  //特判 
	if(n%2==0||n%3==0||n<2)return 0;  
	ll d=n-1,s=0;  //将n-1分解d*2^s
	while(!(d&1))d>>=1,s++;
	//srand((unsigned)time(NULL));在最开始调用即可
	for(int i=0;i<20;i++){ //重复20次 
		ll a=rand()%(n-1)+1;  //在[2,n-1]中随机取一个数 
		ll x=qpow(a,d,n),y=0;
		for(int j=0;j<s;j++){
			y=mul(x,x,n);
			if(y==1&&x!=1&&x!=(n-1))return 0;
			x=y;
		}
		if(y!=1)return 0;  //合数 a^(n-1)≡1(mod n) 费马小定理 
	}
	return 1; 
}
//找到n的一个因子
ll pollard_rho(ll n,ll c){
	ll x=rand()%n,y=x,i=1,k=2;
	while(1){
		i++;
		x=(mul(x,x,n)+c)%n;  //不断调整x2
		ll d=gcd(y>x?y-x:x-y,n);
		if(d>1&&d<n)return d;  //找到因子
		if(x==y)return n;  //找到循环，返回n重来
		if(i==k){
			y=x; k+=k;
		} 
	}
}   
void Find(ll n){
	if(n==1)return ; //递归出口 
	if(Miller_Rabin(n)){  
		factor[cnt++]=n; return ;  //是素数 
	}
	ll p=n;
	//不断找因子，找到为止，返回n说明没找到
	while(p>=n)p=pollard_rho(p,rand()%(n-1)+1); 
	Find(p);
	Find(n/p);
}
void solve(){
 	int t;scanf("%d",&t);   //srand((unsigned)time(NULL));
	while(t--){
		ll n;scanf("%lld",&n);
		if(Miller_Rabin(n))printf("Prime\n");
		else {
			cnt=0; Find(n);  //初始化 
			ll ans=factor[0];
			for(int i=1;i<cnt;i++)ans=min(ans,factor[i]);
			printf("%lld\n",ans);
		}
	} 
}
