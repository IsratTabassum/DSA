#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10];
bool visited[10];
void dfs(int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
            dfs(adj[s][i]);
    }
}

void initialize()
{
    for(int i=0;i<10;i++)
    {
        visited[i]=false;
    }
}
int main()
{
    int n,e,x,y,connectedcompo;
    cin>>n;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
         adj[y].push_back(x);

    }
    initialize();
         for(int i=1; i<=n;i++)
         {
             if(visited[i]==false)
             {
                 dfs(i);
                 connectedcompo++;
                 cout<<endl;
             }

         }

    cout<<"Number of connectedcomponents:"<<connectedcompo;
    return 0;
}
/*
5 4
1 2
2 3
3 1
4 5
*/
