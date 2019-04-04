#include <algorithm>
#include <bitset>
#include <cmath>
ll P[52][52] = {};
string A[52];
ll H, W;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  REP(i, 50) REP(j, 50) P[i][j] = llINF;
  cin >> H >> W;
  REP(i, H) cin >> A[i];
  ll ans = 0;
  REP(i, H) REP(j, W) {
    if (A[i][j] == '.')
      ans++;
  }

  queue<pll> que;
  que.push(make_pair(0, 0));
  P[0][0] = 1;
  while (!que.empty()) {
    auto pos = que.front();
    que.pop();
    ll x = pos.first;
    ll y = pos.second;
    if (x == W - 1 && y == H - 1) {
      break;
    }
    REP(i, 4) {
      if (x + dx[i] < W && x + dx[i] > -1 && y + dy[i] < H && y + dy[i] > -1 &&
          A[y + dy[i]][x + dx[i]] == '.' && P[y + dy[i]][x + dx[i]] == llINF) {
        P[y + dy[i]][x + dx[i]] = P[y][x] + 1;
        que.push(make_pair(x + dx[i], y + dy[i]));
      }
    }
  }

  if (P[H - 1][W - 1] == llINF)
    cout << -1 << endl;
  else
    cout << ans - P[H - 1][W - 1] << endl;

  return 0;
}
