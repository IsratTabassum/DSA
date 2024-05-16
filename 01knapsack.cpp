#include <bits/stdc++.h>
using namespace std;
int knapsack(int n,int M,int w[], int p[])
{
    int i,j;
    int knapsack[n+1][M+1];
    for(j=0;j<=M;j++)
        knapsack[0][j]=0;
     for(i=0;j<=n;i++)
        knapsack[i][0]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=M;j++){

                if(w[i-1]<=j)
                    knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
                else
                    knapsack[i][j]=knapsack[i-1][j];
            }}
            return knapsack[n][M];
}
int main()
{
    int i,j,n,M;
    cout<<"no of items"<<endl;
    cin>>n;
    int w[n],p[n];
    cout<<"enter the weight and profit"<<" ";
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
    cout<<"enter the capacity of knapsack";
    cin>>M;
    int result=knapsack(n,M,w,p);
    cout<<"The maximus value items that can be put into knapsack is "<<result<<endl;
    return 0;

}
