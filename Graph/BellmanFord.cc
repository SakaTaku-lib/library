#include<bits/stdc++.h>
using namespace std;
const int NIL = -1;
const long long INF = 1e17;
struct BellmanFord {
   struct vertex {int id; int p; long long d;};
   struct edge {        
      int EndPoint; long long weight;
      edge(int EndPoint, long long weight):
         EndPoint(EndPoint),weight(weight){}
   };
   struct Graph {
      vector<vertex> V; vector<vector<edge>> E;
      Graph(int n=0):V(n),E(n){};
   };
   Graph G; int s;
   BellmanFord(int n, int s):G(n),s(s){
      init();
   }
   void init(){
      for (int i = 0; i < G.V.size(); i++){
         G.V[i].id = i;
         G.V[i].p = NIL;
         G.V[i].d = INF;
      }
      G.V[s].d = 0;
   }
   void add(int v, int w, long long weight){
      G.E[v].push_back(edge(w, weight));
   }
   void Relax(vertex u, vertex &v, long long w){
      if (u.d == INF || w == INF)return;
      if (v.d > u.d + w){
         v.d = u.d + w;
         v.p = u.id;
      }
   }
   bool solve() {
      for (int i = 0; i < G.V.size()-1; i++)
         for (int j = 0; j < G.E.size(); j++)
            for (int k = 0; k < G.E[j].size(); k++)
               Relax(G.V[j], G.V[G.E[j][k].EndPoint], G.E[j][k].weight);
      for (int i = 0; i < G.E.size(); i++)
         for (int j = 0; j < G.E[i].size(); j++){
            if (G.V[i].d == INF)continue;
            if (G.V[G.E[i][j].EndPoint].d > G.V[i].d + G.E[i][j].weight)
               return false;
         }
      return true;
   }
   vertex Min(){
      long long dist = INF;
      vertex v;
      for (auto &&i : G.V){
         if (i.d < dist)
            v = i;
      }
      return v;
   }
   void PrintPath(vertex v) {
      if (v.id == s)cout << s << " ";
      else if (v.p == NIL)cout << -1 << endl;
      else {
         PrintPath (G.V[v.p]);
         cout << v.id << " ";
      }
   }
};
/*main関数*/
//BellmanFord bf(n,s)、
//for(|E|) bf.add(v,w,weight)
//if bf.solve() bf.PrintPath()
//else -inf
