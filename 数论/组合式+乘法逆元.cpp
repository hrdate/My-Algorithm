���ʽ + �˷���Ԫ
cal��n, m��

����������Ԫ
ll get_inv(a,mod){
	return qpow(a,mod-2,mod);
}
��������Ԫ
void inverse(int n, int p) {
    inv[1] = 1;
    for (int i=2; i<=n; ++i) {
        inv[i]=(ll)(p-p/i)*inv[p%i]%p;
    }
}

�׳���Ԫ
ll fac[MAX],inv[MAX];
const ll mod= 1e9+7; 
ll qpow(ll x,ll n,ll m){
    ll res=1;
	while( n ){
	   if( n % 2== 1 )	{
	   	 res = res * x;
	   	 res = res % m;
	   }
	   x = x * x;
	   x = x % m;
	   n >>= 1;
	}
	return res;	
}
void pree(){//Ԥ����
  fac[0] = inv[0] = 1;
  for( int i = 1 ; i <= n ; i++ ){
	  fac[i] = fac[i - 1] * i % mod;
	  inv[n] = qpow( fac[n] , mod-2 , mod );//������
	  for( int i = n; i >= 2 ; i-- )
	  inv[i - 1] = inv[i] * i % mod; 
  }
}
ll C(int n,int m){//�������
	if( n<0 || m<0 || n-m <0 )
	return 0;
	return fac[n]*inv[m] % mod *inv[n-m] % mod;
} 