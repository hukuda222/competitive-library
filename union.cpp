#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const long long int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int INF = 1000000000000000000;

using namespace std;
using ll = long long int;
using edge = struct {
  ll to;
  ll cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end());
#define MIN(vec) *std::min_element(vec.begin(), vec.end());
#define MAXI(vec)                                                              \
  std::distance(vec.begin(), *std::max_element(vec.begin(), vec.end()));
#define MINI(vec)                                                              \
  std::distance(vec.begin(), *std::min_element(vec.begin(), vec.end()));
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define MATMUL(a, b, c)                                                        \
  REP(i, a.size())                                                             \
  REP(j, b[0].size()) REP(k, a[0].size()) c[i][j] += a[i][k] * b[k][j];
#define CLA2(a) REP(i, a.size()) REP(j, a[0].size()) a[i][j] = 0;
#define REV(T) greater<T>()

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

struct UnionFind {
  vector<ll> data;

  UnionFind(ll sz) { data.assign(sz, -1); }

  bool unite(ll x, ll y) {
    x = root(x), y = root(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  ll root(ll k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = root(data[k]));
  }

  ll size(ll k) { return (-data[root(k)]); }

  ll same(ll a, ll b) { return root(a) == root(b); }
};

int main() {
  ll N, Q;
  vector<string> A;
  cin >> N >> Q;
  auto uf = UnionFind(N);
  REP(i, Q) {
    ll p, a, b;
    cin >> p >> a >> b;
    if (p == 0)
      uf.unite(a, b);
    else {
      auto ans = uf.same(a, b) ? "Yes" : "No";
      A.push_back(ans);
    }
  }
  AUTO(a, A) cout << a << endl;

  return 0;
}
