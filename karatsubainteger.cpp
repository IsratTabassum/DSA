#include <bits/stdc++.h>
using namespace std;
int getsize(long long n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n=n/10;
    }
    return c;
}
long long karatsuba(long long x,long long y)
{
    if(x<10&&y<10)
        return x*y;
    int s=max(getsize(x),getsize(y));
    int n=(int)floor(s/2.0);
    long long p=(long long)pow(10,n);
        long long a=(long long)floor(x/(double)p);
        long long b=x%p;
        long long c=(long long)floor(y/(double)p);
                long long d=y%p;
                 long long ac=karatsuba(a,c);
                          long long bd=karatsuba(b,d);
                                    long long e=karatsuba(a+b,c+d)-ac-bd;
    return (long long)(pow(10,2*n)*ac+pow(10,n)*e+bd);


}
int main()
{
    long long x=karatsuba(14612,35212);
    cout<<x<<endl;
}
