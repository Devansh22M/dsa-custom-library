using ll = long long;

// using binary exponentiation for fast pow

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if (b & 1) {
            res = res * a;
        }
        b >>= 1;
        a = a * a;
    }
    return res;
}

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while(b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
