#include <bits/stdc++.h>
using namespace std;
const int V=5;
void printMST(int parent[V],int graph[V][V]){
    cout<<"Vertex\tParent\tWeight\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t"<<parent[i]<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

int minw(int weight[V],bool visited[V]){
    int Min=INT_MAX,min_inx;
    for(int v=0;v<V;v++){
        if(visited[v]==false && weight[v]<Min){
            Min=weight[v];
            min_inx=v;
        }
    }
    return min_inx;
}

void primMST(int graph[V][V])
{
    int parent[V];
    int weight[V];
    bool visited[V];
    for (int i=0; i<V; i++)
    {
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    weight[0]=0;
    parent[0]=-1;
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
    printMST(parent,graph);
}
int main()
{
    int graph[V][V]= {{0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    primMST(graph);
}
