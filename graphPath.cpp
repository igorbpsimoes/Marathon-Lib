#include <bits/stdc++.h>
using namespace std;

/*
***********DIJKSTRA*************
void dijkstra(int source) {
  for(int i = 0; i < n; i++) dist[i] = INF;
  dist[source] = 0;
  
  priority_queue<pii, vector<pii>, greater<pii>> next;
  next.emplace(0, source);

  while(!next.empty()) {
    int d = next.top().first, u = next.top().second;
    next.pop();

    if(d > dist[u]) continue;

    for(auto e: adj[u]) {
      int w = e.first, v = e.second;
      if(d + w < dist[v]) {
        //parent[v] = u;
        dist[v] = d + w;
        next.emplace(d + w, v);
      }
    }
  }
}

************CUSTOM SORT FOR STRUCT*****************
bool operator() (Node &a, Node &b) {
    if(a.cost > b.cost) return true;
    return false;
}
priority_queue<Node, vector<Node>, Node> next;


*************FLOYD***************
const int n = 5;
int graph[n][n];

void floyd() {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

**********DSU - DISJOINT SET UNION****************
void dsBuild() {
  for(int i = 0; i < n; ++i) {
    ds[i] = i;
    sz[i] = i;
  }
}

int dsFind(int i) {
  if(ds[i] != i) ds[i] = dsFind(ds[i]);
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); b = dsFind(b);
  if(sz[a] < sz[b]) swap(a, b);
  if(a != b) sz[a] += sz[b];
  ds[b] = a;
}

********************KRUSKAL**********************
struct Edge {
    int u, v, cost;
    bool operator < (Edge b) {
        return cost < b.cost;
    }
};

vector<Edge> edges(edgeQtt);
void kruskal() {
    ll total = 0;
    
    sort(all(edges));

    vector<Edge> mst;
    for(int i = 0; i < edgeQtt; ++i) {
        if(dsFind(edges[i].u) != dsFind(edges[i].v)) {
            dsUnion(edges[i].u, edges[i].v);
            mst.pb(edges[i]);
            total += edges[i].cost;
        }
    }
}

********************PRIM*********************
void prim(int source = 0) {
  for(int i = 0; i < n; ++i) dist[i] = INF;
  dist[source] = 0;

  priorqueue<pii, vector<pii>, greater<pii>> next;
  next.emplace(0, source);

  while(!next.empty()) {
    auto cur = next.top(); next.pop();
    int d = cur.f, u = cur.s;
    if(inMST[u]) continue;

    inMST[u] = true;
    for(auto e: adj[u]) {
      int v = e.first, w = e.second;
      if(!inMST[v] && w < dist[v]) {
        //parent[v] = u;
        dist[v] = w;
        next.emplace(dist[v], v);
      }
    }
  }
}

*/