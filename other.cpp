// pllは基本的にfirstが優先されるのでsecondを優先するときはこっちを使う

auto c = [](pll l, pll r) { return l.second < r.second; };
auto c2 = [](pll l, pll r) { return l.second > r.second; };
priority_queue<pll, vector<pll>, decltype(c)> S(c);

//約数を全て列挙
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
//素因数分解する
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  //引数にretを入れてn回使う時用
  if (n != 1 && ret.find(n) == ret.end())
    ret[n] = 1;
  else if (n != 1)
    ret[n] += 1;
  return ret;
}

//階乗
ll factorial(ll n) {
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
// 並べるやつ
ll P(ll n, ll m) {
  ll ans = 1;
  for (ll i = m + 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
// MODつきPOW
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

// コンビネーション(コンビネーションをたくさん計算する時は下のを使う)
ll C(ll n, ll m) { return (P(n, n - m) * MODPOW(factorial(m), MOD - 2)) % MOD; }

ll H(ll n, ll m) { return C(n + m - 1, m); }

// a=a'c,b=b'cなので、LCM(a,b)=a*b/GCD(a,b)
ll GCD(ll a, ll b) {
  if (b == 0)
    return a;
  return GCD(b, a % b);
}

// fはfactrial(事前に計算しておく)
ll nCr(ll n, ll r) {
  if (n < r)
    return 0LL;
  if (r > n / 2LL)
    r = n - r;
  ll res = (f[n] * MODPOW(f[n - r], MOD - 2LL)) % MOD;
  res = (res * MODPOW(f[r], MOD - 2LL)) % MOD;
  return res;
}
ll nHr(ll n, ll m) { return nCr(n + m - 1, m); }

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

//最後の一個がdelimの場合は無視する
vector<string> split(const string &s, char delim) {
  vector<string> elems;
  string item;
  for (char ch : s) {
    if (ch == delim) {
      if (!item.empty())
        elems.push_back(item);
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty())
    elems.push_back(item);
  return elems;
}

// LIS、最大増加部分列を求める
// Dが考えたい数列
// https://qiita.com/walk_to_work/items/378fd4d46d2067237c68
REP(i, N) { *lower_bound(DP.begin(), DP.end(), D[i]) = D[i]; }
cout << lower_bound(DP.begin(), DP.end(), llINF) - DP.begin() << endl;
