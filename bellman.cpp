typedef ll Weight;
struct Edge {
  ll src, dst;
  Weight weight;
  Edge(ll src, ll dst, Weight weight) : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
             e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool shortestPath(const Graph g, ll s, vector<Weight> &dist, vector<ll> &prev) {
  ll n = g.size();
  dist.assign(n, INF + INF);
  dist[s] = 0;
  prev.assign(n, -2);
  bool negative_cycle = false;
  REP(k, n) REP(i, n) AUTO(e, g[i]) {
    if (dist[e.dst] > dist[e.src] + e.weight) {
      dist[e.dst] = dist[e.src] + e.weight;
      prev[e.dst] = e.src;
      if (k == n - 1) {
        dist[e.dst] = -INF;
        negative_cycle = true;
      }
    }
  }
  return !negative_cycle;
}
vector<ll> buildPath(const vector<ll> &prev, ll t) {
  vector<ll> path;
  for (ll u = t; u >= 0; u = prev[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}
