#include <bits/stdc++.h>
#define MAX_N 20001
#define ll long int
using namespace std;
int n,m;
struct Node{
vector <int>adj;
vector<int>rev_adj;

};
Node g[MAX_N];
stack<int>s;
bool visited[MAX_N];
int numcomponents=0;
void dfs1(int x)
{
    visited[x]=true;
    for(int i=0;i<g[x].adj.size();i++)
    {
        if(!visited[g[x].adj[i]])dfs1(g[x].adj[i]);
    }
    s.push(x);
}
void dfs2(int x)
{
    printf("%d ",x);
    visited[x]=true;
    for(int i=0;i<g[x].rev_adj.size();i++){
             if(!visited[g[x].rev_adj[i]])dfs2(g[x].rev_adj[i]);
}
}
void kosaraju()
{
     for(int i=1;i<=n;i++)
    visited[i]=false;
    for(int i=1;i<=n;i++)
    if(!visited[i])dfs1(i);

     for(int i=1;i<=n;i++)
    visited[i]=false;
    while(!s.empty())
    {
        int v=s.top();
        s.pop();
        if(!visited[v])
        {
            printf("components %d: ",numcomponents);
            dfs2(v);
            numcomponents++;

        }
        printf("\n");
    }
}
int main()
{
    cin>>n>>m;
    int a,b;
    while(m--)
    {
        cin>>a>>b;
        g[a].adj.push_back(b);
         g[b].rev_adj.push_back(a);
    }
    kosaraju();
    printf("total number of components: %d\n",numcomponents);
}
/*
4 4
1 3
3 2
2 1
2 4
*/
