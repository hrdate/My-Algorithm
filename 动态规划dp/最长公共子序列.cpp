/*
最长公共子序列
*/
const int MAX=1e3+7;
int dp[MAX][MAX];
void solve(){
	string a,b;
	while(cin>>a>>b){
		int la=a.size(),lb=b.size();
		for(int i=0;i<=la;i++)
		for(int j=0;j<=lb;j++)dp[i][j]=0;
		for(int i=1;i<=la;i++){
			for(int j=1;j<=lb;j++){
				if(a[i-1]==b[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[la][lb]<<endl;
	}
}