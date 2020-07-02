#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct WeightedGraph
{
   int n; //頂点は[0:n)
   WeightedGraph(int n):n(n){}
   struct Edge {
      int ep;  //ep:EndPoint
      ll  w;   //w:Weight
      Edge(int ep, ll w):ep(ep),w(w){}
   };
   vector<vector<Edge>> E;
   void add(int v, int w, ll weight){
      E[v].push_back(Edge(w, weight));
   }
};

struct Dijkstra
{
   int s;
   WeightedGraph wg;
   vector<ll> d;
   Dijkstra(WeightedGraph wg, int s=0):wg(wg),s(s){
      d = vector<ll>(wg.n);
   };

};

void dijkstra(int x){
    int minv;
    int d[MAX], color[MAX];
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        color[i] = WHITE;
    }
    d[x] = 0;
    color[x] = GRAY;
    while (true)
    {
        minv = INF;
        int u = -1;
        for (int i = 0; i < n; i++){
            if (minv > d[i] && color[i] != BLACK){
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++)
            if (color[v] != BLACK && M[u][v] != INF)
                if (d[v] > d[u] + M[u][v])
                {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
    }
    if (d[0] == INF)
        {
            cout << "INF";
        }
        else
        {
            cout << d[0];
        }
    for (int i = 1; i < n; i++)
    {
        if (d[i] == INF)
        {
            cout << " INF";
        }
        else
        {
            cout << " " << d[i];
        }
        
    }
}