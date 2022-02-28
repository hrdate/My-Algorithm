/*
字符串a,b删增修字符串修改最小操作变成相同
POJ - 3356 AGTC
*/
const int MAX=1e3+7;
int dp[MAX][MAX];
void solve(){
	int la,lb;
	string a,b;
	while(cin>>la>>a>>lb>>b){
		a="#"+a; b="#"+b;
		for(int i=1;i<=la;i++)dp[i][0]=i;
		for(int i=1;i<=lb;i++)dp[0][i]=i;
		for(int i=1;i<=la;i++){
			for(int j=1;j<=lb;j++)
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
		}
		cout<<dp[la][lb]<<endl;
	}
}