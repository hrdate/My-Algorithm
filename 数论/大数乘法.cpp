c++大数乘法

从低位向高位乘，在竖式计算中，我们是将乘数第一位与被乘数的每一位相乘，记录结果之后，用第二位相乘，记录结果并且左移一位，以此类推，直到计算完最后一位，再将各项结果相加，得出最后结果。

#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int mod=1e9+7;
const int MAX=1e5+7;
int a[MAX],b[MAX],result[2 * MAX]; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	string s1,s2;
	cin >> s1>> s2
	int l1 = s1.length();
		int l2 = s2.length();
		int i = 0, j = 0;
		for (i = l1 - 1, j = 0; i >= 0; i--, j++)
			a[j] = s1[i] - '0';
			
		for (i = l2 - 1, j = 0; i >= 0; i--, j++)
			b[j] = s2[i] - '0';
			
		for (i = 0; i < l1; i++)
			for (j = 0; j < l2; j++)
				result[i + j] += a[i] * b[j];	
				
		for (i = 0; i < (l1 + l2); i++)
			if (result[i] > 9){
				result[i + 1] += result[i] / 10;
				result[i] %= 10;
			}
	
		for (i = l1 + l2; i >= 0; i--)
			if (result[i] == 0) continue;
			else break;
			
		for (; i >= 0; i--)cout << result[i];
			cout<<endl; 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(result,0,sizeof(result));	
	return 0;
}


