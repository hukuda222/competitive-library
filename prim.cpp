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

pair<Weight, Edges> Prim(const Graph &g, ll r = 0) {
  ll n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push(Edge(-1, r, 0));
  while (!Q.empty()) {
    Edge e = Q.top();
    Q.pop();
    if (visited[e.dst])
      continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    AUTO(f, g[e.dst]) if (!visited[f.dst]) Q.push(f);
  }
  return pair<Weight, Edges>(total, T);
}
