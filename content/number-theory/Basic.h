/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */
#pragma once

const ll mx = 1e8+123;
bitset<mx> isPrime;
vector<ll> primes; 
void primeGen(ll n) {
    for (ll i = 3; i <= n; i += 2) isPrime[i] = 1;
    for (ll i = 3, sq = sqrt(n); i <= sq; i += 2) {
        if(isPrime[i]) {
            for (ll j = i*i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    isPrime[2] = 1;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
} // O(N)
vector<ll> primeFactors(ll n) {
    vector<ll> factors; 
    for (auto p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) {
            while (n % p == 0) {
                factors.push_back(p);
                n /= p;
            }
        }
    }
    if (n > 1) factors.push_back(n); 
    return factors;
} // O(sqrt(n))
ll SOD( ll n ) { 
    ll sod = 1;
    for ( auto p : primes ) {
        if( 1LL * p * p > n ) break;
        if( n % p == 0 ) {
            ll sum = 1; 
            ll a = 1; 
 
            while ( n % p == 0 ) { 
                a *= p;
                sum += a; 
                n /= p;
            }
            sod *= sum;
        }
    }
    if(n > 1) sod *= (n + 1);
    return sod;
} // O(sqrt(n))
ll PHI(ll n) {
    ll phi = n;
    for (auto p : primes) { 
        if (1LL * p * p > n) break; 
        if (n % p == 0) {
            while (n % p == 0) {n /= p;}
            phi /= p;
            phi *= (p - 1);
        }
    } 
    if (n > 1) { 
        phi /= n;
        phi *= (n - 1);
    }
    return phi;
}
const ll MX = 5e6+123; // Harmonic PHI
unsigned long long arrPHI[MX];
void prePHI() {
    for (ll i = 1; i < MX; i++) arrPHI[i] = i;
    for (auto p : primes) {
        for (ll j = p; j < MX; j += p) {
            arrPHI[j] /= p;
            arrPHI[j] *= (p - 1);   
        }
    } // O(nloglogn)
}
vector<vector<ll>> getDivisors; 
void precompute_divisors(ll n) {
    getDivisors.assign(n + 1, {});
    for (ll i = 1; i <= n; ++i) { 
        for (ll j = i; j <= n; j += i) {
            getDivisors[j].push_back(i);
        }
    }
}

