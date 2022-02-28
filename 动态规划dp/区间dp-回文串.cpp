/*
https://www.acwing.com/problem/content/1224/  acwing-1222. 密码脱落

dp(i,i)=0单个字符就是回文串dp(i,i)=0单个字符就是回文串 
dp(i,j)=dp(i+1,j−1)(s[i]==s[j])dp(i,j)=dp(i+1,j−1)(s[i]==s[j])
dp(i,j)=min(dp(i+1,j),dp(i,j−1))+1(s[i]≠s[j])
当i==j−1且s[i]==s[j]时，这也是回文串

*/

int dp[2005][2005];
void solve(){
    string s;cin>>s;
    int len=s.size();
    memset(dp,inf,sizeof(dp));
    for(int i=len-1;i>=0;i--){
        for(int j=i;j<len;j++){
            if(i==j)dp[i][j]=0;
            else {
                if(s[i]==s[j]){
                    if(i+1==j)dp[i][j]=0;
                    else dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }
                else dp[i][j]=min(dp[i][j],min(dp[i+1][j]+1,dp[i][j-1]+1));
            }
        }
    }
    cout<<dp[0][len-1];
}