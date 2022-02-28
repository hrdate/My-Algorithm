/*
对于一个二次函数 f(x)=A*x^2+B*x+C
求区间积分[l,r]
https://oi-wiki.org/math/integral/
P4525 【模板】自适应辛普森法1 https://www.luogu.com.cn/problem/P4525
*/
const double eps=1e-7;
double a,b,c,d;
double f(double x){
    return (c*x+d)/(a*x+b);   //题目要求列出的式子
}
//区间[a,b]上的辛普森值
double simpson(double a,double b){
    double c=a+(b-a)/2;
    return (f(a)+4*f(c)+f(b))*(b-a)/6;
}
//区间[a,b]上的积分，精度限制为eps，已知整个区间的辛普森值A
double asr(double a,double b,double eps,double A){
    double c=a+(b-a)/2;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15;
    else return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
