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

void shortestPath(const Graph &g, ll s, vector<Weight> &dist,
                  vector<ll> &prev) {
  ll n = g.size();
  dist.assign(n, llINF);
  dist[s] = 0;
  prev.assign(n, -1);
  deque<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push_front(Edge(-2, s, 0)); !Q.empty();) {
    Edge &e = Q.front();
    Q.pop_front();
    if (prev[e.dst] != -1)
      continue;
    prev[e.dst] = e.src;
    AUTO(f, g[e.dst]) {
      if (dist[f.dst] > e.weight + f.weight) {
        dist[f.dst] = e.weight + f.weight;
        if (f.weight > 0)
          Q.push_back(Edge(f.src, f.dst, e.weight + f.weight));
        else
          Q.push_front(Edge(f.src, f.dst, e.weight + f.weight));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll K;
  cin >> K;
  Graph G(K, Edges());
  vector<ll> dist(K, 0);
  vector<ll> prev(K, 0);
  REP(i, K) {
    G[i].push_back(Edge(i, (i + 1LL) % K, 1LL));
    if (i != 0)
      G[i].push_back(Edge(i, (i * 10LL) % K, 0LL));
  }

  shortestPath(G, 1, dist, prev);
  cout << dist[0] + 1 << endl;

  return 0;
}
