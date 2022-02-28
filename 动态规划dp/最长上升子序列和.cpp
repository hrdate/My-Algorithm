/*
最长上升子序列和
*/
void solve(){
	ll n;
	while(cin>>n&&n){
		vector<ll>a(n+1,0),dp(n+1,0);
		for(ll i=1;i<=n;i++)cin>>a[i],dp[i]=a[i];
		dp[1]=a[1];
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<i;j++){
				if(a[i]>a[j])
					dp[i]=max(dp[i],dp[j]+a[i]);
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)ans=max(ans,dp[i]);
		cout<<ans<<endl; 
	}
}

力扣周赛，求k次LIS变形，a[i-k]<=a[i]
https://leetcode-cn.com/contest/weekly-contest-272/problems/minimum-operations-to-make-the-array-k-increasing/

int increasing(vector<int> &a) {
        int n = a.size();
        vector<int> LIS;
        for (int ai : a) {
            auto it = upper_bound(LIS.begin(), LIS.end(), ai);
            if (it == LIS.end())
                LIS.push_back(ai);
            else
                *it = ai;
        }
        return LIS.size();
}