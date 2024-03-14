#include <bits/stdc++.h>
using namespace std;
void knapsack(int n,float w[],float p[],float c)
{
    float x[20],tp=0;
    int i,j,u;
    u=c;
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    for(i=0;i<n;i++)
    {
        if(w[i]>u)break;
        else
        {
            x[i]=1.0;
            tp=tp+p[i];
            u=u-w[i];
        }}

            if(i<n)
            {
                x[i]=u/w[i];
            }
            tp=tp+(x[i]*p[i]);
            cout<<"Maximum profit"<<setprecision(2)<<tp<<endl;

}
int main()
{
    float we[20],pr[20],c,ra[20],temp;
    int i,j,nu;
    cout<<"Number of objects"<<endl;
    cin>>nu;
       cout<<"Weights and profits"<<endl;
       for(i=0;i<nu;i++)
       {
           cin>>we[i];
           cin>>pr[i];
       }
          cout<<"capacity"<<endl;
          cin>>c;
          for(i=0;i<nu;i++)
          {
              ra[i]=pr[i]/we[i];
          }
          for(i=0;i<nu;i++)
          {
              for(j=i+1;j<nu;j++)
              {
                  if(ra[i]<ra[j])
                  {
                      temp=ra[j];
                      ra[j]=ra[i];
                      ra[i]=temp;

                      temp=we[j];
                      we[j]=we[i];
                      we[i]=temp;

                      temp=pr[j];
                      pr[j]=pr[i];
                      pr[i]=temp;
                  }
              }
          }
          knapsack(nu,we,pr,c);
}

