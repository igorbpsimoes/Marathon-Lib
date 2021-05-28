#include <bits/stdc++.h>
using namespace std;

/* 
**********BFS***********
void bfs(int source) {
    queue<int> next;
    next.push(source);
    dist[source] = 0;

    while(!next.empty()) {
        auto u = next.front(); next.pop();

        for(int v: adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                next.push(v);
            }
        }
    }
}

***********DFS*************
bool vis[MAXN]
void dfs(int u) {
    vis[u] = true;
    for(auto v: adj[u]) {
        if(vis[v]) continue;

        dfs(v);
    }
}

**********CYCLE************
vector<vector<int>> adj;
vector<bool> vis;
vector<int> cycle;

bool findCycle(int u, int prevPos) {
  vis[u] = true;
  for(int v: adj[u]) {
    if(prevPos == v) continue;
    if(vis[v]) {
      cycle.pb(v);
      return true;
    }
    if(findCycle(v, u)) return true;
  }
  return false;;
}

bool getCycle(int u, int prevPos) {
  vis[u] = true;
  for(int v: adj[u]) {
    if(prevPos == v) continue;
    if(vis[v]) return true;
    if(getCycle(v, u)) {
      cycle.pb(v);
      return true;
    }
  }
  return false;
}

************TOPOSORT**************
void toposort(int source) {
    vector<int> topoOrder;
    priority_queue<int, vector<int>> next;
    next.push(source);

    for(int u = 0; u < n; ++u) {
        if(indegree[u] == 0) next.push(u);
    }

    while(!next.empty()) {
        auto u = next.top(); next.pop();
        topoOrder.pb(u);
        for(int v: adj[u]) {
            if(--indregree[v] == 0) {
                next.push(v);
            }
        }
    }
}

***********BICOLORABILITY***********
int color[MAXN];

void dfs(int u) {
    for(int v: adj[u]) {
        if(color[v] != -1) continue;
        color[v] = 1 - color[u];
        dfs(v);
    }
}

int main() {
    memset(color, -1, sizeof color);

    for(int u = 0; u < n; ++u) {
        if(color[u] == -1) {
            color[u] = 0;
            dfs(u);
        }
    }
    // check if possible
    bool possible = true;
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            possible = possible && color[u] != color[v];
        }
    }
    return 0;
}
*/