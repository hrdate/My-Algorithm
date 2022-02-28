//马拉车算法 Manacher
https://www.cnblogs.com/cain-/p/7977368.html

模板
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 32000005;
int manacher(string s)
{
	string str=""; 
	int len=s.size(),mx=0,id=0,ans=0;
	for(int i=0;i<len;i++){
		str+="#";
		str+=s[i];
	}
	str+="#";
	len=str.size();
	vector<int>p(len,0);
	for(int i=0;i<len;i++){
		if(i<mx) p[i]=min(mx-i,p[2*id-i]);
		else p[i]=1;
		while (i-p[i]>=0&&i+p[i]<len&&str[i-p[i]]==str[i+p[i]])
				p[i]++;
		if (p[i]+i-1>mx){
			mx=p[i]+i-1;
			id=i;
		}
		ans=max(ans,p[i]);
	}
	return ans-1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;cin>>s;
	cout<<manacher(s);
}



——————————————————————————
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 32000005;
string s,str="";
string manacher(string s)
{
	string t = "$#";
	for (int i = 0; i < s.size(); ++i)
	{
		t += s[i];
		t += "#";
	}
	vector<int> p(t.size(), 0);
	int mx = 0, id = 0, r = 0, Center = 0;
	for (int i = 1; i < t.size(); ++i)
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

		while (t[i + p[i]] == t[i - p[i]])
		{
			++p[i];
		}
		if (mx < i + p[i])
		{
			mx = i + p[i]; //mx用来更新当前最长回文串能延伸到的嘴右边的位置
			id = i; //id用来保存当前最长回文串的中心位置
		}
		if (r < p[i])
		{
			r = p[i]; //r用来更新半径的长度
			Center = i; //center用来记录最长回文串中心位置
		}
	}
	//最长子串的长度是半径减一，起始位置是中间位置减去半径再除以2
	return s.substr((Center - r) / 2, r - 1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>s;str="";
	cout<<manacher(s);
}

——————————————————————————————
牛客练习：马拉车
https://ac.nowcoder.com/acm/problem/14517

#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
string s;
int manacher(string s)
{
   string str="$";
   int len=s.size(),mx=0,id=0,ans=0;
   for(int i=0;i<len;i++)str+='#',str+=s[i];
   str+='#';
   len=str.size();
   vector<int>p(len+1,0);
   for(int i=1;i<=len;i++){
      p[i]=i<mx?min(mx-i,p[2*id-i]):1;
      while(i-p[i]>=1&&i+p[i]<=len&&str[i-p[i]]==str[i+p[i]])p[i]++;
      if(p[i]+i>mx)mx=p[i]+i,id=i;
      ans=max(ans,p[i]);
   }
   return ans-1;
}
int main()
{
   ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
   while(cin>>s){
      cout<<manacher(s)<<endl;
   }
}