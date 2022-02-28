

struct trie {
  int nex[100000][26], cnt;
  bool exist[100000];  // �ý���β���ַ����Ƿ����

  void insert(char *s, int l) {  // �����ַ���
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // ���û�У�����ӽ��
      p = nex[p][c];
    }
    exist[p] = 1;
  }
  bool find(char *s, int l) {  // �����ַ���
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
};


��������������������������������������������������������������������������������
���� n�����ִ���Ȼ�����  m�ε�����ÿ������Ҫ�ش����ֲ����ڡ�������һ�ε㵽������֡������Ѿ����������֡�֮һ��
1<=n<=10^4   1<=m<=10^5 �����ַ������Ȳ�����50 ��
#include <cstdio>

const int N = 500010;

char s[60];
int n, m, ch[N][26], tag[N], tot = 1;

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      if (!ch[u][c]) ch[u][c] = ++tot;
      u = ch[u][c];
    }
    tag[u] = 1;
  }

  scanf("%d", &m);

  while (m--) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      u = ch[u][c];
      if (!u) break;  // �����ڶ�Ӧ�ַ��ĳ���˵�����ֲ�����
    }
    if (tag[u] == 1) {
      tag[u] = 2;
      puts("OK");
    } else if (tag[u] == 2)
      puts("REPEAT");
    else
      puts("WRONG");
  }

  return 0;
}