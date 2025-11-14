/**
 * Author: Unknown
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left to right.
 * If there are cycles, the returned list will have size smaller than $n$ -- nodes reachable
 * from cycles will not be returned.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

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
