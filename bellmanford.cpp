#include<bits/stdc++.h>
using namespace std;
#define N 4
const int INF=1e9;



int main()
{
    int ve,e;
    cin>>ve>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});}
        int s;
        cin>>s;
       vector<int>dist(ve,INF);
        dist[s]=0;
        for(int i=0;i<ve-1;i++)
        {
            for(auto e1: edges)
            {
                int u=e1[0];
                int v=e1[1];
                int w=e1[2];
                dist[v]=min(dist[v],w+dist[u]);
            }
        }
        for(auto i:dist)cout<<i<<" ";
        cout<<endl;

}
