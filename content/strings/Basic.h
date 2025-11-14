/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
#pragma once

// --- Hashing Setup ---
const ll P = 31;
const ll HASH_MOD = 1e9 + 7;
const ll MAX_LEN = 1e6 + 123;

vector<ll> p_pow(MAX_LEN);       // Powers of P
vector<ll> inv_p_pow(MAX_LEN);   // Modular inverses of powers of P

// Fast modular exponentiation
inline ll modPowH(ll b, ll p, ll m) { ll r = 1; while (p) { if (p & 1) r = (r * b) % m; b = (b * b) % m; p >>= 1;} return r; }
inline ll modInverseH(ll a, ll m) {return modPowH(a, m - 2, m);}

// Precompute powers and inverse powers
void precomputeHash() {
    p_pow[0] = 1;
    for (ll i = 1; i < MAX_LEN; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % HASH_MOD;
    }

    inv_p_pow[MAX_LEN - 1] = modInverseH(p_pow[MAX_LEN - 1], HASH_MOD);
    for (ll i = MAX_LEN - 2; i >= 0; i--) {
        inv_p_pow[i] = (inv_p_pow[i + 1] * P) % HASH_MOD;
    }
}

// Computes hash of full string
ll compute_hash(const string& s) {
    ll hash_value = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1ll) * p_pow[i]) % HASH_MOD;
    }
    return hash_value;
}

// Prefix hashes: h[i] = hash of s[0..i-1]
vector<ll> compute_prefix_hashes(const string& s) {
    ll n = s.size();
    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % HASH_MOD;
    }
    return h;
}

// Get hash of s[l..r] (0-indexed) using precomputed prefix hashes
ll get_substring_hash(const vector<ll>& h, ll l, ll r) {
    ll raw_hash = (h[r + 1] - h[l] + HASH_MOD) % HASH_MOD;
    return (raw_hash * inv_p_pow[l]) % HASH_MOD;
}
vector<vector<ll>> group_identical_strings(vector<string> const& s) { // O(nm + nlogn) [m = highest len of any string]
    ll n = s.size();
    vector<pair<ll, ll>> hashes(n);
    for (ll i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end()); // O(nlogn)

    vector<vector<ll>> groups;
    for (ll i = 0; i < n; i++) { // O(n)
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
} 
ll count_unique_substrings(string const& s) { // TC: O(n^2)
    ll n = s.size();

    const ll p = 31;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (ll i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    ll cnt = 0;
    for (ll l = 1; l <= n; l++) {
        unordered_set<ll> hs;
        for (ll i = 0; i <= n - l; i++) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
} 
vector<ll> rabin_karp(string const& pattern, string const& text) { // O(|s| + |t|)
    const ll p = 31; 
    const ll m = 1e9 + 9;
    ll S = pattern.size(), T = text.size();

    vector<ll> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (ll i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(T + 1, 0); 
    for (ll i = 0; i < T; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m; 
    ll h_s = 0; 
    for (ll i = 0; i < S; i++) 
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<ll> occurrences;
    for (ll i = 0; i + S - 1 < T; i++) {
        ll cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
// ----------------------

// --- Hashing Setup ---
const ll P1 = 31, P2 = 53;
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const ll MAX_LEN = 1e6 + 123;

vector<ll> p_pow1(MAX_LEN), p_pow2(MAX_LEN);
vector<ll> inv_p_pow1(MAX_LEN), inv_p_pow2(MAX_LEN);

inline ll modPowH(ll b, ll p, ll m) { ll r = 1; while (p) { if (p & 1) r = (r * b) % m; b = (b * b) % m; p >>= 1;} return r; }
inline ll modInverseH(ll a, ll m) {return modPowH(a, m - 2, m);}

void precomputeHash() {
    p_pow1[0] = p_pow2[0] = 1;
    for (ll i = 1; i < MAX_LEN; i++) {
        p_pow1[i] = (p_pow1[i - 1] * P1) % MOD1;
        p_pow2[i] = (p_pow2[i - 1] * P2) % MOD2;
    }

    inv_p_pow1[MAX_LEN - 1] = modInverseH(p_pow1[MAX_LEN - 1], MOD1);
    inv_p_pow2[MAX_LEN - 1] = modInverseH(p_pow2[MAX_LEN - 1], MOD2);
    for (ll i = MAX_LEN - 2; i >= 0; i--) {
        inv_p_pow1[i] = (inv_p_pow1[i + 1] * P1) % MOD1;
        inv_p_pow2[i] = (inv_p_pow2[i + 1] * P2) % MOD2;
    }
}
pair<ll, ll> compute_hash(const string& s) {
    ll h1 = 0, h2 = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
        ll val = s[i] - 'a' + 1;
        h1 = (h1 + val * p_pow1[i]) % MOD1;
        h2 = (h2 + val * p_pow2[i]) % MOD2;
    }
    return {h1, h2};
}
vector<pair<ll, ll>> compute_prefix_hashes(const string& s) {
    ll n = s.size();
    vector<pair<ll, ll>> h(n + 1, {0, 0});
    for (ll i = 0; i < n; i++) {
        ll val = s[i] - 'a' + 1;
        h[i + 1].first  = (h[i].first + val * p_pow1[i]) % MOD1;
        h[i + 1].second = (h[i].second + val * p_pow2[i]) % MOD2;
    }
    return h;
}
pair<ll, ll> get_substring_hash(const vector<pair<ll, ll>>& h, ll l, ll r) {
    ll raw1 = (h[r + 1].first - h[l].first + MOD1) % MOD1;
    ll raw2 = (h[r + 1].second - h[l].second + MOD2) % MOD2;
    ll hash1 = (raw1 * inv_p_pow1[l]) % MOD1;
    ll hash2 = (raw2 * inv_p_pow2[l]) % MOD2;
    return {hash1, hash2};
}
vector<vector<ll>> group_identical_strings(const vector<string>& s) {
    ll n = s.size();
    vector<pair<pair<ll, ll>, ll>> hashes(n);
    for (ll i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<ll>> groups;
    for (ll i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i - 1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
ll count_unique_substrings(const string& s) {
    ll n = s.size();
    set<pair<ll, ll>> seen;

    for (ll i = 0; i < n; i++) {
        ll h1 = 0, h2 = 0;
        for (ll j = i; j < n; j++) {
            ll val = s[j] - 'a' + 1;
            h1 = (h1 * P1 + val) % MOD1;
            h2 = (h2 * P2 + val) % MOD2;
            seen.insert({h1, h2});
        }
    }
    return seen.size();
}
vector<ll> rabin_karp(const string& pattern, const string& text) {
    ll S = pattern.size(), T = text.size();

    vector<ll> h1(T + 1, 0), h2(T + 1, 0);
    for (ll i = 0; i < T; i++) {
        h1[i + 1] = (h1[i] + (text[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        h2[i + 1] = (h2[i] + (text[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }

    ll hp1 = 0, hp2 = 0;
    for (ll i = 0; i < S; i++) {
        hp1 = (hp1 + (pattern[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        hp2 = (hp2 + (pattern[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }

    vector<ll> occurrences;
    for (ll i = 0; i + S <= T; i++) {
        ll cur1 = (h1[i + S] - h1[i] + MOD1) % MOD1;
        ll cur2 = (h2[i + S] - h2[i] + MOD2) % MOD2;

        ll h_sub1 = (cur1 * inv_p_pow1[i]) % MOD1;
        ll h_sub2 = (cur2 * inv_p_pow2[i]) % MOD2;

        if (h_sub1 == hp1 && h_sub2 == hp2)
            occurrences.push_back(i);
    }
    return occurrences;
}
struct pair_hash { // for set, unordered_set
    size_t operator()(const pair<ll, ll>& p) const {
        auto h1 = hash<ll>{}(p.first);
        auto h2 = hash<ll>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
// ----------------------
