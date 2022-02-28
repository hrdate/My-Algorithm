/*
KMP�ַ���ƥ��ģ��
*/
const int MAX=1e6+7;
int nt[MAX];
void kmp_next(string pattern,int next[]){
    int len=pattern.size();
    next[0]=-1;
    for(int i=0,j=-1;i<len;){
        if(j==-1||pattern[i]==pattern[j]) next[++i]=++j;
        else j=next[j];
    }
}
int kmp(string s,string pattern,int next[]){
    int ls=s.size(),lp=pattern.size(),flag=0;
    for(int i=0,j=0;i<ls;){
        if(j==-1||s[i]==pattern[j])i++,j++;
        else j=next[j];
        if(j==lp)
            flag++,j=0;
    }
    return flag;
}


���⣺���P3375
���ӣ�https://www.luogu.com.cn/problem/P3375


 ���⣺ţ�� �ɰ�������
https://ac.nowcoder.com/acm/problem/18984


