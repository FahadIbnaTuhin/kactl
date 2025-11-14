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
