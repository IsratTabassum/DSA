#include <bits/stdc++.h>
using namespace std;
const int V=6;
void printMST(int parent[V],int graph[V][V])
{
    cout<<"Vertex\tParent\tWeight\n";
    for(int i=0; i<V; i++)
    {
        if(parent[i]==-1)cout<<"new component"<<endl;
        cout<<i<<"\t"<<parent[i]<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

int minw(int weight[V],bool visited[V])
{
    int Min=INT_MAX,min_inx;
    for(int v=0; v<V; v++)
    {
        if(visited[v]==false && weight[v]<Min)
        {
            Min=weight[v];
            min_inx=v;
        }
    }
    return min_inx;
}

void primMST(int graph[V][V],int v,int weight[],int parent[],bool visited[])
{
    weight[v]=0;
    parent[v]=-1;
    for(int cnt=0; cnt<V-1; cnt++)
    {
        int u=minw(weight,visited);
        visited[u]=true;
        for(int v=0; v<V; v++)
            if(graph[u][v]&&visited[v]==false&&graph[u][v]<weight[v])
            {
                parent[v]=u;
                weight[v]=graph[u][v];
            }
    }
}
int main()
{
    int parent[V],weight[V];
    bool visited[V];
    for (int i=0; i<V; i++)
    {
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    int graph[V][V]= {{0,2,0,0,0,8},
        {2,0,0,0,0,6},
        {0,0,0,1,3,0},
        {0,0,1,0,9,0},
        {0,0,3,9,0,0},
        {8,6,0,0,0,0}
    };
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            primMST(graph,i,weight,parent,visited);
    }
     printMST(parent,graph);
}
