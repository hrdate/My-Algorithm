/*
最大连续子序列
http://acm.hdu.edu.cn/showproblem.php?pid=1231
dp[i] 以a[i]元素结尾的子序列的最大和
对每个测试用例，在1行里输出最大和、最大连续子序列的第一个和最后一个元 
素，中间用空格分隔。如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。
若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。 
*/
#define ll long long
const int MAX=1e6+7;
ll dp[MAX],index[MAX],a[MAX];
void solve(){
	ll k,ans=0,id=0;
	while(cin>>k&&k){
		id=0;
		for(ll i=1;i<=k;i++){
			cin>>a[i];  dp[i]=0;
			if(a[i]<0)id++;
		}
		if(id==k)cout<<0<<" "<<a[1]<<" "<<a[k]<<endl;
		else {
			for(ll i=1;i<=k;i++){
				if(dp[i-1]+a[i]>a[i]){
					dp[i]=dp[i-1]+a[i];  index[i]=index[i-1];
				}
				else {
					dp[i]=a[i];  index[i]=i;  
				}
			}
			ans=id=0;
			for(ll i=1;i<=k;i++){
				if(ans<dp[i]){   //输出序号i和j最小的那个
					ans=dp[i]; id=i;
				}
			}
			cout<<ans<<" "<<a[index[id]]<<" "<<a[id]<<endl;
		}
	} 
} 