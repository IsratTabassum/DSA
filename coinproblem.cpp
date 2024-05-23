
#include<bits/stdc++.h>
using namespace std;

int coin(int coins[],int n, int s)
{
int dp[n+1][s+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
           dp[i][j]=0;
        }
    }
    dp[0][0]=1;
  for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
           dp[i][j]+=dp[i-1][j];
           if(j-coins[i-1]>=0)dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }

    return dp[n][s];
}
int main()
{
    int coins[]={1,2,3};
   int n=3;
   int sum=5;
    cout<<coin(coins,n,sum);
}

