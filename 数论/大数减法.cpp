C++大数减法
输入字符串str1，str2转化为a[], b[]


void sub()
{
	//逆序存入
	for (int i = strlen(str1) - 1, j = 0; i >= 0; i--)
		a[j++] = str1[i] - '0';
	for (int i = strlen(str2) - 1, j = 0; i >= 0; i--)
		b[j++] = str2[i] - '0';
	//计算以及借位
	int bit = 0;
	for (int i = 0; i < maxn; i++)
	{
		a[i] -= bit;
		if (a[i] < b[i])
		{
			a[i] += 10;
			bit = 1;
		}
		else
			bit = 0;
		b[i] = a[i] - b[i];
	}
	//去除前置0的输出
	int i;
	for (i = maxn - 1; i >= 0 && b[i] == 0; i--);
	if (i >= 0)
		for (; i >= 0; i--)
			cout << b[i];
	else
		cout << 0;
	cout << endl;
}
