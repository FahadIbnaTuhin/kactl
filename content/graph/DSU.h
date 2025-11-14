/**
 * Author: Simon Lindholm
 * Date: 2015-02-23
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates shortest paths from $s$ in a graph that might have negative edge weights.
 * Time: O(VE)
 * Status: Tested on kattis:shortestpath3
 */
#pragma once

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
