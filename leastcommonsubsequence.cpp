
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2)
{
    int m=s1.length();
       int n=s2.length();
    int l[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
            l[i][j]=0;

            else if(s1[i-1]==s2[j-1])
                l[i][j]=1+l[i-1][j-1];
            else
                l[i][j]=max(l[i][j-1],l[i-1][j]);
        }
    }
    return l[m][n];
}
int main()
{
    string s="KOCHY";
    string s1="KYCHHH";
    cout<<lcs(s,s1);
}
