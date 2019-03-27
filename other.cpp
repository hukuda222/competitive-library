auto c = [](Pair l, Pair r) { return l.second < r.second; };
auto c2 = [](Pair l, Pair r) { return l.second > r.second; };

priority_queue<Pair, vector<Pair>, decltype(c)> S(c);

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}

ll factorial(ll n) {
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
ll P(ll n, ll m) {
  ll ans = 1;
  for (ll i = m + 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}

ll MODPOW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = MODPOW(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * MODPOW(n, m - 1)) % MOD;
  }
}

ll C(ll n, ll m) { return (P(n, n - m) * MODPOW(factorial(m), MOD - 2)) % MOD; }

ll GCD(ll a, ll b) {
  if (b == 0)
    return a;
  return GCD(b, a % b);
}

// fはfactrial(事前に計算しておく)
ll nCr(ll n, ll r) {
  if (n < r) {
    return 0LL;
  }

  if (r > n / 2LL) {
    r = n - r;
  }

  ll res = (f[n] * MODPOW(f[n - r], MOD - 2LL)) % MOD;
  res = (res * MODPOW(f[r], MOD - 2LL)) % MOD;

  return res;
}

//エラトステネスの篩(O(NloglogN))
vector<bool> prime(1e5 + 1, true);
prime[1] = false;
FOR(i, 2, (ll)pow(1e5, 0.5) + 1) {
  if (!prime[i])
    continue;
  for (ll j = 2; j * i < 1e5 + 1; j++) {
    prime[i * j] = false;
  }
}
