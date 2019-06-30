// トポロジカルソート 根に近いほど小さい値になる
// uが根
void dfs(ll u, vvl &g, vl &ans, vector<bool> &used) {
  if (used[u])
    return;
  used[u] = true;
  AUTO(i, g[u]) dfs(i, g, ans, used);
  // 帰りがけ順で追加
  ans.push_back(u);
}

vl tsort(vvl &g, ll N) {
  vector<bool> used(N, false);
  vl ans;
  REP(i, N) dfs(i, g, ans, used);
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ll N, M;
  cin >> N >> M;
  vvl g(N);
  vvl parent(N);

  REP(i, N - 1 + M) {
    ll a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    parent[b - 1].push_back(a - 1);
  }

  vl ans = tsort(g, N);
  vl i2ans(N);
  REP(i, N) i2ans[ans[i]] = i;

  REP(i, N) {
    if (parent[i].size() == 0)
      cout << 0 << endl;
    else {
      ll m = -1;
      ll mi = -1;
      AUTO(j, parent[i]) {
        if (i2ans[j] > m) {
          m = i2ans[j];
          mi = j;
        }
      }
      cout << mi + 1 << endl;
    }
  }

  // REP(i, ans.size()) cout << ans[i] << endl;
  return 0;
}
