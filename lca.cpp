typedef ll Weight;
struct Edge {
  ll src, dst;
  Weight weight;
  Edge(ll src, ll dst, Weight weight) : src(src), dst(dst), weight(weight) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

// GはGraphかvvlを想定している

template <typename G> struct DoublingLowestCommonAncestor {
  const ll LOG;
  vector<ll> dep; // dep[j]=hは、j番目の要素の深さはh
  const G &g;
  // table[k][i]=pは、iの2^k回前親を辿ったのがp
  vector<vector<ll>> table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(30) {
    table.assign(LOG, vector<ll>(g.size(), -1));
  }

  void dfs(ll idx, ll par, ll d) {
    table[0][idx] = par;
    dep[idx] = d;
    for (auto &to : g[idx]) {
      if (to != par)
        dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for (ll k = 0; k + 1 < LOG; k++) {
      for (ll i = 0; i < table[k].size(); i++) {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  ll query(ll u, ll v) {
    ll inu = u, inv = v;
    if (dep[u] > dep[v])
      swap(u, v);
    for (ll i = LOG - 1; i >= 0; i--) {
      if (((dep[v] - dep[u]) >> i) & 1)
        v = table[i][v];
    }
    if (u == v)
      return u;
    for (ll i = LOG - 1; i >= 0; i--) {
      if (table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};
