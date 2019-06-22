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

Weight minimumCut(const Graph &g) {
  ll n = g.size();
  vector<vector<Weight>> h(n, vector<Weight>(n, 0)); // make adj. matrix
  REP(u, n) AUTO(e, g[u]) h[e.src][e.dst] += e.weight;
  vector<ll> V(n);
  REP(u, n) V[u] = u;

  Weight cut = llINF;
  for (ll m = n; m > 1; m--) {
    vector<Weight> ws(m, 0);
    ll u, v;
    Weight w;
    REP(k, m) {
      u = v;
      v = max_element(ws.begin(), ws.end()) - ws.begin();
      w = ws[v];
      ws[v] = -1;
      REP(i, m) if (ws[i] >= 0) ws[i] += h[V[v]][V[i]];
    }
    REP(i, m) {
      h[V[i]][V[u]] += h[V[i]][V[v]];
      h[V[u]][V[i]] += h[V[v]][V[i]];
    }
    V.erase(V.begin() + v);
    cut = min(cut, w);
  }
  return cut;
}
