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
