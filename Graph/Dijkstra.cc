//2020-07-03 05:32:32
//writer SakaTaku
//Dijkstra法   O(|E|log|V|)
struct Edge {int to; ll cost;};
typedef pair<ll, int> P;
int V;
struct Dijkstra {
   int V;
   vector<vector<Edge>> G;
   Dijkstra(int V):G(V){}
   void add(int v, int w, int cost){
      Edge e;
      e.to = w; e.cost = cost;
      G[v].push_back(e);
   }
   ll inf = (1<<60);
   vector<ll> d;
   void solve(int s){
      priority_queue<P, vector<P>, greater<P>> pq;
      d = vector<ll>(V,inf);
      d[s] = 0;
      pq.push(P(0,s));
      while (!pq.empty()){
         P p = pq.top(); pq.pop();
         if (d[p.second] < p.first)continue;
         for (auto &&e : G[p.second]){
            if (d[e.to] > d[p.second] + e.cost){
               d[e.to] = d[p.second] + e.cost;
               pq.push(P(d[e.to], e.to));
            }
         }  
      }
   }
}; 