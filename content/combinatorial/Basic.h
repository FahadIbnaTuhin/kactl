/**
 * Author: Mattias de Zalenski, Fredrik Niemelä, Per Austrin, Simon Lindholm
 * Date: 2002-09-26
 * Source: Max Bennedich
 * Description: Computes $\displaystyle \binom{k_1 + \dots + k_n}{k_1, k_2, \dots, k_n} = \frac{(\sum k_i)!}{k_1!k_2!...k_n!}$.
 * Status: Tested on kattis:lexicography
 */
#pragma once

// exponent
ll binPower(ll base, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * base;
        }
        base = base * base;
        power >>= 1;
    }
    return res;
}
ll binPowerMod(ll base, ll power, ll m) {
    ll res = 1;
    base %= m;
    while (power > 0) {
        if (power & 1) {
            res = res * base % m;
        }
        base = base * base % m;
        power >>= 1;
    }
    return res;
}
ll binModInv(ll base, ll modd) {
    return binPowerMod(base, modd - 2, modd);
}
// ncr
const ll N = 1e5;
ll fact[N + 1];
ll invFact[N + 1];
void precomputeFact() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod; 
    }
    invFact[N] = modInverse(fact[N]);
    for (ll i = N - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
} // O(N + logmod) = O(N)
ll ncr(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    ll numerator = fact[n];
    ll invDenominator = (invFact[r] * invFact[n - r]) % mod; // 1 / (fact[r] * fact[n - r])
    ll ans = (numerator * invDenominator) % mod;
    return ans;
} // TC: O(1)
