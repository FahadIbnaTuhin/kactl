/**
 * Author: Simon Lindholm
 * Date: 2015-02-23
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates shortest paths from $s$ in a graph that might have negative edge weights.
 * Unreachable nodes get dist = inf; nodes reachable through negative-weight cycles get dist = -inf.
 * Assumes $V^2 \max |w_i| < \tilde{} 2^{63}$.
 * Time: O(VE)
 * Status: Tested on kattis:shortestpath3
 */
#pragma once

// DFS 
const ll mx = 2e5+123;
vector<vector<ll>> adj(mx);
vector<bool> vis(mx);
vector<ll> parent(mx);
bool cycleExist;
void dfs(ll u) {
    vis[u] = 1;
    // parent[u] = -1; 
    for (auto &v : adj[u]) {
        if (v == parent[u]) continue;
        if (!vis[v]) {
            vis[v] = 1;
            parent[v] = u;
            dfsP(v);
        } // else {
        //     cout << parent[u] << ' ' << u << ' ' << v << endl;
        //     cout << "CYCLE FOUND" << endl;
        // }
    }    
}
// BFS
void bfs(ll src) { 
    queue<ll> q;
    q.push(src);
    parent[src] = -1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll &v : adj[u]) {
            if (v == parent[u]) continue;
            if (!vis[v]) {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            } // else {
            //     cout << parent[u] << ' ' << u << ' ' << v << endl;
            //     cout << "CYCLE FOUND" << endl;
            // }
        }
    }
}
// Dijkstra
const ll mx = 2e5+123;
vector<vector<pair<ll, ll>>> adj(mx);
vector<ll> dist(mx), parent(mx);

void dijkstra(ll src, ll n) {
    dist.assign(n + 1, inf);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    parent[src] = -1;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;

        for (const auto &[v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}
// BellmanFord
const ll mx = 1123;
vector<tuple<ll, ll, ll>> edges;
ll dist[mx], par[mx];

bool bellmanFord(int src, ll n) {
    for (ll i = 0; i <= n; i++) { // <= n can handle both 0-based and 1-based
        dist[i] = inf;
        par[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool relaxed = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] < inf && dist[u] + w < dist[v]) {
                dist[v] = max(-inf, dist[u] + w); // prevent underflow
                par[v] = u;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }

    // Negative cycle check
    for (auto [u, v, w] : edges) {
        if (dist[u] < inf && dist[u] + w < dist[v]) {
            return true; // cycle exists
        }
    }
    return false;
}
// Floyd
const ll mx = 500;
ll adj[mx][mx], dist[mx][mx];
ll n, m; 

void floydWarshall() { // No need to clear the dist 
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = inf;
        }
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
// DSU
class dsu { 
public: 
    vector<ll> parent, size, rank; 
    dsu(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    } 
    ll findPar(ll u) {
        if (parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);  
    } 
    void unionSize(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return; 
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv]; 
    } 
    void unionRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v); 
        if (pu == pv) return;  
        if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            ++rank[pu];
        } else {
            if (rank[pu] < rank[pv]) swap(pu, pv);
            parent[pv] = pu;
        }
    }
};
// Topological Sort
const ll mx = 105;
ll indeg[mx];
vector<ll> g[mx]; // g[i] means from i where can go
bool vis[mx];

int main() {
    // Starting e tader ke nite parbo, jader indegree 0
    ll n, m; cin >> n >> m;
    while (m--) {
        ll u, v; cin >> u >> v;
        ++indeg[v];
        g[u].push_back(v);
    }
    vector<ll> z;
    for (ll i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            z.push_back(i);
            vis[i] = true;
        }
    }
    vector<ll> ans; 
    while (sz(ans) < n) {
        if (z.empty()) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ll cur = z.back(); // okay to take any element from z
        z.pop_back();
        ans.push_back(cur);
        vis[cur] = 1;
        for (auto v : g[cur]) {
            --indeg[v];
            if (!vis[v] && indeg[v] == 0) {
                z.push_back(v);
                vis[v] = true;
            }
        }
    }
    for (ll &i : ans) cout << i << ' ';
    cout << endl;
}
