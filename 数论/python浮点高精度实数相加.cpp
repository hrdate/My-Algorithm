
t=int(input())
for i in range(1,t+1) :
    a=int(input())  
    b=int(input())
    print(a+b)   

    '''python输出print自带换行，可用end=“”指定参数，可以阻断换行例如print(1,end=" ")'''

'''
T = int(input())
for i in range(1, T + 1):
    a, b = map(int, input().split())
    print('Case %d:' % i)
    print(a, '+', b, '=', a + b)
    if i != T:
        print()        
'''

'''
from decimal import Decimal,getcontext
getcontext().prec=101#设置浮点数的精度为101位
a=Decimal(input())
b=Decimal(input())
print(str(a+b).rstrip('0'))#去掉右边多余的0
'''