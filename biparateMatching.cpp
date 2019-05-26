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

bool augment(const Graph &g, ll u, vector<ll> &matchTo, vector<bool> &visited) {
  if (u < 0)
    return true;
  AUTO(e, g[u]) if (!visited[e.dst]) {
    visited[e.dst] = true;
    if (augment(g, matchTo[e.dst], matchTo, visited)) {
      matchTo[e.src] = e.dst;
      matchTo[e.dst] = e.src;
      return true;
    }
  }
  return false;
}
ll bipartiteMatching(const Graph &g, ll L, Edges &matching) {
  const ll n = g.size();
  vector<ll> matchTo(n, -1);
  ll match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited))
      ++match;
  }
  REP(u, L)
  if (matchTo[u] >= 0)
    matching.push_back(Edge(u, matchTo[u], 1));
  return match;
}
