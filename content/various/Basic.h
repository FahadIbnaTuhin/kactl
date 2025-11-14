/**
 * Author: Simon Lindholm
 * Date: 2015-09-12
 * License: CC0
 * Source: me
 * Description: Hi
 * Status: tested
 */
#pragma once

// checker.sh
for ((i = 1; ; ++i)); do
    echo $i
    ./gen $i.exe > in.txt
    diff -w <(./z.exe < in.txt) <(./bruteForce.exe < in.txt) || break
done
// gen.cpp
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define endl '\n'
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
// inline double gen_random(double l, double r) {  // for real number generation
//     return uniform_real_distribution<double>(l, r)(rng);
// }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("in.txt", "w", stdout);
    ll t = gen_random(1, 1);
    cout << t << '\n';
    for (ll tc = 1; tc <= t; tc++) {
        ll n = gen_random(1, 8);
        // cout << n << endl;
        for (ll i = 0; i < n; i++) cout << gen_random(1, 10) << ' ';
        cout << endl;
    }
}
// in.txt
// bruteForce.cpp
