#include<bits/stdc++.h>
using namespace std;

#define N 4
const int INF=1e9;
void print(int m[][N])
{
      for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
                if(m[i][j]==INF)
                cout<<"INF";
          else
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}void   floydwarshell(int graph[][N])
{
    int m[N][N],i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            m[i][j]=graph[i][j];
        }
    }
       for(k=0;k<N;k++)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(m[i][k]+m[k][j]<m[i][j])
                {
                    m[i][j]=m[i][k]+m[k][j];
                }
            }

        }
    }
    print(m);

}

int main()
{
    int graph[N][N]={{0,3,INF,5},
                      {2,0,INF,4},
                      {INF,1,0,INF},
                      {INF,INF,2,0}};

     floydwarshell(graph);

}
